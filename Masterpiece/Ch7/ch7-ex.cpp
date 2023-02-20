#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text;
	int alpha[26] = { 0 };
public:
	Histogram(string text) { this->text = text; }
	Histogram& operator<< (string text);
	Histogram& operator<<(char c);
	void operator!();
};

Histogram& Histogram::operator<<(string text) {
	this->text += text;
	return *this;
}

Histogram& Histogram::operator<<(char c) {
	this->text += c;
	return *this;
}

void Histogram::operator!() {
	int count = 0; // 알파벳 전체 갯수
	char c;

	for(int i=0;i<text.length();i++){
		c = text[i];
		if (isalpha(c) != 0) { //c가 알파벳 이라면
			c = tolower(text[i]); // 문자 text[i]를 소문자로 변환하여 리턴
			alpha[(int)c - 97]++; //알파벳 배열 index에도 ++
			count++; // 알파벳 수도 ++
		}
	}
	cout << text << endl << endl;
	cout << "총 알파벳 수 " << count << endl;

	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 97) << ":";
		for (int j = 0; j < alpha[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}


}

int main() {
	Histogram song("Wise men say,\nonly fools rush in But I can't help, \n");
	song << "falling" << "in love with you." << "- by "; //히스토그램에 문자열 추가
	song << 'k' << 'i' << 't'; //히스토 그램에 문자 추가
	!song; //히스토 그램 그리기


}

/*
#include <iostream>
using namespace std;

class Rect; //Rect 클래스가 선언되기 전에 먼저 참조되는 컴파일 오류를 막기 위한 선언문
bool equals(Rect r, Rect s); //equals() 함수 선언

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width;  this->height = height; }
	friend bool equals(Rect r, Rect s); //프렌드 함수 선언
};

bool equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
} //외부 함수

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}

//두 객체를 비교하는 bool equals(Rect r, Rect s)를 Rect 클래스에 프렌드 함수로 작성

------------
#include <iostream>
using namespace std;

class Rect;

class RectManager { //RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s); // 프렌드 함수 선언
};

//이렇게 friend 연산자를 통해 다른 클래스의 멤버 함수를 선언하면
//RectManager의 모든 멤버 함수는 Rect 클래스의 모든 멤버를 자유롭게 접근할 수 있다.

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height ==s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(3, 4);
	RectManager man;

	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;

}
------------
#include <iostream>
using namespace std;

class Rect;

class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};


class Rect { //Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager; //RectManager 클래스의 모든 함수를 프렌드 함수로 선언
};


bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {
	dest.width = src.width;
	dest.height = src.height;
}


int main() {
	Rect a(3, 4), b(5, 6);
	RectManager man;

	man.copy(b, a);
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
---------
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator+ (Power op2); // +연산자 함수 선언
	bool operator== (Power op3); // == 연산자 함수 선언
	Power& operator+=(Power op4); //+= 연산자 함수 선언
};

void Power::show() {
	cout << "kick : " << kick << " punch : " << punch << endl;
}


Power Power::operator+(Power op2) {//+연산자 멤버 함수 구현
	Power tmp;//임시 객체 생성
	tmp.kick = this->kick + op2.kick; // kick 더하기
	tmp.punch = this->punch + op2.punch; // punch 더하기
	return tmp; // 더한 결과 리턴
}

bool Power::operator==(Power op3) {//==연산자 멤버 함수 구현
	if (kick == op3.kick && punch == op3.punch) return true;
	else return false;
}

Power& Power::operator+=(Power op4) {//+=연산자 멤버 함수 구현
	kick = kick + op4.kick;
	punch = punch + op4.punch;
	return *this;
}

int main() {
	Power a(3, 5), b(4, 6), c, d(3, 5),e;
	c = a + b;
	a.show();
	b.show();
	c.show();

	if (a == d) cout << "두 파워가 같다." << endl;
	else cout << "두 파워가 같지 않다." << endl;

	e = d += b;
	e.show();
}
--------
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator++ (int x); // 후위 ++연산자 함수 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch<< endl;
}

Power Power::operator++(int x) {
	Power tmp = *this;
	kick++;
	punch++;
	return tmp;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a++;

	a.show();
	b.show();
}
----------
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	friend Power operator+(int op1, Power op2); //프렌드 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(int op1,Power op2) {
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;
	return tmp;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = 2+a;

	a.show();
	b.show();
}
--------
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	friend Power operator+(Power op1, Power op2); //프렌드 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(Power op1, Power op2) {
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}

int main() {
	Power a(3, 5), b(4,6), c;

	c = a + b;
	a.show();
	b.show();
	c.show();
}
----------
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	friend Power& operator++(Power &op); // 전위 ++연산자 함수 프렌드 선언
	friend Power operator++(Power& op, int x); // 후위 ++연산자 함수 프렌드 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

//전위 연산자의 경우 참조 리턴에 주목
Power& operator++(Power & op) { // 전위 ++ 연산자 함수 구현
	op.kick++;
	op.punch++;
	return op; // 연산 결과 리턴
}

Power operator++(Power& op, int x) { // 후위 ++연산자 함수 구현
	Power tmp = op;//변경하기 전의 op 상태 저장
	op.kick++;
	op.punch++;
	return tmp; // 변경 이전의 op 리턴
}

//각각 참조 매개변수 사용에 주목

int main() {
	Power a(3, 5), b(4, 6);

	b=++ a; // 전위 연산자
	cout << "a.show : "; a.show();
	cout << "b.show : "; b.show();

	b = a++; //후위 연산자
	cout << "a.show : "; a.show();
	cout << "b.show : "; b.show();
}
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power& operator << (int n); //연산 후 Power 객체의 참조 리턴
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power& Power::operator<<(int n) {
	kick += n;
	punch += n;
	return *this;
}

int main() {
	Power a(1, 2);
	a << 3 << 5 << 6;
	a.show();
}
*/
