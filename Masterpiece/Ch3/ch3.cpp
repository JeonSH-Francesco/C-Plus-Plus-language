/*
----------
1번문제
#include <iostream>
using namespace std;

class Tower{
	int height;
public:
	Tower();
	Tower(int height);
	int getHeight();
};

Tower::Tower() {
	height = 1;
}
Tower::Tower(int h) {
	height = h;
}

int Tower::getHeight(){
	return height;
}

int main() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << " 미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << " 미터" << endl;

}
-----------
2번 문제
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Date {
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d);
	Date(string strDate);
	void show();
	int getYear();
	int getMonth();
	int getDay();

};

Date::Date(int y, int m, int d) {
	year=y;
	month = m;
	day = d;
}
Date::Date(string strDate) {
	char* str_buff = new char[100];
	strcpy(str_buff, strDate.c_str());

	year = stoi(strtok(str_buff, "/"));
	month= stoi(strtok(nullptr, "/"));
	day= stoi(strtok(nullptr, "/"));
}

void Date::show() {

	cout << year << "년" << month << "월" << day << "일" << endl;

}

int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}
----------
2번문제 sol2
#include <iostream>
#include <string>

using namespace std;

class Date {
public:
	int year;
	int month;
	int day;
	Date(int year, int month, int day);
	Date(string date);
	void show();
	int getYear();
	int getMonth();
	int getDay();
};

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Date(string date)
{
	int ind;

	this->year = stoi(date);

	ind = date.find('/');
	this->month = stoi(date.substr(ind + 1));

	ind = date.find('/', ind + 1);
	this->day = stoi(date.substr(ind + 1));
}
void Date::show()
{
	cout << year << "년" << month << "월" << day << "일" << endl;
}
int Date::getYear()
{
	return year;
}
int Date::getMonth()
{
	return month;
}
int Date::getDay()
{
	return day;
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;

	return 0;
}
-----------
3번문제
#include <iostream>
using namespace std;

class Account {
	string name;
	int id;
	int balance;
public:
	Account(string name, int id,int balance);
	void deposit(int money);
	int withdraw(int money);
	string getOwner();
	int inquiry();
};

Account::Account(string name,int id, int balance) {
	this->name = name;
	this->id = id;
	this->balance = balance;
}

void Account::deposit(int money) {
	balance += money;
}

int Account::withdraw(int money) {
	balance -= money;
	return money;
}
string Account::getOwner() {
	return name;
}
int Account::inquiry() {
	return balance;
}


int main() {
	Account a("kitae",1,5000);//id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은" << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은" << a.inquiry() << endl;
}
----------
4번문제
#include <iostream>
using namespace std;


class CoffeeMachine {
	int coffee;
	int water;
	int sugar;
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void fill();
	void show();
};

CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	coffee=c; //this->coffee=coffee;
	water = w;//this->water=water;
	sugar = s;//this->sugar=sugar;
}

void CoffeeMachine::drinkEspresso() {
	coffee -= 1;
	water -= 1;
}
void CoffeeMachine::drinkAmericano() {
	coffee -= 1;
	water -= 2;
}void CoffeeMachine::drinkSugarCoffee() {
	coffee -= 1;
	water -= 2;
	sugar -= 1;
}
void CoffeeMachine::fill() {
	coffee = 10;
	water = 10;
	sugar = 10;
}
void CoffeeMachine::show() {
	cout << "커피 마신 상태, "<<"커피"<<coffee<<"\t물" <<water << "\t설탕"<< sugar<< endl;
}

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();

}
--------
5번문제
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Random {
	int s, e;
public:
	Random();
	int next();
	int nextInRange(int s, int e);
};

Random::Random() {
	srand((unsigned int)time(NULL));
	s = 0;
	e = RAND_MAX;
}
int Random::next() {
	return rand() % (RAND_MAX + 1); //1~RAND_MAX 사이의 랜덤 값 생성
}
int Random::nextInRange(int s, int e) {
	return rand() % (e - s + 1) + s; //s~e 사이의 랜덤 값 생성
}


int main() {
	Random r;
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;

	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 4까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;

}
------
6번문제
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class EvenRandom {
	int s, e;
public:
	EvenRandom();
	int next();
	int nextInRange(int s, int e);
};

EvenRandom::EvenRandom() {
	srand((unsigned int)time(NULL));
	s = 0;
	e = RAND_MAX;
}
int EvenRandom::next() {
	while (true) {
		int even = rand() % (RAND_MAX + 1);
		if(even % 2 ==0){
			return even;
		}
	}
}


int EvenRandom::nextInRange(int s, int e) {
	while (true) {
		int even = rand() % (e - s + 1) + s;
		if (even % 2 == 0) {
			return even;
		}
	}

}


int main() {
	EvenRandom r;
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;

	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 10까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;

}
----
7번문제
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SelectableRandom {
	int seed = 0;
public:
	int nextEven();
	int nextOdd();
	int nextEvenInRange(int start, int end);
	int nextOddInRange(int start, int end);
};

int SelectableRandom::nextEven() {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand();
	} while (n % 2 != 0);
	return n;
}
int SelectableRandom::nextOdd() {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand();
	} while (n % 2 != 1);
	return n;
}
int SelectableRandom::nextEvenInRange(int start, int end) {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand() % (end - start + 1) + start;
	} while (n % 2 != 0);
	return n;
}
int SelectableRandom::nextOddInRange(int start, int end) {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand() % (end - start + 1) + start;
	} while (n % 2 != 1);
	return n;
}

int main() {
	SelectableRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextEven();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 9까지의 랜덤 홀수 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextOddInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;
	return 0;
}
-------
8번문제
#include <iostream>
#include <string>
using namespace std;

class Integer {
	int num;
public:
	Integer(int num);
	Integer(string num);
	void set(int num);
	int get();
	int isEven();
};

Integer::Integer(int num){
	this->num = num;
}
Integer::Integer(string num) {
	this->num = stoi(num);
}
void Integer::set(int num){
	this->num = num;
}

int Integer::get() {
	return num;
}
int Integer::isEven() {
	return true;
}
//class Integer {
//	int num;
//public:
//	Integer(int num) {
//		this->num = num;
//	}
//	Integer(string num) {
//		this->num = stoi(num);
//	}
//	void set(int num) {
//		this->num = num;
//	}
//	int get() {
//		return num;
//	}
//	int isEven() {
//		return true;
//	}
//};

int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven() << ' ';
}
--------
9번문제
#include <iostream>
#include <string>

using namespace std;

class Oval {
private:
	int width;
	int height;
public:
	Oval() {
		width = height = 1;
	}
	Oval(int width, int height) {
		this->width = width;
		this->height = height;
	}
	~Oval() {
		cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
	}
	void show() {
		cout << "width = " << width << ", height = " << height << endl;
	}
	void set(int width, int height) {
		this->width = width;
		this->height = height;
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
};

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;

	return 0;
}
----------
10-1
#include <iostream>
#include <string>

using namespace std;

class Add {
	int a, b;
public:
	void setValue(int x,int y){
		a = x; b = y;
	}
	int calculate() {
		return a + b;
	}
};

class Sub {
	int a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a - b;
	}
};

class Mul {
	int a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a * b;
	}
};

class Div {
	int a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a / b;
	}
};

int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;
	while (true) {
		cout << "두 정수와 연산자를 입력하세요>>";
		int x, y;
		char op;
		cin >> x >> y >> op;

		switch (op) {
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}
------
10-2
calculator.h

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Add {
	int x, y;
public:
	void setValue(int x, int y);
	int calculate();
};

class Sub {
	int x, y;
public:
	void setValue(int x, int y);
	int calculate();
};

class Mul {
	int x, y;
public:
	void setValue(int x, int y);
	int calculate();
};

class Div {
	int x, y;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif
------
calculator.cpp

#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

void Add::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}

int Add::calculate() {
	return x + y;
}

void Sub::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}

int Sub::calculate() {
	return x - y;
}

void Mul::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}

int Mul::calculate() {
	return x * y;
}

void Div::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}

int Div::calculate() {
	return x / y;
}

int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;
	while (true) {
		cout << "두 정수와 연산자를 입력하세요>>";
		int x, y;
		char op;
		cin >> x >> y >> op;

		switch (op) {
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}


--------------
Box.h

#ifndef BOX_H
#define BOX_H
class Box {
	int width, height;
	char fill;
public:
	Box(int w, int h);
	void setFill(char f);
	void setSize(int w, int h);
	void draw();
};

#endif

Box.cpp
#include <iostream>
#include "Box.h"

using namespace std;

Box::Box(int w, int h) {
  setSize(w, h);
  fill = '*';
}
void Box::setFill(char f) {
  fill = f;
}
void Box::setSize(int w, int h) {
  width = w;
  height = h;
}

void Box::draw() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << fill;
		}
		cout << endl;
	}
}


main.cpp
#include "Box.h"

int main() {
	Box b(10, 2);
	b.draw();
	cout << endl;
	b.setSize(7, 4);
	b.setFill('^');
	b.draw();

	return 0;
}

--------
Ram.h
#ifndef RAM_H
#define RAM_H

class Ram {
	char mem[100 * 1024];
	int size;
public:
	Ram();
	~Ram();
	char read(int address);
	void write(int address, char value);
};

#endif

-----------
Ram.cpp
#include <iostream>
#include <string>
#include "Ram.h"

using namespace std;

Ram::Ram() {
	for (int i = 0; i < 100 * 1024; i++) {
		mem[i] = 0;
	}
	size = 100 * 1024;
}
Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address) {
	return mem[address];
}
void Ram::write(int address, char value) {
	mem[address] = value;
}



--------
main.cpp
#include <iostream>
#include "Ram.h"
using namespace std;

int main() {
	Ram ram;
	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101);
	ram.write(102, res);
	cout << "102번지의 값 = " << (int)ram.read(102) << endl;

	return 0;
}



*/
