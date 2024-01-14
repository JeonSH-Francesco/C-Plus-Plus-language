#pragma once
#include <iostream>
#include <Windows.h>

EXTERN_C NTSTATUS NTAPI NtUnmapViewOfSection(HANDLE, PVOID);
EXTERN_C NTSTATUS NTAPI NtResumeThread(HANDLE, PULONG);

class Hollow
{
private:
	STARTUPINFOW si;
	PROCESS_INFORMATION pi;
public:
	Hollow();
	~Hollow();
	bool CreateDummyProcess(const wchar_t* pCommandLine);
	bool ProcessHollowing(const wchar_t* pProgramPath);
	void TerminateDummyProcess();
};
