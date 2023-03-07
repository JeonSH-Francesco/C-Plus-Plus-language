#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

	string name, dept,strsid;
	int sid;

	//키보드로부터 읽기
	cout << "이름 >> ";
	getline(cin, name);

	cout << "학번 >> ";
	cin >> sid;
	getline(cin, strsid);

	cout << "학과 >> ";
	getline(cin, dept);

	//파일 열기. students.txt 파일을 열고, 출력 스트림 생성

	ofstream fout("c:\\tempC++\\student.txt");

	if (!fout) {
		cout << "c:\\tempC++\\student.txt 파일을 열 수 없다.";
		return 0;
	}

	//파일 쓰기
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	//파일 종료
	fout.close();

}

/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char name[10], dept[20];
	int sid;

	//키보드로부터 읽기
	cout << "이름 >>";
	cin >> name;

	cout << "학번 >>";
	cin >> sid;

	cout << "학과 >>";
	cin >> dept;

	//파일 열기. students.txt 파일을 열고, 출력 스트림 생성
	ofstream fout("c:\\tempC++\\student.txt",ios::app);

	if (!fout) {
		cout << "c:\\tempC++\\student.txt 파일을 열 수 없다.";
		return 0;
	}

	//파일 쓰기
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();

}
*/
