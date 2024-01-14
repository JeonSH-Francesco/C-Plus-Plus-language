#include "Hollow.h"
using namespace std;

int main(void) {
	Hollow* hollow = new Hollow();

	if (!hollow->CreateDummyProcess(L"calc.exe")) {
		cout << "[!] CreateDummyProcess" << endl;
		return 1;
	}

	if (!hollow->ProcessHollowing(L"C:\\Temp\\helloworld.exe")) {
		cout << "[!] ProcessHollowing" << endl;
		return 1;
	}

	delete(hollow);
	return 0;
}
