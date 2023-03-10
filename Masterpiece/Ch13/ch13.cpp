#include<iostream>
using namespace std;
int* copy(int* src, int size) {
	int* p = NULL;
	if (size < 0) {
		throw - 1; // too small
	}
	else if (size > 100) {
		throw - 2; // too big
	}
	p = new int[size]; // 메모리 할당
	if (p == NULL) {
		throw - 3; // memory short
	}
	else if (src == NULL) {
		throw - 4; // NULL source
		delete[] p;
	}
	else { // 정상적으로 배열을 복사하는 부분
		for (int n = 0; n < size; n++) p[n] = src[n];
		return p;
	}
}
int main() {
	int x[] = { 1,2,3 };
	try {
		int* p = copy(x, 3);
		for (int i = 0; i < 3; i++) cout << p[i] << ' ';
		cout << endl;
		delete[]p;
	}
	catch (int a) {
		cout << "failCode : " << a;
		return 0;
	}
}

[출처] 명품 C++ programming 13장 실습문제 8번 | 작성자 purposeforblogging




/*
-------
1번문제
#include <iostream>
using namespace std;


int sum(int a, int b) {
	if (a > b) throw "잘못된 입력";
	if (a < 0 || b < 0) throw "음수 처리 안됨";
	int s = 0;
	for (int i = a; i <= b; i++)
		s += i;
	return s;
}

int main() {
	try {
		cout << sum(2, 5) << endl;
		cout << sum(-1, 5) << endl;
	}
	catch (const char* s) {
		cout << s << endl;
	}

}
-------
2번문제
#include <iostream>
using namespace std;

int main() {
	int score = 0;
	cout << "0~100점 사이의 점수를 입력하시오>>";
	cin >> score;

	try {
		if (score >= 90 && score <= 100)
			cout << "A학점입니다." << endl;
		else if (score >= 80 && score < 90)
			cout << "B학점입니다." << endl;
		else if (score >= 70 && score < 80)
			cout << "C학점입니다." << endl;
		else if (score >= 60 && score < 70)
			cout << "D학점입니다." << endl;
		else if (score >= 0 && score < 60)
			cout << "F학점입니다." << endl;
		else
			throw "점수 입력 오류";
	}
	catch (const char *s) {
		cout << s << endl;
	}


}
------
5번문제
#include <iostream>
using namespace std;

void print() {
	while (true) {
		int n=0;
		cout << "양수 입력>>";
		cin >> n;
		if (cin.fail())
			throw "입력 오류가 발생하여 더 이상 입력 불가. 프로그램 종료.";
		else if (1 > n || 9 < n) {
			cout << "잘못된 입력 1~9사이의 정수만 입력하세요." << endl;
			continue;
		}
		for (int i = 0; i <= 9; i++) {
			cout << n << 'x' << i << "=" << n * i << ' ';
		}
		cout << endl;
	}

}

int main() {
	try {
		print();
	}
	catch (const char* s) {
		cout << s << endl;
	}
}


*/
