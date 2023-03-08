#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream fin("C:\\tempC++\\words.txt");
	
	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다." << endl;
	}

	//fin.open("경로명 txt명");

	string line;

	while (!fin.eof()) {
		getline(fin, line);
		cout << line << endl;
	}


	fin.close();
}
