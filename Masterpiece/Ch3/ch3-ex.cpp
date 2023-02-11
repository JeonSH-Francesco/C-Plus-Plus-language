#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	double getArea();
}; //Circle 클래스 선언부

double Circle::getArea() {
	return 3.14 * radius * radius;
}//Circle 클래스 구현부

int main() {
	Circle donut;
	donut.radius = 1;
	double darea = donut.getArea();
	cout << "donut 면적은 " << darea << endl;

	Circle pizza;
	pizza.radius = 30;
	double parea = pizza.getArea();
	cout << "pizza 면적은 " << parea << endl;

}
-----------
#include <iostream>
using namespace std;

class Rectangle {
public:
	int width;
	int height;
	int getArea();
}; //Rectangle 클래스 선언부

int Rectangle::getArea() {
	return width * height;
}

int main() {
	Rectangle rect;
	rect.width=3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;

}
-----------------
2개의 생성자를 가진 Circle 클래스
#include <iostream>
using namespace std;
class Circle {
public:
	int radius;
	Circle();//기본 생성자
	Circle(int r); //매개변수 있는 생성자
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << "인 원을 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << "인 원을 생성" << endl;
}
//중복된 초기화 코드를 하나의 생성자로 몰고, 다른 생성자에서 이 생성자를 호출할 수 있게 한다.


double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	double darea = donut.getArea();
	cout << "donut의 면적은 " << darea << endl;
	cout << endl;
	Circle pizza(30);
	double parea = pizza.getArea();
	cout << "pizza의 면적은 " << parea << endl;
}
#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();//위임 생성자(delegating constructor)
	Circle(int r); //타겟 생성자
	double getArea();
};

Circle::Circle() : Circle(1){} //위임 생성자

//타켓 생성자에 객체 초기화를 전담시킴으로써 객체의 생성 과정이 명료해지고 단순해진다.
//위임 생성자에서는 타겟 생성자를 호출한 뒤, 자신만의 코드를 추가하면 된다.

//호출 r에 1 전달
Circle::Circle(int r) {
	radius = r;
	cout << "반지름" << radius << "원 생성" << endl;
}

double Circle::getArea() {
	return 3.14 * radius*radius;
}

int main() {
	Circle donut;
	double darea = donut.getArea();
	cout << "donut의 면적은 " << darea << endl;

	cout << endl;

	Circle pizza(30);
	double parea = pizza.getArea();
	cout << "pizza의 면적은 " << parea << endl;
}
#include <iostream>
using namespace std;

class point {
	int x, y;
public:
	point();
	point(int a, int b);
	void show() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

point ::point() : point(0,0){} //point(int a, int b) 생성자 호출

point::point(int a, int b)
	:x(a), y(b){}

int main() {
	point origin;
	point target(10, 20);
	origin.show();
	target.show();
}
------
main()함수가 잘 작동하도록 Rectangle 클래스를 작성하고 프로그램을 완성해라
->Rectangle 클래스는 width와 height 의 두 멤버 변수와 3개의 생성자,
그리고 isSqaure()함수를 가진다.
#include <iostream>
using namespace std;

class Rectangle {
public:
	int width, height;
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(int length);
	bool isSqaure();
};

Rectangle::Rectangle() {
	width = height = 1;
}

Rectangle::Rectangle(int w,int h){
	width = w; height = h;
}


Rectangle::Rectangle(int length) {
	width = height =length;
}

bool Rectangle::isSqaure() {
	if (width == height) return true;
	else return false;
}

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSqaure()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSqaure()) cout << "rect2는 정사각형이다." << endl;
	if (rect3.isSqaure()) cout << "rect3는 정사각형이다." << endl;
}
----------
#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle(); //소멸자 선언
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "반지름" << radius << " 원 생성" << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "반지름" << radius << "원 생성" << endl;
}

//소멸자의 목적은 객체가 사라질 때 필요한 마무리 작업을 위함으로 클래스 이름 앞에 ~를 붙인다.
Circle::~Circle() {
	cout << "반지름" << radius << "원 소멸" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

//전역 개체 생성 ->전역 객체는 프로그램이 로딩시 생성. main() 종료 후, 프로그램 메모리가 사라질 떄 소멸
Circle globalDonut(1000);
Circle globalPizza(2000);

//지역 객체 생성 ->지역 객체는 함수 실행시 생성되고 종료시 소멸되며
void f() {
	Circle fDonut(100);
	Circle fPizza(200);
}

int main() {
	//Circle donut;
	//Circle pizza(30);

	//지역 객체 생성
	Circle mainDonut;
	Circle mainPizza(30);
	f();

	return 0;
}
----------
#include <iostream>
using namespace std;

class PrivateAccessError {
private:
	int a;
	void f();
	PrivateAccessError();
public:
	int b;
	PrivateAccessError(int x);
	void g();
};

PrivateAccessError::PrivateAccessError() {
	a = 1;
	b = 1;
}

PrivateAccessError::PrivateAccessError(int x){
	a = x;
	b = x;
}

void PrivateAccessError::f() {
	a = 5;
	b = 5;
}

void PrivateAccessError::g() {
	a = 6;
	b = 6;
}

int main() {
	PrivateAccessError objA; // ->생성자 PrivateAccessError는 private이므로 main()에서 호출X
	PrivateAccessError objB(100);
	objB.a = 10;//->a는 PrivateAccessError 클래스의 private 멤버이므로 main()에서 접근 X
	objB.b = 20;
	objB.f(); //->f()는 PrivateAccessError 클래스의 private 멤버이므로 main()에서 호출 X
	objB.g();
}
------
#include <iostream>
using namespace std;

struct StructCircle {
private:
	int radius;
public:
	StructCircle(int r) { radius=r; }
	double getArea();
};

double StructCircle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	StructCircle sc(3);
	cout << "면적은" << sc.getArea();
}
//C++클래스 멤버의 디폴트 접근 권한은 private이며, 구조체 멤버의 디폴트 접근 권한은 public이다.













----------------
circle.h
#pragma once
class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getArea();
};

-------
circle.cpp
#include <iostream>
using namespace std;

#include "Circle.h"

Circle::Circle() {
	radius = 1;
	cout << "반지름" << radius;
	cout << "원 생성" << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "반지름" << radius;
	cout << "원 생성" << endl;

}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

--------
main.cpp
#include <iostream>
using namespace std;

#include "Circle.h"

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은";
	cout << area << endl;


	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은";
	cout << area << endl;
}





----------

Adder.h

#pragma once
#ifndef ADDER_H
#define ADDER_H

//덧셈 모듈 클래스
class Adder{
	int op1, op2;
public:
	Adder(int a, int b);
	int process();
};
#endif
===========
Adder.cpp

#include "Adder.h"

Adder::Adder(int a, int b) {
	op1 = a;
	op2 = b;
}

int Adder::process() {
	return op1 + op2;
}


=================

Calculator.h

#pragma once
#ifndef Cal_h
#define Cal_h
//계산기 클래스
class Calculator {
public:
	void run();
};

#endif
=========================
Calcultor.cpp
#include <iostream>
using namespace std;

#include "Adder.h"
#include "Calculator.h"

void Calculator::run() {
	cout << "두개의 수를 입력하세요~>> : ";
	int a, b;
	cin >> a >> b;	//정수 2개 입력
	Adder adder(a, b); // 덧셈기 생성
	cout << adder.process(); //덧셈 계산
}
=======
main.cpp
#include "Calculator.h"
int main() {
	Calculator calc;
	calc.run();
}



-------------------------

=======
Exp.h
#pragma once
#ifndef exp_h
#define exp_h

class Exp {
	int base;
	int exponent;
public:
	Exp();
	Exp(int a);
	Exp(int a, int b);
	int getValue(); //지수를 정수로 계산하여 리턴
	int getBase();// 베이스 값 리턴
	int getExp(); //지수 값 리턴
	bool equals(Exp b); //이 객체와 객체 b의 값이 같은지 판별하여 리턴
};

#endif
========
Exp.cpp
#include "Exp.h"

Exp::Exp() { 
	base = 1; 
	exponent = 1; 
}

Exp::Exp(int a) {
	base = a;
	exponent = 1;
}

Exp::Exp(int a, int b) {
	base = a;
	exponent = b;
}

int Exp::getValue() {
	int result = base;
	for (int i = 1; i < exponent; i++) {
		result *= base;
	}
	return result;
}

int Exp::getBase() {
	return base;
}

int Exp::getExp() {
	return exponent;
}

bool Exp::equals(Exp b) {
	if (getValue() == b.getValue())
		return true;
	else
		return false;
}


==========
main.cpp
#include <iostream>
#include "Exp.h"
using namespace std;

int main() {
	Exp a(3, 2);
	Exp b(9);
	Exp c;

	cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << endl;
	cout << "a의 베이스 " << a.getBase() << ',' << "a의 지수 " << a.getExp() << endl;

	if (a.equals(b))
		cout << "same" << endl;
	else
		cout << "not same" << endl;

}
