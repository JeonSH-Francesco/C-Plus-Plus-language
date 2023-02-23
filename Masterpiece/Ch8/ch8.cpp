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
*/
