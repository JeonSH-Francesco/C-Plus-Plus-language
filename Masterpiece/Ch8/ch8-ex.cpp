
/*

#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {// 2차원 평면에서 컬러 점을 표현하는 클래스 ColorPoint. Point 를 상속받음
	string color; // 점의 색 표현
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

int main() {
	Point p; //기본 클래스의 객체 생성
	ColorPoint cp; // 파생 클래스 객체 생성
	cp.set(3, 4);// 기본 클래스 멤버 호출
	cp.setColor("Red"); // 파생 클래스 멤버 호출
	cp.showColorPoint(); // 파생 클래스 멤버 호출
}
----------
#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {// 2차원 평면에서 컬러 점을 표현하는 클래스 ColorPoint. Point 를 상속받음
	string color; // 점의 색 표현
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

//업 캐스팅이란 파생 클래스의 객체를 기본 클래스의 포인터로 가리키는 것

int main() {
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer; //업 캐스팅
	//업 캐스팅한 기본 클래스의 포인터로는 기본 클래스의 멤버만 접근할 수 있다.
	//업 캐스팅 시 다음과 같이 명시적 타입 변환이 필요 없다.
	//Point *pBase = (Point*)pDer; (Point*) 생략 가능

	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();
}
----------
#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {// 2차원 평면에서 컬러 점을 표현하는 클래스 ColorPoint. Point 를 상속받음
	string color; // 점의 색 표현
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

//업 캐스팅이란 파생 클래스의 객체를 기본 클래스의 포인터로 가리키는 것
//반대로 다운 캐스팅이란 기본 클래스 포인터가 가리키는 객체를 파생 클래스의 포인터로 가리키는 것

int main() {
	ColorPoint cp;
	ColorPoint* pDer;
	Point* pBase = &cp; //업 캐스팅

	pBase->set(3, 4);
	pBase->showPoint();

	pDer = (ColorPoint*)pBase; //다운 캐스팅->강제 타입 변환 반드시 필요
	pDer->setColor("Red");
	pDer->showColorPoint();
}
-----
#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
	int x, y; // 한점 (x,y) 좌표 값
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
	bool equals(ColorPoint p);
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint(); // Point 클래스의 showPoint()호출
}

bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color) //Point 클래스의 x,y는 protected 멤버이므로 파생 클래스인
		//ColorPoint에서도 접근 가능
		return true;
	else
		return false;
}

int main() {
	Point p; // 기본 클래스의 객체 생성
	p.set(2, 3); //public 멤버 접근 가능
	p.x = 5;
	p.y = 5;
	p.showPoint();

	ColorPoint cp;
	cp.x = 10;
	cp.y = 10;
	//protected 멤버에 접근 불가능 한 부분은 오류 발생
	cp.set(3, 4);
	cp.setColor("Red");

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "true" : "false"); //상속받은 클래스에서는 오류 발생하지 않음.
}
-----------
#include <iostream>
#include <string>
using namespace std;


class TV {
	int size;//스크린 크기
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};


class WideTV : public TV {
	bool videoIn;
public:
	WideTV(int size, bool videoIn) : TV(size) {
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};

class SmartTV : public WideTV {
	string ipAddr;
public:
	SmartTV(string ipAddr, int size) : WideTV(size, true) {
		this->ipAddr = ipAddr;
	}
	string getIpAddr() { return ipAddr; }
};


int main() {
	//32 인치 크기에 "192.0.0.1"의 인터넷 주소를 가지는 스마트 TV 객체 생성
	SmartTV htv("192.0.0.1", 32);
	cout << "size=" << htv.getSize() << endl;
	cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
	cout << "ipAddr=" << htv.getIpAddr() << endl;

}
----------
#include <iostream>
using namespace std;

class Adder {
protected:
	int add(int a, int b) { return a + b; }
};

class Subtractor {
protected:
	int minus(int a, int b) { return a - b; }
};

class Calculator : public Adder, public Subtractor {
public:
	int calc(int a, char op, int b);
};

int Calculator::calc(int a, char op, int b) {
	int res = 0;
	switch (op) {
	case '+': res = add(a, b); break;
	case '-': res = minus(a, b); break;
	}
	return res;
}


int main() {
	Calculator cc;
	cout << "2+4=" << cc.calc(2, '+', 4) << endl;
	cout << "100-8=" << cc.calc(100, '-', 8) << endl;
}


*/
