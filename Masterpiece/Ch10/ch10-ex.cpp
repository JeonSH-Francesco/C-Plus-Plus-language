
/*
#include <iostream>
using namespace std;

void myswap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void myswap(double& a, double& b) {
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 4, b = 5;
	myswap(a, b);
	cout << a << '\t' << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << c << '\t' << d << endl;

}
------
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class Tmyswap>
void myswap(Tmyswap& a, Tmyswap& b) {
	Tmyswap tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 4, b = 5;
	myswap(a, b);
	cout << a << '\t' << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << c << '\t' << d << endl;

	Circle donut(5), pizza(20);
	myswap(donut, pizza);
	cout << "donut 반지름= " << donut.getRadius() << ",";
	cout << "pizza 반지름= " << pizza.getRadius() << endl;

}
------
#include <iostream>
using namespace std;

template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}


int main() {
	int a =20, b = 50;
	char c = 'a', d = 'z';

	cout << "bigger(20,50)의 결과는 " << bigger(a, b) << endl;
	cout << "bigger(a,z)의 결과는 " << bigger(c, d) << endl;
}
--------
#include <iostream>
using namespace std;

template <class T> T add(T data[], int n) {
	T sum = 0;
	for (int i = 0; i < n; i++) {
		sum += data[i];
	}
	return sum;
}


int main() {
	int x[] = { 1,2,3,4,5 };
	double d[] = { 1.2,2.3,3.4,4.5,5.6,6.7 };

	cout << "sum of x[]= " << add(x, 5)<< endl;
	cout << "sum of d[]= " << add(d, 6) << endl;
}
------
#include <iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n) {
	for (int i = 0; i < n; i++) {
		dest[i] = (T2)src[i];
	}
} //copy()함수는 C++의 표준 라이브러리에 이미 있기 때문에 이름 충돌 회피 위해 mcopy 이용

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5];
	char c[5] = { 'H','e','l','l','o' }, e[5];

	mcopy(x, d, 5);
	mcopy(c, e, 5);

	for (int i = 0; i < 5; i++) {
		cout << d[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << e[i] << ' ';
	}
	cout << endl;
}
--------
#include <iostream>
using namespace std;

template<class T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << '\t';
	}
	cout << endl;
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5] = { 1.2,2.3,3.4,4.5,5.6 };
	print(x, 5);
	print(d, 5);

	char c[5] = { 1,2,3,4,5 };
	print(c, 5); //제네릭 타입 T 가 char 타입으로 구체화 되어 윈도우 OS 문자 코드표에 정의된 그래픽 문자를 출력한다.
}
--------
#include <iostream>
using namespace std;

template <class T>
void print(T array[],int n){
	for (int i = 0; i < n; i++)
		cout << array[i] << '\t';
	cout << endl;
}

void print(char array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << (int)array[i] << '\t';
	}
	cout << endl;
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5] = { 1.1,2.2,3.3,4.4,5.5 };
	print(x, 5);
	print(d, 5);

	char c[5] = { 1,2,3,4,5 };
	print(c, 5);
}
-----
#include <iostream>
using namespace std;

template <class T>
class MyStack {
	int tos; //top of stack
	T data[100]; // T 타입의 배열. 스택 크기는 100
public:
	MyStack();
	void push(T element); //T 타입원소 element data[] 배열에 삽입
	T pop(); //스택의 탑에 있는 데이터를 data[] 배열에서 리턴
};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack is full";
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "stack is empty";
		return 0; //오류 표시
	}
	retData = data[tos--];
	return retData;
}


int main() {
	MyStack<int> iStack; //int만 저장할 수 있는 스택
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack; //double만 저장할 수 있는 스택
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	MyStack<char>* p = new MyStack<char>(); //char만 저장할 수 있는 스택
	p->push('a');
	cout << p->pop() << endl;
	delete p;
}
------
#include <iostream>
using namespace std;

template <class T>
class MyStack {
	int tos;//top of stack
	T data[100];
public:
	MyStack();
	void push(T element); // T 타입원소 element data[] 배열에 삽입
	T pop(); // 스택의 탑에 있는 데이터를 data[] 배열에서 리턴
};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack is full";
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "stack is empty.";
		return 0; //오류 표시
	}
	retData = data[tos--];
	return retData;
}


class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() {
		cout << '(' << x << ',' << y << ')' << endl;
	}

};

int main(){

	MyStack<int*> ipStack; //int*만 저장하는 스택

	int* p = new int[3];
	for (int i = 0; i < 3; i++) {
		p[i] = i * 10;
	}
	ipStack.push(p);

	int* q = ipStack.pop();
	for (int i = 0; i < 3; i++) {
		cout << q[i] << ' ';
	}
	cout << endl;
	delete[]p;

	MyStack<Point> pointStack;
	Point a(2, 3), b;
	pointStack.push(a);
	b = pointStack.pop();
	b.show();

	MyStack<Point*> pStack;
	pStack.push(new Point(10, 20));

	Point* pPoint = pStack.pop();
	pPoint->show(); // Point 객체 출력

	MyStack<string> stringStack;
	string s = "C++";
	stringStack.push(s);
	stringStack.push("java");

	cout << stringStack.pop() << ' ';
	cout << stringStack.pop() << endl;
}
----------
#include <iostream>
using namespace std;

template <class T1,class T2> //두개의 제네릭 타입 선언
class GClass {
	T1 data1;
	T2 data2;
public:
	GClass();
	void set(T1 a, T2 b);
	void get(T1& a, T2& b); //data1을 a에 data2를 b에 리턴하는 함수
};


template <class T1,class T2>
GClass<T1, T2>::GClass() { //생성자
	data1 = 0;
	data2 = 0;
}


template <class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b) {
	data1 = a;
	data2=b;
}

template <class T1,class T2>
void GClass<T1, T2>::get(T1& a, T2& b) {
	a = data1;
	b = data2;
}

int main() {

	int a;
	double b;
	GClass<int, double> x;
	x.set(2, 0.5);
	x.get(a, b);
	cout << "a=" << a << '\t' << "b=" << b << endl;

	char c;
	float d;
	GClass<char, float> y;
	y.set('m', 12.5);
	y.get(c, d);
	cout << "c=" << c << '\t' << "d=" << d << endl;

}
----------
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it; //벡터 v의 원소에 대한 포인터 it 선언

	for (it = v.begin(); it != v.end(); it++) { //iterator를 이용하여 모든 원소 탐색
		int n = *it; //it가 가리키는 원소 값 리턴
		n = n * 2; //곱하기 2
		*it = n; // it가 가리키는 원소에 값 쓰기
	}

	for (it = v.begin(); it != v.end(); it++) { // 벡터 v의 모든 원소 출력
		cout << *it << ' ';
	}
	cout << endl;
}
------
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

	map<string, string> dic;

	dic.insert(make_pair("love", "사랑")); //("love","사랑") 저장
	dic.insert(make_pair("apple", "사과"));//("apple","사과") 저장
	dic["cherry"] = "체리";//("cherry","체리") 저장

	cout << "저장된 단어 개수 = " << dic.size() << endl;

	string eng;

	while (true) {
		cout << "찾고 싶은 단어>>";
		getline(cin, eng); // 사용자로부터 키 입력
		if (eng == "exit")
			break;

		if (dic.find(eng) == dic.end())
			cout << "없음" << endl;
		else
			cout << dic[eng] << endl;
	}

	cout << "종료합니다..." << endl;
}
-----
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<int> v; //정수 벡터 생성

	cout << "5개의 정수를 입력하세요 >> ";
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	//v.begin()에서 v.end()사이의 값을 오름차순으로 정렬
	//sort()함수의 실행 결과 벡터 v의 원소 순서가 변경됨.
	sort(v.begin(), v.end()); //vector sorting

	vector<int>::iterator it; //벡터 내의 원소를 탐색하는 iterator 변수 선언

	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}

	cout << endl;

}
------
#include <iostream>
using namespace std;

int main() {
	[](int x, int y) {cout << "합은 " << x + y; }(2, 3);//람다식 실행
}
--------
#include <iostream>
#include <string>
using namespace std;

int main() {
	auto love = [](string a, string b) {
		cout << a << "보다 " << b << "가 좋아" << endl;
	};

	love("돈", "너");
	love("냉면", "만두");
}
-------
#include <iostream>
using namespace std;

int main() {
	double pi = 3.14; //지역 변수

	auto calc = [pi](int r)->double {return pi * r * r; };

	cout << "면적은" << calc(3);
	//캡쳐 리스트와 리턴 타입을 가지는 람다식 만들기

}
-----
#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	[&sum](int x, int y) {sum = x + y; }(2, 3); //합 5를 지역 변수 sum에 저장

	cout << "합은 " << sum;

}
----
#include <iostream>
#include <vector>
#include <algorithm> //for_each() 알고리즘 함수를 사용하기 위함
using namespace std;

void print(int n) {
	cout << n << " ";
}

int main() {
	vector <int> v = { 1,2,3,4,5 };

	//for_each()는 벡터 v의 첫번째 원소(v.begin())부터 끝(v.end())까지 검색하면서,
	//각 원소에 대해 3번째 매개변수인 print(int n) 호출. 매개변수 n에 각 원소 값 전달
	for_each(v.begin(), v.end(),print);
}
-------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v = { 1,2,3,4,5 };

	for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });

}


*/
