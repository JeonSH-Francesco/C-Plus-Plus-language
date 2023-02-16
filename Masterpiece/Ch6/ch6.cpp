#include<iostream>
#include<string>
using namespace std;

class Trace {
public:
	static string tagInfo[100];
	static string debugInfo[100];
	static int count;
	static void put(string tag, string debug);
	static void print(string tag = "all");
};

int Trace::count = 0;
string Trace::tagInfo[100];
string Trace::debugInfo[100];

void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음"); // 디버깅 정보 저장
	c = a + b;
	Trace::put("f()", "합 계산"); // 디버깅 정보 저장
	cout << "합은 " << c << endl;
}

void Trace::put(string tag, string debug) {
	tagInfo[count] = tag;
	debugInfo[count] = debug;
	count++;
	//cout << "count : "<<count << endl; 
}

void Trace::print(string tag) {
	if (tag == "all") {
		cout << "----- 모든 Trace 정보를 출력합니다. -----\n";
		for (int i = 0; i < count; i++) {
			cout << tagInfo[i] << ":" << debugInfo[i] << endl;
		}
	}
	else {
		cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----\n";
		for (int i = 0; i < count; i++) {
			if (tagInfo[i] == tag) cout << tagInfo[i] << ":" << debugInfo[i] << endl;
		}
	}
}

int main() {
	Trace::put("main()", "프로그램을 시작합니다"); // 디버깅 정보 저장
	f();
	Trace::put("main()", "종료");    // put()의 첫 번째 매개 변수는 태그이고 두 번째 매개 변수는 디버깅 정보이다.
									  
	Trace::print("f()"); // "f()" 태그를 가진 디버깅 정보를 모두 출력한다.
	Trace::print(); // 모든 디버깅 정보를 출력한다.
}




/*
-----
1번문제
#include <iostream>
#include <string>

using namespace std;

int add(int* a, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return sum;
}

int add(int* a, int size, int* b) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i] + b[i];
	}
	return sum;
}


int add(int* a, int size, int* b = NULL) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	if (b != NULL) {
		for (int i = 0; i < size; i++) {
			sum += b[i];
		}
	}
	return sum;
}


int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
	return 0;
}
---------------
2번문제 2-1
#include <iostream>
#include <string>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	Person() { id = 1; name = "grace";  weight = 20.5;  }
	Person(int id, string name) { this->id = id; this->name=name; weight = 20.5;}
	Person(int id, string name, double weight) { this->id = id; this->name = name;  this->weight = weight;}
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

int main() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}
------
2번문제 2-2
#include <iostream>
#include <string>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	Person(int id = 1, string name = "Grace", double weight = 20.5);
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

Person::Person(int id, string name, double weight) {
	this->id = id;
	this->name = name;
	this->weight = weight;
}

int main() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
}
-----------
3번문제 3-1
#include <iostream>
using namespace std;

int big(int a, int b) {
	if (a > b && a<100) {
		return a;
	}
	else if (b > a && b < 100) {
		return b;
	}
	else if (a > b && a > 100) {
		return 100;
	}
	else if (b > a && b > 100) {
		return 100;
	}
}

int big(int a, int b,int c) {
	if (a > b && a > c) {
		return c;
	}
	else if (b > a && b > c) {
		return c;
	}

}

int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;

}

---------
3번문제 3-2
#include <iostream>
using namespace std;

int big(int a, int b, int c = 100) {
	return (a > b ? a : b) < c ? (a > b ? a : b) : c;
}
//a와 b가 c보다 작다는 전제하에
//a가 b보다 크면 return a, 아니면 return b
//a와 b가 c보다 작지 않다는 전제하에
//return c


int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
}
--------
4번문제
#include <iostream>
#include <string>

using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n, int val);
	~MyVector() { delete[] mem; }
	void show();
};

MyVector::MyVector(int n = 100, int val = 0) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++) mem[i] = val;
}
void MyVector::show() {
	for (int i = 0; i < size; i++) {
		cout << mem[i] << ' ';
	}
	cout << endl;
}

int main() {
	MyVector a, b(50, 1);
	a.show();
	b.show();

	return 0;
}
-----
5번문제
#include <iostream>
#include <string>
using namespace std;

class ArrayUtility{
public:
	static void intToDouble(int source[], double dest[], int size);
	static void doubleToInt(double source[], int dest[], int size);
};

void ArrayUtility::intToDouble(int source[], double dest[], int size) {
	for (int i = 0; i < size; i++) {
		dest[i] = (double)source[i];
	}
}

void ArrayUtility::doubleToInt(double source[], int dest[], int size) {
	for (int i = 0; i < size; i++) {
		dest[i] = (int)source[i];
	}
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double y[5];
	double z[] = { 9.9, 8.8, 7.7, 6.6, 5.6 };

	ArrayUtility::intToDouble(x, y, 5);
	for (int i = 0; i < 5; i++)cout << y[i] << ' ';
	cout << endl;

	ArrayUtility::doubleToInt(z, x, 5);
	for (int i = 0; i < 5; i++)cout << x[i] << ' ';
	cout << endl;
	return 0;
}

----------
6번문제
#include <iostream>
#include <string>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* ret = new int[size];
	int ind = 0;
	cout << "합친 정수 배열을 출력한다." << endl;
	for (int i = 0; i < size / 2; i++) {
		ret[ind] = s1[i];
		cout << ret[ind] << ' ';
	}
	for (int i = 0; i < size / 2; i++) {
		ret[ind] = s2[i];
		cout << ret[ind] << ' ';
	}
	return ret;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int cnt = 0;
	int* tmp = new int[size];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) break;
			if (j == size - 1) tmp[cnt++] = s1[i];
		}
	}

	if (cnt == 0) return NULL;

	retSize = cnt;
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	int* ret = new int[retSize];
	for (int i = 0; i < retSize; i++) {
		ret[i] = tmp[i];
		cout << ret[i] << ' ';
	}
	cout << endl;

	return ret;
}

int main() {
	int x[5], y[5], retSize;
	int* z, * w;

	cout << "정수를 5개 입력하라. 배열 x에 삽입한다>>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	cout << "정수를 5개 입력하라. 배열 y에 삽입한다>>";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}
	z = ArrayUtility2::concat(x, y, 10);
	w = ArrayUtility2::remove(x, y, 5, retSize);
	return 0;
}
------
7번문제
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();
};

int Random::nextInt(int min, int max) {
	return rand() % (max - min) + min;
}


char Random::nextAlphabet() {
	if (rand()%2 == 0) return rand() % 26 + 'a';
	else return rand() % 26 + 'A';
}

double Random::nextDouble() {
	return (double)rand() / RAND_MAX;
}

int main() {
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt(1, 100) << ' ';
	}
	cout << endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() << ' ';
	}
	cout << endl;

	cout << "랜덤한 실수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << ' ';
	}
	cout << endl;
	return 0;
}
------------
8번문제
#include<iostream>
#include<string>
using namespace std;

class Trace {
public:
	static string tagInfo[100];
	static string debugInfo[100];
	static int count;
	static void put(string tag, string debug);
	static void print(string tag = "all");
};

int Trace::count = 0;
string Trace::tagInfo[100];
string Trace::debugInfo[100];

void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음"); // 디버깅 정보 저장
	c = a + b;
	Trace::put("f()", "합 계산"); // 디버깅 정보 저장
	cout << "합은 " << c << endl;
}

void Trace::put(string tag, string debug) {
	tagInfo[count] = tag;
	debugInfo[count] = debug;
	count++;
	//cout << "count : "<<count << endl;
}

void Trace::print(string tag) {
	if (tag == "all") {
		cout << "----- 모든 Trace 정보를 출력합니다. -----\n";
		for (int i = 0; i < count; i++) {
			cout << tagInfo[i] << ":" << debugInfo[i] << endl;
		}
	}
	else {
		cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----\n";
		for (int i = 0; i < count; i++) {
			if (tagInfo[i] == tag) cout << tagInfo[i] << ":" << debugInfo[i] << endl;
		}
	}
}

int main() {
	Trace::put("main()", "프로그램을 시작합니다"); // 디버깅 정보 저장
	f();
	Trace::put("main()", "종료");    // put()의 첫 번째 매개 변수는 태그이고 두 번째 매개 변수는 디버깅 정보이다.

	Trace::print("f()"); // "f()" 태그를 가진 디버깅 정보를 모두 출력한다.
	Trace::print(); // 모든 디버깅 정보를 출력한다.
}


*/
