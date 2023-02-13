#include <iostream>
#include <string>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(Dept& dept);
	~Dept();
	int getSize() { return size; }
	void read();
	bool isOver60(int index);
};

Dept::Dept(Dept& dept) {
	this->size = dept.size;
	this->scores = new int[size];
	for (int i = 0; i < this->size; i++) {
		this->scores[i] = dept.scores[i];
	}
}

Dept::~Dept() {
	delete[] scores;
}

void Dept::read() {
	cout << "10개 점수 입력>>";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}


bool Dept::isOver60(int index) {
	if (scores[index] >= 60) return true;
	else return false;
}

int countPass(Dept dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";

	return 0;
}

/*
#include <iostream>
using namespace std;
// 값에 의한 호출
void copy(int dest, int src) {
	dest = src;
}

int main() {
	int a = 4, b = 5;
	copy(a, b);
	cout << "a: "<< a <<" b: "<< b<< endl;
}
----------
#include <iostream>
using namespace std;
// 주소에 의한 호출
void copy(int *dest, int *src) {
	*dest = *src;
}

int main() {
	int a = 4, b = 5;
	copy(&a, &b);
	cout << "a: " << a << " b: " << b << endl;
}

----------
#include <iostream>
using namespace std;
// 참조에 의한 호출
void copy(int &dest, int src) {
	dest = src;
}

int main() {
	int a = 4, b = 5;
	copy(a, b);
	cout << "a: " << a << " b: " << b << endl;
}
--------
1번문제
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { this->radius = r; }
	void show() { cout << "반지름=" << radius <<endl; }
};

void swap(Circle& a, Circle& b) {
	Circle tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	Circle a(1), b(2);
	cout << "before swap" << endl;
	a.show();
	b.show();
	cout << endl;
	cout << "after swap" << endl;
	swap(a, b);
	a.show();
	b.show();
	return 0;
}
-------
2번문제
#include <iostream>
using namespace std;

void half(double &n) {
	n /= 2; //참조 연습
}

int main() {
	double n= 20;
	half(n);
	cout << n;
}
------
3번문제
#include <iostream>
#include <string>
using namespace std;

void combine(string& text1, string& text2, string& text3) {
	text3 = text1 +" "+ text2;
}

int main() {
	string text1("I love you"), text2("very much");
	string text3;
	combine(text1, text2, text3);
	cout << text3;

}
--------
4번문제
#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) {
		big = a;
		return true;
	}
	else {
		if (a > b) big = a;
		else big = b;

		return false;
	}
}

int main() {
	int a, b, big;

	a = 5;
	b = 5;
	if (bigger(a, b, big)) {
		cout << "두 수는 같습니다" << endl;
	}
	else {
		cout << a << "와 " << b << "중 큰 수는 " << big << "입니다." << endl;
	}

	a = 5;
	b = 10;
	if (bigger(a, b, big)) {
		cout << "두 수는 같습니다" << endl;
	}
	else {
		cout << a << "와 " << b << "중 큰 수는 " << big << "입니다." << endl;
	}


	return 0;
}
--------------
5번문제
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r) { radius= r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << " 인 원"<< endl; }
};

void increaseBy(Circle &a, Circle &b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y); //x의 반지름이 15인 원을 만들고자 한다.
	x.show(); //"반지름이 15인 원"을 출력한다.
	return 0;
}
-------
6번문제
#include <iostream>
#include <string>
using namespace std;

//참조에 의한 호출과 참조를 리턴하는 함수 작성
char& find(char a[], char c, bool& success) {
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
	success = false;
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);

	if (b == false) {
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}

	loc = 'm';
	cout << s << endl;
}
----------
7번문제
#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];
	int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack();
	bool push(int n); // 정수 n 푸시, 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 팝 하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
};
MyIntStack::MyIntStack(){
	tos = 0;
}

bool MyIntStack::push(int n) {
	if (tos ==10)
		return false;
	p[tos] = n;
	tos++;
	return true;
}

bool MyIntStack::pop(int& n) {
	if (tos == 0)
		return false;
	tos--;
	n = p[tos];
	return true;
}


int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' '; //푸시된 값 에코
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}

	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' '; //팝 한 값 출력
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}
-----
8번문제
#include <iostream>
using namespace std;

class MyIntStack {
	int* p; // 스택 메모리로 사용할 포인터
	int size; // 스택의 최대 크기
	int tos; // 스택의 탑을 가리키는 인덱스
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s); // 복사 생성자 : 자기 클래스에 대한 참조
	~MyIntStack();// 소멸자
	bool push(int n);// 정수 n을 스택에 푸시한다.
	//스택이 꽉 차 있으면 false, 아니면 true 를 리턴
	bool pop(int& n); // 스택의 top에 있는 값을 n에 팝한다.
	//만일 스택이 비어 있으면 false, 아니면 true 리턴
};

MyIntStack::MyIntStack() {
	tos = 0;
}

MyIntStack::MyIntStack(int size) {
	this->p = new int[size];
	this->size = size;
	this->tos = 0;
}

MyIntStack::MyIntStack(const MyIntStack& s) {
	int len = s.size;
	this->p = new int[len];
	this->size = len;
	this->tos = s.tos;

	for (int i = 0; i <= tos; i++) {
		this->p[i] = s.p[i];
	}

}

MyIntStack::~MyIntStack() {
	delete[]p;
}

bool MyIntStack::push(int n) {
	if (tos == 10) return false;
	p[tos] = n;
	tos++;
	return true;
}

bool MyIntStack::pop(int& n) {
	if (tos == 0)
		return false;
	tos--;
	n = p[tos];
	return true;
}
int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //복사 생성
	b.push(30);

	int n;
	a.pop(n); // 스택 a에 pop
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);// 스택 b에 pop
	cout << "스택 b에서 팝한 값 " << n << endl;

}

-----
9번문제
#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value); // 매개변수 value로 멤버 value를 초기화 한다.
	Accumulator& add(int n); // value에 n을 더해 값을 리턴한다.
	int get(); // 누적된 값 value를 리턴한다.
};

Accumulator::Accumulator(int value) {
	this->value = value;
}

Accumulator& Accumulator::add(int n) {
	value += n;
	return *this;
}
int Accumulator::get() {
	return value;
}
int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();

}

----
10번문제
#include <iostream>
#include <string>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& buf, string text) {
	buf.add(text);
	return buf;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();

	return 0;
}
------------
11번문제
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price); // const char* title을 string title로 바꿔야 함.
	Book(Book& b);
	~Book();
	void set(string tile, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(string title, int price) {
	this->title = title;
	this->price = price;
}

Book::~Book() { }

void Book::set(string title, int price) {
	this->title = title;
	this->price = price;
}

Book::Book(Book& b) {
	this->title = title;
	this->price = price;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}

*/
