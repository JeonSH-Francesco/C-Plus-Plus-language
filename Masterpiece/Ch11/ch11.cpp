/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class AbstractPlayer {
	string name;
protected:
	string gbb[3];
public:
	AbstractPlayer(string name) {
		this->name = name;
		gbb[0] = "가위";
		gbb[1] = "바위";
		gbb[2] = "보";
	}
	virtual string turn() = 0;
	string getName() { return name; }
};

class Human : public AbstractPlayer {
public:
	Human(string name) : AbstractPlayer(name){ ; }
	string turn() {
		string gg;
		while (1) {
			cout << getName() << ">>";
			getline(cin, gg);
			if (gg == "가위" || gg == "바위" || gg == "보")
				return gg;
		}
	}
};

class Computer : public AbstractPlayer {
public:
	Computer() : AbstractPlayer("Computer") {
		srand((unsigned)time(0));
	}
	string turn() {
		int num = rand() % 3;
		return gbb[num];
	}
};

int main() {
	string name;

	cout << "***** 컴퓨터와 사람이 가위 바위 보 대결을 펼칩니다. *****" << endl;
	cout << "선수 이름을 입력하세요>>";
	getline(cin, name);

	Human h(name);
	Computer c;

	while (1) {
		string temp = h.turn();
		string com = c.turn();
		cout << c.getName() << ": " << com << endl;
		if (temp == com)
			cout << "the same" << endl;
		else if (temp == "바위") {
			if (com == "가위")
				cout << h.getName() << " is winner." << endl;
			else
				cout << c.getName() << " is winner." << endl;
		}
		else if (temp == "가위") {
			if (com == "보")
				cout << h.getName() << " is winner." << endl;
			else
				cout << c.getName() << " is winner." << endl;
		}
		else if (temp == "보") {
			if (com == "바위")
				cout << h.getName() << " is winner." << endl;
			else
				cout << c.getName() << " is winner." << endl;
		}
	}
}
--------
1번문제

#include <iostream>
using namespace std;

int main() {
	int a;

	int cnt = 0;

	cout << "a의 개수를 카운트 합니다. 문장을 입력하세요" << endl;
	while ((a = cin.get()) != EOF) {
		if (a == 'a')
			cnt++;
		else if (a == '\n')
			break;
	}
	cout << cnt;

}
------------
2번문제
#include <iostream>
using namespace std;

int main() {
	char ch;
	int cnt=0;

	cout << "빈칸이 몇 개 사용했는지 카운트 합니다." << endl;

	while (true) {
		cin.get(ch); // 키를 ch에 읽어옴

		if (cin.eof()) // EOF 문자 즉 ctrl-z 키가 입력된 경우, 읽기 종료
			break;
		if (ch == '\n') // <Enter> 키가 입력된 경우 읽기 중단
			break;
		else if (ch == ' ')
			cnt++;
	}
	cout << cnt;
}

----
7번문제
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

void showDec(int d) { // 10진수 출력
	cout << setw(10) << dec << d;
}


void showHexa(int h) { // 16진수 출력
	cout << setw(10) << hex << h;
}

void showChar(int c) { // ASCII 출력
	int i = 0;
	if ((i = isprint(c)) != 0) // 출력 가능한 문자인지 확인
		cout << setw(10) << (char)c;
	else // 출력 불가능한 문자이면 "." 출력
		cout << setw(10) << ".";
}

void print() {
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << "dec";
		cout << setw(10) << "hexa";
		cout << setw(10) << "char";
	}
	cout << endl;

	for (int i = 0; i < 4; i++) {
		cout << setw(10) << "-----";
		cout << setw(10) << "-----";
		cout << setw(10) << "-----";
	}
	cout << endl;

	for (int i = 0; i < 128; i++) {
		if (i % 4 == 0 && i != 0)
			cout << endl;
		showDec(i);
		showHexa(i);
		showChar(i);
	}

}

int main() {
	cout.setf(ios::left); // 출력 포맷 왼쪽 정렬
	print();
}
---
10번문제
#include <iostream>
using namespace std;

istream& prompt(istream& ins) {
	cout << "암호?";
	return ins;
}

int main() {
	string password;
	while (true) {
		cin >> prompt>>password;
		if (password == "C++") {
			cout << "login success!!" << endl;
			break;
		}
		else
			cout << "login fail. try again!!" << endl;
	}
}


*/
