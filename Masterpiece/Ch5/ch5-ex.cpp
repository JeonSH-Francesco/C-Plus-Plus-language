
/*
#include <iostream>
using namespace std;

//매개변수 객체의 생성자는 실행되지 않고 소멸자만 실행 되도록 컴파일한다.
//->전달 받은 원본의 상태를 잃어버리기 때문.
//값에 의한 호출 시 컴파일러는 매개변수의 객체의 생성자 대신 복사 생성자가 호출되도록 컴파일하기 때문
//생성자가 실행 X
class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius= " << radius << endl;
}

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

int main() {
	Circle waffle(30); //waffle 생성
	increase(waffle);  // c 소멸 c의 생성자가 실행되지 않았음.
	cout << waffle.getRadius() << endl; // waffle 소멸
}
----------------------

#include <iostream>
using namespace std;

// 참조에 의한 호출의 장점
//1. 참조 매개변수로 이루어진 모든 연산은 원본 객체에 대한 연산이 된다.
//2. 참조 매개변수는 이름만 생성되므로, 생성자와 소멸자는 아예 실행되지 않는다.


class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius= " << radius << endl;
}

void increase(Circle& c) { //c는 참조 매개변수
	int r = c.getRadius();
	c.setRadius(r + 1); // c가 참조하는 원본 객체의 반지름 1 증가
}

int main() {
	Circle waffle(30); //waffle 생성
	increase(waffle);  // 참조에 의한 호출
	cout << waffle.getRadius() << endl; // waffle 소멸
}
-------
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}
	Circle(int radius) {
		this->radius = radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

Circle getCircle() {
	Circle tmp(30);
	return tmp;  // 객체 tmp 를 리턴한다.
}


int main() {
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle(); // tmp 객체가 c에 복사 c의 radius 는 30이 된다.
	cout << c.getArea() << endl;
}
--------
#include <iostream>
using namespace std;
//기본 타입 변수에 대한 참조
int main() {
	cout << "i " << '\t' << "n" << "\t" << "refn" << endl;
	int i = 1;
	int n = 2;
	int& refn = n; // 참조변수 refn 선언 refn은 n에 대한 별명
	n = 4;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;

	refn = i;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;

	int* p = &refn;
	*p = 20;
	cout << i << '\t' << n << '\t' << refn << endl;

}
-------
#include <iostream>
using namespace std;

//객체에 대한 참조

bool average(int a[], int size, int& avg) {
	if (size <= 0)
		return false;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	avg = sum / size; // 참조 매개변수 avg에 평균값 전달
	return true;
}

int main() {
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg)) cout << "평균은 " << avg << endl; // avg에는 평균이 넘어오고 average()는 true리턴
	else cout << "매개 변수 오류" << endl;

	if (average(x, -2, avg)) cout << "평균은 " << avg << endl; //avg의 값은 의미 없고, average()는 false 리턴
	else cout << "매개 변수 오류" << endl;
}
-------
#include <iostream>
using namespace std;

//참조 매개변수를 가진 함수 만들기

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}
	Circle(int radius) {
		this->radius = radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

void readRadius(Circle& c) {
	int r;
	cout << "정수 값으로 반지름을 입력하세요 >> ";
	cin >> r;
	c.setRadius(r); //반지름 설정
}

int main() {
	Circle donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}
------
#include <iostream>
using namespace std;

char& find(char s[], int index) {
	return s[index];
}

int main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S';
	cout << name << endl;

	char &ref = find(name, 2); // ref는 name[2]에 대한 참조
	ref = 't';
	cout << name << endl;

}
//char &, char*, char 사용에 대한 비교
//char c='a'; char * p= &c; char &s=c;
//기본 타입 변수가 c 가 생성되면 a가 저장되어 있고, 포인터 타입의 변수는 c의 주소를 가리키며
//참조변수 s는 이름만 생성되고 c를 가리킨다.
//이후, *p='b'; 하고 s='c'; 실행하면, c에는 문자 c가 들어있다.

//참조를 리턴하는 함수
//char c='a';
//char &r(){ return c;}
//r() ='c'; 변수 c = 'c'로 변경


//포인터를 리턴하는 함수
//char*p(){ return &c;} 변수 c의 주소 리턴
//char *s=p(); // s는 c의 주소 저장
//*s='b'; //s가 가치키는 변수 c='b'로 변경
//주의! p()='b'; 컴파일 오류 L-value에는 값이 올 수 없기 때문. L-value = R-value; 왼쪽에는 공간 오른쪽에는 값

-----------
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(const Circle& c);
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle(const Circle& c) {//복사 생성자 구현
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius = " << radius << endl;
}


int main() {
	Circle src(30); //src 객체의 보통 생성자 호출
	Circle dest(src); // dest 객체의 복사 생성자 호출

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}
--------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name); // 생성자
	Person(const Person& person); //복사 생성자
	~Person(); //소멸자
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) {//생성자
	this->id = id;
	int len = strlen(name);//name문자 개수
	this->name = new char[len+1];//name 문자열 공간 할당
	strcpy(this->name, name);//name에 문자열 복사
}

//깊은 복사 수행
Person::Person(const Person& person) { // 복사 생성자
	this->id = id; // id 값 복사
	int len = strlen(person.name); // name의 문자 개수
	this->name = new char[len + 1]; //name을 위한 공간 할당
	strcpy(this->name, person.name); //name의 문자열 복사
	cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}

Person::~Person() { // 소멸자
	if (name) //만일 name에 동적 할당된 배열이 있으면
		delete[] name; //동적 할당 메모리 소멸
}

void Person::changeName(const char* name) { // 이름 변경
	if (strlen(name) > strlen(this->name))
		return; // 현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
	strcpy(this->name, name);
}


int main() {
	Person father(1, "kitae"); // father 객체 생성
	Person daughter(father); // daughter 객체 복사 생성. 복사 생성자 호출

	cout << "daughter 객체 생성 직후 ====" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter의 이름을 Grace로 변경한 후====" << endl;
	father.show(); //father 객체 출력
	daughter.show(); //daughter 객체 출력

	return 0; //daughter, father 객체 소멸

}
----------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name); // 생성자
	Person(const Person& person); //복사 생성자
	~Person(); //소멸자
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) {//생성자
	this->id = id;
	int len = strlen(name);//name문자 개수
	this->name = new char[len + 1];//name 문자열 공간 할당
	strcpy(this->name, name);//name에 문자열 복사
}

//깊은 복사 수행
Person::Person(const Person& person) { // 복사 생성자
	this->id = id; // id 값 복사
	int len = strlen(person.name); // name의 문자 개수
	this->name = new char[len + 1]; //name을 위한 공간 할당
	strcpy(this->name, person.name); //name의 문자열 복사
	cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}

Person::~Person() { // 소멸자
	if (name) //만일 name에 동적 할당된 배열이 있으면
		delete[] name; //동적 할당 메모리 소멸
}

void Person::changeName(const char* name) { // 이름 변경
	if (strlen(name) > strlen(this->name))
		return; // 현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
	strcpy(this->name, name);
}

void f(Person person) {
	person.changeName("dummy"); // 값에 의한 호출로 객체가 전달될 때 person 객체의 복사 생성자 호출
}

Person g() {
	Person mother(2, "Jane");
	return mother; // 함수에서 객체를 return 할 때, mother 객체의 복사본 생성. 복사본의 복사 생성자 호출
}


int main() {
	Person father(1,"kitae");
	Person son = father; // 복사 생성자 호출
	f(father); // 복사 생성자 호출
	g(); // 복사 생성자 호출
}

*/
