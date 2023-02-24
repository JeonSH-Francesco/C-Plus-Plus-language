#include <iostream>
using namespace std;

//추상 클래스를 상속받는 파생클래스는 그 목적에 따라 순수 가상 함수를 다양하게 구현한다.
//응용 프로그램의 설계와 구현을 분리할 수 있따.
//추상 클래스로 기본 방향을 잡아 놓고 파생 클래스를 목적에 따라 구현하면 작업이 쉬워진다.
//또한 추상 클래스는 계층적 상속 관계를 가진 클래스들의 구조를 만들 때 적합하다.

class Calculator { // 추상 클래스
	void input() {
		cout << "정수 2개를 입력하세요>>";
		cin >> a>>b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;//두 정수 합 리턴
public:
	void run() {
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};

class Adder :public Calculator {
protected:
	int calc(int a, int b) { // 순수 가상 함수 구현
		return a + b;
	}
};

class Subtractor :public Calculator {
protected:
	int calc(int a, int b) { // 순수 가상 함수 구현
		return a - b;
	}
};

int main() {
	Adder adder;
	Subtractor subtractor;

	adder.run();
	subtractor.run();
}




/*
#include <iostream>
using namespace std;

class Base {
public:
	void f() { cout << "Base::f() called"<<endl; }
};

class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};

void main() {
	Derived d, *pDer;
	pDer = &d; // 객체 d를 가리킨다.
	pDer->f(); //Derived의 멤버 f()호출->파생 클래스에 대한 포인터로는 파생 클래스의 함수를 호출

	Base* pBase;
	pBase = pDer;//업 캐스팅, 객체 d를 가리킨다.
	pBase->f();// Base의 멤버 f() 호출 ->기본 클래스에 대한 포인터로는 기본 클래스의 함수를 호출
}
//Base의 멤버 함수 f()와 완전히 동일한 멤버 함수f()를 Derived에서 재정의 하였다.
//상속에 있어 기본 클래스의 멤버 함수로 원하는 작업을 할 수 없는 경우
//파생 클래스에서 동일한 원형으로 그 함수를 재정의 하여 해결한다.
//이러한 호출 관계는 컴파일 시에 결정된다.(정적 바인딩)
------------------------
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	virtual void f() { cout << "Derived::f() called" << endl; }
};

void main() {
	Derived d, * pDer;
	pDer = &d; // 객체 d를 가리킨다.
	pDer->f(); //Derived::f()호출

	Base* pBase;
	pBase = pDer;//업 캐스팅, 객체 d를 가리킨다.
	pBase->f();// 동적 바인딩 발생!! Derived::f()실행

}
//파생 클래스에서 가상 함수를 오버라이딩 하고 기본 클래스의 포인터로 파생 클래스의 객체를 가리킬 때!
//가상 함수를 호출하면 무조건 파생 클래스에서 오버라이딩 한 가상함수가 호출 된다. -> 동적 바인딩!!!

//오버라이딩의 목적= 하나의 Interface에 대해 서로 다른 모양의 구현
//기본 클래스에 가상 함수를 만드는 목적은
//파생 클래스들이 자신의 목적에 맞게 가상 함수를 재정의 하도록 하는 것
//가상 함수는 객체지향 언어의 다형성을 실현하는 도구
------------
#include <iostream>
using namespace std;

class Shape {
public:
	void paint() {
		draw();
	}
	virtual void draw() {
		cout << "Shape::draw() called" << endl;
	}
};

class Circle :public Shape {
public:
	virtual void draw() {
		cout << "Circle::draw() called" << endl;
	}
};

int main() {
	Shape* pShape= new Shape();
	//Shape* pShape = new Circle(); // 기본 클래스에서 파생 클래스의 함수를 호출하는 사례 -> 동적 바인딩
	pShape->paint();
	delete pShape;
}

------------
#include <iostream>
using namespace std;


class Base {
public: virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public: void f() { cout << "Derived::f() called" << endl; }
};

class GrandDerived : public Derived {
public: void f() { cout << "GrandDerived::f() called" << endl; }
};

int main() {
	GrandDerived g;
	Base* bp;
	Derived* dp;
	GrandDerived* gp;

	bp = dp = gp = &g; // 모든 포인터가 객체 g를 가리킴

	bp->f(); // Base의 멤버 f() 호출
	dp->f(); // Derived의 멤버 f() 호출
	gp->f(); // GrandDerived의 멤버 f() 호출
	//동적 바인딩에 의해 모두 GrandDerived의 함수 f()호출
}
------
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() {
		cout << "-----Shape-----";
	}
};

class Circle : public Shape {
public:
	int x;
	virtual void draw() {
		Shape::draw(); // 기본 클래스의 draw() 호출
		cout << "Circle" << endl;
	}
};


int main() {
	Circle circle;
	Shape* pShape = &circle;

	pShape->draw(); // 동적 바인딩 발생. draw()가 virtual 이므로
	pShape->Shape::draw(); //정적 바인딩 발생. 범위 지정 연산자로 인해

}
-----
//범위 지정 연산자 예제 1 : 전역변수와 지역변수의 이름이 같은 경우
#include <iostream>
using namespace std;

int n = 11;

int main() {

	int n = 3;
	cout << "전역 변수 n =" << ::n << endl;
	cout << "지역 변수 n =" << n << endl;
}
-----
//범위 지정 연산자 예제 2 : 클래스의 멤버 함수와 외부 함수의 이름이 같은 경우
#include <iostream>
using namespace std;

void sendMessage(const char* msg) {
	cout << msg << endl;
}

class Window {
public:
	void sendMessage(const char* msg) {
		cout << "Window msg : " << msg << endl;
	}
	void run() {
		::sendMessage("Global Hello"); // 전역 함수 호출
		sendMessage("Local Hello"); // 지역 함수 호출
	}
};

int main() {
	Window window;
	window.run();
}
------
#include <iostream>
using namespace std;

//기본 클래스의 소멸자를 만들 때 가상 함수로 작성할 것을 권한다.
//이유 : 파생 클래스의 객체가 기본 클래스에 대한 포인터로 delete 되는 상황에서도 정상적인 소멸이 되기 위해서
//정리하면 소멸자를 가상함수로 선언하면, 객체를 기본 클래스의 포인터로 소멸하든, 파생 클래스의 포인터로 소멸하든
//파생클래스와 기본 클래스의 소멸자를 모두 실행하는 정상적인 소멸의 과정이 진행된다. virtual키워드 활용!!
class Base {
public:
	virtual ~Base() { cout << "~Base()" << endl; } // 동적 바인딩
};

class Derived : public Base {
public:
	virtual ~Derived() { cout << "~Derived()" << endl; }
};

int main() {
	Derived* dp = new Derived();
	Base* bp = new Derived();

	delete dp;// Derived의 포인터로 소멸
	delete bp; // Base의 포인터로 소멸
}
---------
//오버로딩: 매개변수의 타입이나 개수가 다른 함수들은 여러개 중복 작성하는 것이다.
//존재 : 클래스의 멤버들 사이, 외부 함수들 사이, 그리고 기본 클래스와 파생 클래스 사이에 존재 가능
//목적 : 이름이 같은 여러 개의 함수를 중복 작성하여 사용의 편의성 향상
//바인딩 : 정적 바인딩, 컴파일 시에 중복된 함수들의 호출 구분
//객체 지향 특성 : 컴파일 시간 다형성
//
//함수 재정의(가상 함수가 아닌 멤버에 대하여) : 기본 클래스의 멤버 함수를 파행 클래스에서
//이름, 매개변수 타입과 개수, 리턴 타입 까지 완벽히 같은 원형으로 재작성 하는것.
//존재 : 상속 관계
//목적 : 기본 클래스의 멤버 함수와 별도로 파생 클래스에서 필요하여 재작성
//바인딩 : 정적 바인딩.컴파일 시에 함수의 호출 구분
//객체 지향 특성 : 컴파일 시간 다형성
//
//오버라이딩 : 기본 클래스의 가상 함수를 파생 클래스에서 이름, 매개변수 타입과 개수,
//리턴 타입까지 완벽하게 같은 원형으로 재작성 하는 것.
//존재 : 상속 관계
//목적 : 기본 클래스에 구현된 가상 함수를 무시하고, 파생 클래스에서 새로운 기능으로 재작성 하고자 함.
//바인딩 : 동적 바인딩.실행 시간에 오버라이딩 된 함수를 찾아 실행
//객체 지향 특성 : 실행 시간 다형성



-------
#include <iostream>
using namespace std;

//추상 클래스 : 최소 하나의 순수 가상함수를 가진 클래스
class Calculator {
public:
	virtual int add(int a, int b) = 0; // 두 정수 합 리턴

	virtual int subtract(int a, int b) = 0; // 두 정수 차 리턴

	virtual double average(int a[], int size) = 0; //배열 a의 평균 리턴. size는 배열의 크기
};

// 추상 클래스 구현 :파생 클래스에 추상 클래스의 순수 가상 함수의 코드를 작성함.
class GoodCalc : public Calculator {
public:
	int add(int a, int b) { return a + b; }

	int subtract(int a, int b) { return a - b; }

	double average(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++) {
			sum += a[i];
		}
		return sum / size;
	}
};

int main() {
	int a[] = { 1,2,3,4,5 };
	Calculator* p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;
	delete p;
}
*/
