#include <iostream>
using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
protected:
	Printer(string mo = "", string me = "", int a = 0) {
		this->model = mo;
		this->manufacturer = me;
		this->availableCount = a;
		this->printedCount = 0;
	}
	bool isValidPrint(int pages) {
		if (availableCount > pages) return true;
		else return false;
	}
	void print(int pages) {
		if (isValidPrint(pages)) {
			printedCount += pages;
			availableCount -= pages;
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showPrinter() { cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장"; }
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0) : Printer(mo, me, a) { this->availableInk = i; }
	bool isValidInkJetPrint(int pages) {
		if (availableInk > pages) return true;
		else return false;
	}
	void printInkJet(int pages) {
		if (isValidPrint(pages)) {
			if (isValidInkJetPrint(pages)) {
				print(pages);
				availableInk -= pages;
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showInkJetPrinter() {
		showPrinter();
		cout << ", 남은 토너 " << availableInk << endl;
	}
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0) : Printer(mo, me, a) { this->availableToner = t; }
	bool isValidLaserPrint(int pages) {
		if (availableToner > pages) return true;
		else return false;
	}
	void printInkJet(int pages) {
		if (isValidPrint(pages)) {
			if (isValidLaserPrint(pages)) {
				print(pages);
				availableToner -= pages;
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showLaserPrinter() {
		showPrinter();
		cout << ", 남은 토너 " << availableToner << endl;
	}
};

int main() {
	InkJetPrinter ink("Officejet V40", "HP", 100, 100);
	LaserPrinter laser("SCX-6x45", "삼성전자", 100, 100);

	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink.showInkJetPrinter();
	cout << "레이저 : ";
	laser.showLaserPrinter();

	int printer, paper;
	char ch;
	
	
	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> paper;

		if (printer != 1 && printer != 2) {
			cout << "올바른 프린터를 선택하세요.";
			continue;
		}

		switch (printer) {
		case 1: ink.printInkJet(paper); break;
		case 2: laser.printInkJet(paper); break;
		default: break;
		}
		ink.showInkJetPrinter();
		laser.showLaserPrinter();

		cout << "게속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') {
			break;
		}
		else if (ch != 'y') {
			cout << "잘못된 입력입니다. 게속 진행하려면 y를 누르세요. "<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//streamsize의 타입의 최대값을 반환-> 현재 입력버퍼에서 최대한 많은 문자를 개행문자가 나올 때까지 무시
			cout << "게속 진행하시겠습니까(y/n)>>";
			cin >> ch; 
		}

	}

	return 0;
}

/*
1번문제
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius*radius;
	}
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius = 0, string name = "") :Circle(radius) {
		this->name = name;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
};


int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
	return 0;
}
-----------------
2번문제
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius = 0, string name = "") : Circle(radius){
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setName(string name){
		this->name = name;
	}
};

int main() {
	int r;
	string name;
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요."<< endl;
	NamedCircle pizza[5];
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">>";
		cin >> r >>name;
		pizza[i].setName(name);
		pizza[i].setRadius(r);
	}
	int max = 0, j; //최대의 면적에 해당하는 원 구하기
	for (int i = 0; i < 5; i++) {
		if (pizza[i].getArea() > max) {
			max = pizza[i].getArea();
			j = i;
		}
	}
	cout << "가장 면적이 큰 피자는" << pizza[j].getName() << "입니다." << endl;
	return 0;
}
---------
3번문제
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x = 0, int y = 0, string color = "") : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { move(x, y); }
	void setColor(string color) { this->color = color; }
	void show() {
		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
	}
};

int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}
-----------------
4번문제
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { move(x, y); }
	void setColor(string color) { this->color = color; }
	void show() {
		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
	}
};

int main() {
	ColorPoint zeroPoint; // Black 색에 (0,0) 위치의 점
	zeroPoint.show(); // zeroPoint를 출력한다.

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();

}
-------
5번문제
#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity; // 배열의 크기
	int* mem; //정수 배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray(int capacity) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) {
		mem[index] = val;
	}
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
	int start, end;
public:
	MyQueue(int capacity) : BaseArray(capacity) { start = 0; end = 0; }
	int capacity() { return getCapacity(); }
	int length() { return end - start; }
	void enqueue(int n) { put(end, n); end++; }
	int dequeue() { return get(start++); }
};


int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
	return 0;
}
--------
6번문제
#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity; // 배열의 크기
	int* mem; //정수 배열을 만들기 위한 메모리의 포인터
protected:
	BaseArray(int capacity=100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) {
		mem[index] = val;
	}
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack:public BaseArray {
	int top;
public:
	MyStack(int capacity) : BaseArray(capacity) { top = -1; }
	int capacity() { return getCapacity(); }
	int length() { return top + 1;}
	void push(int n) { put(++top, n); }
	int pop() { return get(top--); }
};


int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택의 용량:" << mStack.capacity() << ", 스택의 크기:" << mStack.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
	return 0;
}
-------
7번문제
#include <iostream>
using namespace std;

class BaseMemory {
	char* mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	void setData(char x, int length) { mem[length] = x; }
	void setData(char x[], int length) {
		for (int i = 0; i < length; i++)
			mem[i] = x[i];
	}
	char getData(int index)
	{
		return mem[index];
	}
};

class ROM : public BaseMemory {
public:
	ROM(int size, char x[], int length) :BaseMemory(size) {
		setData(x, length);
	}
	char read(int index) { return getData(index); }
};


class RAM : public BaseMemory {
public:
	RAM(int size) : BaseMemory(size) {}
	void write(int index, char data) { setData(data, index); }
	char read(int index) { return getData(index); }
};


int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
	return 0;
}
--------
8번문제
#include <iostream>

using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
protected:
	Printer(string mo = "", string me = "", int a = 0) {
		this->model = mo;
		this->manufacturer = me;
		this->availableCount = a;
		this->printedCount = 0;
	}
	bool isValidPrint(int pages) {
		if (availableCount > pages) return true;
		else return false;
	}
	void print(int pages) {
		if (isValidPrint(pages)) {
			printedCount += pages;
			availableCount -= pages;
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showPrinter() { cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장"; }
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0) : Printer(mo, me, a) { this->availableInk = i; }
	bool isValidInkJetPrint(int pages) {
		if (availableInk > pages) return true;
		else return false;
	}
	void printInkJet(int pages) {
		if (isValidPrint(pages)) {
			if (isValidInkJetPrint(pages)) {
				print(pages);
				availableInk -= pages;
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showInkJetPrinter() {
		showPrinter();
		cout << ", 남은 토너 " << availableInk << endl;
	}
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0) : Printer(mo, me, a) { this->availableToner = t; }
	bool isValidLaserPrint(int pages) {
		if (availableToner > pages) return true;
		else return false;
	}
	void printInkJet(int pages) {
		if (isValidPrint(pages)) {
			if (isValidLaserPrint(pages)) {
				print(pages);
				availableToner -= pages;
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void showLaserPrinter() {
		showPrinter();
		cout << ", 남은 토너 " << availableToner << endl;
	}
};

int main() {
	InkJetPrinter ink("Officejet V40", "HP", 5, 10);
	LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink.showInkJetPrinter();
	cout << "레이저 : ";
	laser.showLaserPrinter();

	int printer, paper;
	char ch;
	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> paper;
		switch (printer) {
		case 1: ink.printInkJet(paper); break;
		case 2: laser.printInkJet(paper); break;
		default: break;
		}
		ink.showInkJetPrinter();
		laser.showLaserPrinter();

		cout << "게속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		else continue;
	}

	return 0;
}
*/
