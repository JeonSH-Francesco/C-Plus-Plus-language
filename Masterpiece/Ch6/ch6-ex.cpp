/*
#include <iostream>
using namespace std;

int big(int a, int b) { // a,b 중 큰 수 리턴
	if (a > b) return a;
	else return b;
}

int big(int a[], int size) { //배열 a[] 에서 가장 큰 수 리턴
	int res = a[0];
	for (int i = 0; i < size; i++) {
		if (res < a[i]) {
			res = a[i];
		}
	}
		return res;
}

int main() {
	int array[5] = {1,9,-2,8,6};
	cout << big(2, 3) << endl;
	cout << big(array, 5) << endl;
}

--------
#include <iostream>
using namespace std;

int sum(int a, int b) {
	int s = 0;
	for (int i = a; i <= b; i++) {
		s += i;
	}
	return s;
}

int sum(int a) {
	int s = 0;
	for (int i = 0; i <= a; i++) {
		s += i;
	}
	return s;
}

int main() {
	cout << sum(3, 5) << endl;
	cout << sum(3) << endl;
	cout << sum(100) << endl;
}

//함수 중복 조건-> 이름이 같지만, 함수들의 매개변수의 개수나 타입이 달라야 한다.
------
#include <iostream>
#include <string>
using namespace std;

void star(int a = 5);
void msg(int id, string text = " ");

void star(int a) {
	for (int i = 0; i < a; i++) {
		cout << "*";
	}
	cout << endl;
}

void msg(int id, string text) {
	cout << id << ' ' << text << endl;
}

int main() {
	star();
	star(10);

	msg(10);
	msg(10, "Hello");

}
-------
#include <iostream>
using namespace std;

//default 매개 변수를 가진 함수 만들기 연습
void f(char c = ' ', int line = 1);

void f(char c, int line) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++) {
			cout << c;
		}
		cout << endl;
	}
}

int main() {
	f(); // 빈칸이 10개 출력 됨.
	f('%'); // %가 10개 1줄 출력 됨.
	f('@', 5); // @가 10개 5줄 출력 됨.
}
-----
#include <iostream>
using namespace std;

void fillLine(int n = 25, char c = '*') {
	for (int i = 0; i < n; i++) {
		cout << c;
	}
	cout << endl;
}

int main() {
	fillLine(); // 25개의 *이 출력
	fillLine(10, '%'); //10개의 '%'를 한 라인에 출력
}
----
#include <iostream>
using namespace std;

class MyVector {
	int* p;
	int size;
public:
	MyVector(int n = 100) {
		p = new int[n];
		size = n;
	}
	~MyVector() { delete[] p; }
};


int main() {
	MyVector* v1, * v2;
	v1 = new MyVector(); //default 정수 배열 100 동적 할당
	v2 = new MyVector(1024); // 정수 배열 1024 동적 할당

	delete v1;
	delete v2;
}
------
#include <iostream>
using namespace std;

//형 변환으로 인해 함수 중복이 모호한 경우

float square(float a) {
	return a * a;
}

double square(double a) {
	return a * a;
}

int main() {
	cout << square(3.0)<< endl; // square(double a); 호출
	//cout << square(3); // 중복된 함수에 대한 모호한 호출로서, 컴파일 오류
	cout << square((float)3);
}
----
#include <iostream>
using namespace std;

//참조 매개변수로 인한 함수 중복의 모호성
int add(int a, int b) {
	return a + b;
}

int add(int a, int& b) {
	b = b + a;
	return b;
}


int main() {
	int s = 10, t = 20;
	cout << add(s, t); // 컴파일 오류. 참조 매개 변수로 인해 함수 호출이 모호함.
}
----------
#include <iostream>
#include <string>
using namespace std;

//default 매개변수로 인한 함수 중복의 모호성

void msg(int id){
	cout << id << endl;
}

void msg(int id, string s = "") {
	cout << id <<  ":" << s << endl;
}


int main() {
	msg(5, "Good Morning");
	msg(6);
}
-----

static 멤버
->static의 특성
static은 변수와 함수의 생명 주기와 사용 범위를 지정하는 방식 중 하나로서,
static으로 선언된 변수와 함수의 생명 주기와 사용 범위는 다음과 같은 특징을 가진다.

->생명 주기 - 프로그램이 시작할 때 생성되고 프로그램이 종료할 때 소멸
->사용 범위 - 변수나 함수가 선언된 범위 내에서 사용, 전역(global) 혹은 지역(local)으로 구분

non-static 멤버는 각 객체마다 별도로 생성되므로 인스턴스 멤버라고 부르며,
static 멤버는 클래스 당 하나만 생기고 모든 객체들이 공유하므로 클레스 멤버라고 부른다.
static 멤버들은 private, public. protected 등 어떤 접근 지정도 가능하다.
static 멤버 변수는 외부에 전역 변수로 선언 되어야 한다.


#include <iostream>
using namespace std;

class Person {
public:
	int money; // 개인 소유의 돈
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney; // 공급
	static void addShared(int n) {
		sharedMoney += n;
	}
};


//static 변수 생성, 전역 공간에 생성
int Person::sharedMoney = 10;

int main() {
	Person han;
	han.money = 100; // han의 개인 돈=100
	han.sharedMoney = 200; // static 멤버 접근, 공금 200

	Person lee;
	lee.money = 150; // lee의 개인 돈=150
	lee.addMoney(200); // lee의 개인 돈=350
	lee.addShared(200); // static 멤버 접근, 공금=400

	cout << han.money << ' ' << lee.money << endl; // 100, 350
	cout << han.sharedMoney << ' ' << lee.sharedMoney << endl; //han과 lee의 sharedMoney는 공통 400
}
----------
#include <iostream>
using namespace std;

class Math {
public:
	static int abs(int a) { return a > 0 ? a : -a; }
	static int max(int a, int b) { return (a > b) ? a : b; }
	static int min(int a, int b) { return (a > b) ? b : a; }
};

int main() {
	cout << Math::abs(-5)<< endl;
	cout << Math::max(10,8) << endl;
	cout << Math::min(-3,-8) << endl;
}
-----
#include <iostream>
using namespace std;

class Circle {
private:
	static int numOfCircles; // 생성된 원의 개수 기억-> static
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; }// 생성된 원의 개수 감소
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircles() { return numOfCircles; } // static
};

Circle::Circle(int r) {
	radius = r;
	numOfCircles++;
}

int Circle::numOfCircles = 0;

int main() {
	Circle* p = new Circle[10];//numOfCricles=10이 됨
	cout << "생존하고 있는 원의 개수 =" << Circle::getNumOfCircles() << endl;

	delete[]p; //numOfCricles=0이 됨
	cout << "생존하고 있는 원의 개수 =" << Circle::getNumOfCircles() << endl;

	Circle a;//numOfCricles=1이 됨
	cout << "생존하고 있는 원의 개수 =" << Circle::getNumOfCircles() << endl;

	Circle b;//numOfCricles=2가 됨
	cout << "생존하고 있는 원의 개수 =" << Circle::getNumOfCircles() << endl;


}

//static 멤버 함수는 오직 static 멤버들만 접근
//static 멤버 함수는 this를 사용할 수 없다.

*/
