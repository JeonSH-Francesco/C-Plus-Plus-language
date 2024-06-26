// main.cpp
#include "Hollow.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
    Hollow* hollow = new Hollow();

    cout << "Creating dummy process (calc.exe)..." << endl;
    if (!hollow->CreateDummyProcess(L"C:\\Windows\\System32\\calc.exe")) {
        PrintError("[!] CreateDummyProcess");
        return 1;
    }

    cout << "Performing process hollowing (notepad.exe)..." << endl;
    if (!hollow->ProcessHollowing(L"C:\\Windows\\System32\\notepad.exe")) {
        PrintError("[!] ProcessHollowing");
        return 1;
    }

    cout << "Process hollowing completed successfully." << endl;

    delete(hollow);
    return 0;
}
