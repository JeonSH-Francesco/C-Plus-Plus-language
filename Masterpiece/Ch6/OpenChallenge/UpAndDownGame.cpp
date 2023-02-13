#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Person {
	string s[2];
	int n; //카운트 루프
public:
	Person() { s[0] = "김인수"; s[1] = "오은경"; n = -1; }
	string getName() {
		n++; 
		if (n ==2) {
			n = 0;
			return s[n];
		}
		else {
			return s[n];
		}
	}
};

class UpAndDownGame {
	static int result;// 랜덤하게 생성된 수 = 답
	static int start, end; // 시작과 끝
public:
	UpAndDownGame() { srand( (unsigned)time(0)); }
	static void game();
};

int UpAndDownGame::start = 0; // 초기화
int UpAndDownGame::end = 99; // 초기화
int UpAndDownGame::result=0; // 정답은 0부터 99 사이의 수



void UpAndDownGame::game() {
	int number;
	Person p;
	cout << "Up & Down 게임을 시작합니다." << endl;
	result = rand() % 100;
	while (1) {
		string name = p.getName();
		cout << "답은 " << start << "과" << end << "사이에 있습니다." << endl;
		cout << name << ">>";
		cin >> number;

		if (number > result)
		{
			end = number;
		}
		else if (number < result)
		{
			start = number;
		}
		else {
			cout << name << "이(가) 이겼습니다!!" << endl;
			break;
		}
	}
}

int main() {
	UpAndDownGame gamestart;
	gamestart.game();
}
