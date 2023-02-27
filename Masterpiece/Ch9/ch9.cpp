#include <iostream>
using namespace std;

class Shape {
	Shape* next; //추상 클래스의 포인터 선언
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	void paint() {
		draw();
	}
	Shape* getNext() { return next; }
};

//순수 가상함수 다양하게 구현
class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rectangle : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class UI {
public:
	static int getMenu() {
		int key;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> key;
		return key;
	}
	static int getShapeTypeToInsert() {
		int key;
		cout << "선:1, 원:2, 사각형:3 >>";
		cin >> key;
		return key;
	}
	static int getShapeIndexToDelete() {
		int key;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> key;
		return key;
	}
};



class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() { pStart = pLast = NULL; }
	void InsertItem(int type) {
		Shape* p = NULL;
		switch (type) {
		case 1:
			p = new Line();
			break;
		case 2:
			p = new Circle();
			break;
		case 3:
			p = new Rectangle();
			break;
		default:
			break;
		}
		if (pStart == NULL) {
			pStart = p;
			pLast = p;
			return;
		}
		else {
			pLast->add(p);
			pLast = pLast->getNext();
		}
	}

	void deleteItem(int index) {
		Shape* pre = pStart;
		Shape* tmp = pStart;
		if (pStart == NULL) {
			cout << "도형이 없습니다." << endl;
			return;
		}
		for (int i = 1; i < index; i++) {
			pre = tmp;
			tmp = tmp->getNext();
		}
		if (tmp == pStart) {  //처음 것 지워지는 경우
			pStart = tmp->getNext();//단순히 tmp의 다음 노드 연결
			delete tmp;
		}
		else { // 중간의 것 지워지는 경우
			pre->add(tmp->getNext()); // 삭제한 다음 노드를 연결
			delete tmp;
		}
	}

	void show() {
		Shape* tmp = pStart;
		int i = 0;
		while (tmp != NULL) {
			cout << i++ << ": ";
			tmp->paint();
			tmp = tmp->getNext();
		}
	}

	void run() {
		cout << "그래픽 에디터입니다." << endl;
		int menu, index, type;
		while (true) {
			menu = UI::getMenu();
			switch (menu) {
			case 1:
				type = UI::getShapeTypeToInsert();
				InsertItem(type);
				break;
			case 2:
				index = UI::getShapeIndexToDelete();
				deleteItem(index);
				break;
			case 3:
				show();
				break;
			default:
				return;
			}
		}
	}
};

int main() {
	GraphicEditor graphicEditor;
	graphicEditor.run();

	return 0;
}


/*#include <iostream>
using namespace std;

class Base {
public:
	void func() { f(); }
	void f() { cout << "Base::f() called." << endl; }
	//virtual키워드를 넣는지 여부에 따라 결과는 달라진다.
	//
};

class Derived : public Base {
public:
	void f() { cout << "Derived::f() called." << endl; }
};

int main() {
	Derived der;
	der.f();
	Base base;
	Base* p = &base;
	p->f();
	p = &der;
	p->f();
	p->func();


}
-----------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Person {
	int id;
public:
	Person(int id = 0) { this->id = id; }
	virtual ~Person() { cout << "id = " << id << endl; }
};
 
class Student : public Person {
	char* name;
public:
	Student(int id, const char* name) : Person(id) {
		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name); 
	}
	~Student() {
		cout << "name = " << name << endl;
		delete[] name;
	}
};

int main() {
	Person* p = new Student(10, "손연재");
	delete p;
}
----
1번문제
#include <iostream>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; //src를 다른 단위로 변경한다.
	virtual string getSourceString() = 0; //src 단위 명칭
	virtual string getDestString() = 0; // dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을" << getDestString() << "로 바꿉니다.";
		cout << getSourceString() << "을 입력하세요>>";
		cin >> src;
		cout << "변환 결과 :" << convert(src) << getDestString() << endl;
	}

};

//추상 클래스를 상속받는 파생 클래스 만들기
class WonToDollar : public Converter {
public:
	WonToDollar(double ratio = 0.0) : Converter(ratio) {}
	double convert(double src) { return src / ratio; }
	string getSourceString() { return "원"; }
	string getDestString() { return "달러"; }
};

int main() {
	WonToDollar wd(1010);
	wd.run();

	return 0;
}
-----
2번문제
#include <iostream>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; //src를 다른 단위로 변경한다.
	virtual string getSourceString() = 0; //src 단위 명칭
	virtual string getDestString() = 0; // dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << " 을" << getDestString() << " 로 바꿉니다.";
		cout << getSourceString() << "을 입력하세요>>";
		cin >> src;
		cout << "변환 결과 :" << convert(src) << getDestString() << endl;
	}

};

//추상 클래스를 상속받는 파생 클래스 만들기
class KmToMile : public Converter {
public:
	KmToMile(double ratio = 0.0) : Converter(ratio) {}
	double convert(double src) { return src / ratio; }
	string getSourceString() { return "KM"; }
	string getDestString() { return "Mile"; }
};

int main() {
	KmToMile toMile(1.609344);
	toMile.run();

	return 0;
}
--------
3번문제
#include <iostream>
using namespace std;

class LoopAdder { //추상 클래스
	string name;//루프 이름
	int x, y, sum; //x에서 y까지의 합은 sum
	void read(); //x,y 값을 읽어 들이는 함수
	void write(); // sum 을 출력하는 함수
protected:
	LoopAdder(string name = "") { //루프의 이름을 받는다. 초깃 값은 " "
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // 순수 가상 함수 루프를 돌며 합을 구하는 함수
public:
	void run(); //연산을 진행하는 함수
};
void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요>>";
	cin >> x >> y;
}

void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << "입니다." << endl;
}


void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}


class ForLoopAdder :public LoopAdder {
public:
	ForLoopAdder(string name="") : LoopAdder(name) { }
	int calculate() {
		int result = 0;
		for (int i = getX(); i <= getY(); i++) {
			result += i;
		}
		return result;
	}
};


int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();

	return 0;
}
-----
4번문제
#include <iostream>
using namespace std;

class LoopAdder { //추상 클래스
	string name;//루프 이름
	int x, y, sum; //x에서 y까지의 합은 sum
	void read(); //x,y 값을 읽어 들이는 함수
	void write(); // sum 을 출력하는 함수
protected:
	LoopAdder(string name = "") { //루프의 이름을 받는다. 초깃 값은 " "
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // 순수 가상 함수 루프를 돌며 합을 구하는 함수
public:
	void run(); //연산을 진행하는 함수
};
void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요>>";
	cin >> x >> y;
}

void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << "입니다." << endl;
}


void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}


class WhileLoopAdder :public LoopAdder {
public:
	WhileLoopAdder(string name = "") : LoopAdder(name) { }
	int calculate() {
		int result = 0;
		int i = getX();
		while(i<=getY()){
			result += i;
			i++;
		}
		return result;
	}
};

class DoWhileLoopAdder : public LoopAdder {
public:
	DoWhileLoopAdder(string name = " ") : LoopAdder(name) {}
	int calculate() {
		int result = 0;
		int i = getX();
		do {
			result += i;
			i++;
		} while (i <= getY());
		return result;
	}
};

int main() {
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do While Loop");

	whileLoop.run();
	doWhileLoop.run();

	return 0;
}

-----
5번문제
#include <iostream>
using namespace std;

class AbstractGate {  //추상 클래스
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0; //순수 가상 함수
};

class ANDGate : public AbstractGate {
public:
	bool operation() {
		return x & y;
	}
};

class ORGate : public AbstractGate {
public:
	bool operation() {
		return x | y;
	}
};

class XORGate : public AbstractGate {
public:
	bool operation() {
		return x ^ y;
	}
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);// bool 값을 "true", "false" 문자열로 출력할 것을 지시
	cout << andGate.operation() << endl; // AND 결과는 false;
	cout << orGate.operation() << endl; // OR 결과는 true;
	cout << xorGate.operation() << endl; // XOR 결과는 true;

	return 0;
}
-----
6번문제
#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack {
	int stack[5] = { 0 };
	int top = -1;
public:
	bool push(int n) {
		if (size() + 1 >= 5) {
			cout << "Stack is full" << endl;
			return false;
		}
		stack[++top] = n;
		return true;
	}
	bool pop(int& n) {
		if (size() < 0) {
			cout << "Stack is empty" << endl;
			return false;
		}
		n = stack[top--];
		return true;
	}
	int size() {
		return top;
	}
	void show() {
		cout << "|";
		for (int i = 0; i <= top; i++) {
			cout << stack[i] << ' ';
		}
		cout << "|" << endl;
	}
};

int main() {
	IntStack intStack;

	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);


	intStack.show();

	int n;
	intStack.pop(n);
	cout << n << " is popped" << endl;
	intStack.show();

	return 0;
}
-------
9번문제
#include <iostream>
using namespace std;

class Printer { //추상 클래스
	string model;// 모델
	string manufacturer; // 제조사
	int printedCount; //인쇄 매수
	int availableCount; // 인쇄 종이 잔량
protected:
	Printer(string mod = "", string manuf = "", int a = 0) {
		this->model = mod;
		this->manufacturer = manuf;
		this->availableCount = a;
		this->printedCount = 0;
	}
	bool isValidPrint(int pages) {
		if (availableCount > pages) return true;
		else return false;
	}

	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }

	void setModel(string model) { this->model = model; }
	void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
	void setPrintedCount(int printedCount) { this->printedCount = printedCount; }
	void setAvailableCount(int availableCount) { this->availableCount = availableCount; }

	virtual void print(int pages) = 0; //순수 가상 함수
	virtual void show() = 0; //순수 가상 함수
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mod = "", string manuf = "", int a = 0, int i = 0) : Printer(mod, manuf, a)
	{ this->availableInk = i; }

	bool isValidInkJetPrint(int pages) {
		if (availableInk > pages) return true;
		else return false;
	}
	int getAvailableInk() { return availableInk; }
	void setAvailableInk(int availableInk) { this->availableInk = availableInk; }

	void print(int pages) {
		if (isValidPrint(pages)) {
			if (isValidInkJetPrint(pages)) {
				setPrintedCount(getPrintedCount() + pages);
				setAvailableCount(getAvailableCount() - pages);
				setAvailableInk(getAvailableInk() - pages);
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void show() {
		cout << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 잉크 " << getAvailableInk() << endl;
	}

};


class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mod = "", string manuf = "", int a = 0, int t = 0) : Printer(mod, manuf, a)
	{ this->availableToner = t; }

	bool isValidLaserPrint(int pages) {
		if (availableToner > pages) return true;
		else return false;
	}

	int getAvailableToner() { return availableToner; }
	void setAvailableToner(int availableToner) { this->availableToner = availableToner; }

	void print(int pages) {
		if (isValidPrint(pages)) {
			if (isValidLaserPrint(pages)) {
				setPrintedCount(getPrintedCount() + pages);
				setAvailableCount(getAvailableCount() - pages);
				setAvailableToner(getAvailableToner() - pages);
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void show() {
		cout << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 토너 " << availableToner << endl;
	}

};

int main() {
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink->show();

	cout << "레이저 : ";
	laser->show();

	int printer, paper;
	char ch;

	while (true) {
		cout << endl << "프린터(1.잉크젯,2:레이저)와 매수 입력>>";
		cin >> printer >> paper;
		switch (printer) {
		case 1: ink->print(paper); break;
		case 2: laser->print(paper); break;
		default: break;
		}
		ink->show();
		laser->show();

		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		else continue;
	}


	return 0;
}
*/
