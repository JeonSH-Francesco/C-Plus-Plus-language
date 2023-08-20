#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Word {
	string english;
	string korean;
public:
	Word(string eng, string kor) : english(eng), korean(kor) {}
	string getEng() const { return english; }
	string getKor() const { return korean; }
};

int main() {
	srand(static_cast<unsigned>(time(0)));
	cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다." << endl;

	vector<Word> v = {
		{"human", "인간"},
		{"baby", "아기"},
		{"society", "사회"},
		{"photo", "사진"},
		{"painting", "그림"},
		{"love", "사랑"},
		{"emotion", "감정"},
		{"doll", "인형"},
		{"animal", "동물"},
		{"bear", "곰"},
		{"trade", "거래"}
	};

	while (true) {
		int index = rand() % v.size();
		const string correctAnswer = v[index].getKor();

		vector<string> options;
		options.push_back(correctAnswer);

		while (options.size() < 4) {
			int randomIndex = rand() % v.size();
			const string newOption = v[randomIndex].getKor();

			if (newOption != correctAnswer && find(options.begin(), options.end(), newOption) == options.end()) {
				//조건 1 : 새로운 보기 newOption은 정답 correctAnswer과 달라야 한다.
				//이를 통해 같은 정답을 여러 번 보기로 제시하지 않도록 합니다.
				//조건 2 : 새로운 보기는 이미 options 벡터에 존재하지 않아야 한다.
				//중복된 보기를 피하기 위한 조건입니다.
		
				options.push_back(newOption);
				//위 두조건이 만족하는 경우에만. options 벡터에 추가한다.
			}
		}

		random_shuffle(options.begin(), options.end());

		cout << v[index].getEng() << "?" << endl;
		for (int i = 0; i < 4; ++i) {
			cout << "(" << i + 1 << ") " << options[i] << ' ';
		}

		cout << ":>";
		int answer;
		cin >> answer;

		if (answer >= 1 && answer <= 4) {
			if (options[answer - 1] == correctAnswer) {
				cout << "Excellent !!" << endl;
			}
			else {
				cout << "No. !!" << endl;
			}
		}
		else {
			break;
		}
	}

	return 0;
}
/*
------
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int countstack = 0, numCount = 0;
	char buf[10000];

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다."<<endl;
	cout << "텍스트의 끝은 ;입니다. 10000개까지 가능합니다." << endl;

	cin.getline(buf, 1000, ';');

	for (int i = 0; i < strlen(buf); i++) {
		if (isalpha(buf[i]) != 0) {
			buf[i] = tolower(buf[i]);
			numCount++;
		}
	}

	cout << "총 알파벳 수 " << numCount << endl;

	for (char i = 'a'; i <= 'z'; i++)
	{
		for (int j = 0; j <= strlen(buf); j++) {
			if (buf[j] == i)
				countstack++;
		}
		cout << i << "(" << countstack << ")" << ":";

		for (int k = 0; k < countstack; k++)
			cout << "*";
		cout << endl;
		countstack = 0;
	}

}

------
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
-----
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
--------
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
	getline(cin, s, '\n');
	int sum = 0;
	int startIndex = 0;

	while (true) {
		int fIndex = s.find('+', startIndex);
		if (fIndex == -1) { // +문자를 처음부터 다 찾은 경우 즉, 마지막인 경우
			string part = s.substr(startIndex); // part를 통해 나머지 출력
			if (part == "") break; //2+3+와 같이 +로 끝난 경우
			cout << part << endl;
			sum += stoi(part);
			break;
		}
		//그 외의 66+2+8+55+100에서 66+2+8 ~ 중간 중간 찾고 있는 과정일 경우
		int count = fIndex - startIndex; //자릿수 체크
		string part = s.substr(startIndex,count); // startIndex 즉, fIndex+1(+찾은 후) 다음부터 찾는 것이므로 startIndex부터 count만큼 자르고
		cout << part << endl;//part로 출력하고
		sum += stoi(part);//합 계산하고
		startIndex = fIndex + 1; // part 자른 다음부터 찾도록 초기화 과정을 하고
	}

	cout << "숫자들의 합은 "<<sum << endl;

}
--------
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int cnt = 0, ind = 0;

	cout << "문자열 입력 >> ";
	getline(cin, str);

	while (true) {
		ind = str.find('a', ind+1);
		if (ind == -1) break;
		else cnt++;
	}
	cout << "문자 a 의 개수는" <<cnt<< "개 있습니다." << endl;
	return 0;
}

--------
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "여러 줄의 문자열 입력하세요. 입력의 끝은 &문자입니다." << endl;
	getline(cin, s, '&'); // 문자열 입력
	cin.ignore(); // &뒤에 따라오는 <Enter>키 제거하는 코드

	string f, r;
	cout << endl << "find: ";
	getline(cin, f, '\n');

	cout << "replace: ";
	getline(cin, r, '\n');

	int startIndex = 0;
	while (true) {
		int fIndex = s.find(f, startIndex);
		if (fIndex == -1) break;

		s.replace(fIndex, f.length(), r);
		startIndex = fIndex + r.length();
	}
	cout << s << endl;
}
--------
#include <iostream>
#include <string>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n;
		p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	cout << "10개의 정수를 입력하세요 : ";
	for (int i = 0; i < size; i++) {
		cin >> p[i];
	}
}

void Sample::write() {
	cout << "10개의 정수를 출력합니다." << endl;
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
	}
}

int Sample::big() {
	int max=0;
	for (int i = 0; i < size; i++) {
		if (p[i] > max)
			max = p[i];
	}
	return max;
}

Sample::~Sample() {
	delete[] p;
}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout <<endl<<"가장 큰 수는 " << s.big()<<endl;
}
--------
#include <iostream>
#include <string>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; }
	void consume() { size = size - 1; }
	int getSize() { return size; }
};


class CoffeeVendingMachine {
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
public:
	void run();
};

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++)
		tong[i].fill();
	show();
}

void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 1) {
		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소 드세요" << endl;
	}
	else {
		cout << "원료가 부족합니다" << endl;
	}
}

void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2) {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "아메리카노 드세요" << endl;
	}
	else {
		cout << "원료가 부족합니다" << endl;
	}
}

void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2 && tong[2].getSize() >= 1) {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "설탕커피 드세요" << endl;
	}
	else {
		cout << "원료가 부족합니다" << endl;
	}
}


void CoffeeVendingMachine::run() {
	cout << "***** 커피자판기를 작동합니다. *****" << endl;

	while (true) {
		int num;
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>>)";
		cin >> num;

		switch (num) {
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		default:
			break;
		}
	}
}

int main() {
	CoffeeVendingMachine coffeeVendingMachine;
	coffeeVendingMachine.run();
	return 0;
}
--------
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Histogram {
	string str;
	int alphabet[26] = { 0 };
public:
	Histogram(string str) { this->str = str; }
	void put(string new_str) { this->str.append(new_str); }
	void putc(char ch) { this->str.append(&ch); }
	void print();
	int getAlphabetSize();
	void countAlphabet();
};

void Histogram::print() {
	cout << str << endl << endl;
	cout << "총 알파벳 수 " << getAlphabetSize() << endl << endl;

	countAlphabet();

	char ch = 'a';


	while (ch <= 'z') {
		cout << ch << " (" << alphabet[(int)ch - 'a'] << ")\t: ";

		for (int i = 0; i < alphabet[(int)ch - 'a']; i++) {
			cout << "*";
		}

		cout << endl;
		ch++;
	}

}

int Histogram::getAlphabetSize() {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			cnt++;
		}
	}
	return cnt;
}


void Histogram::countAlphabet() {
	for (int i = 0; i < str.length(); i++) {

		if (str[i] >= 'A' && str[i] <= 'Z') {
			int ind = str[i] - 'A';
			alphabet[ind]++;
		}

		if (str[i] >= 'a' && str[i] <= 'z') {
			int ind = str[i] - 'a';
			alphabet[ind]++;
		}

	}
}

int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();

	return 0;
}
-----
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { this->radius = r; }
	void show() { cout << "반지름 = " << radius << endl; }
};

void swap(Circle& a, Circle& b) {
	Circle tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	Circle a(1), b(2);
	cout << "before swap" << endl;
	a.show();
	b.show();
	cout << endl;

	cout << "after swap" << endl;
	swap(a, b);
	a.show();
	b.show();
	return 0;
}
-----
#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];
	int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack();
	bool push(int n); // 정수 n 푸시, 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 팝 하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
};
MyIntStack::MyIntStack() {
	tos = 0;
}

bool MyIntStack::push(int n) {
	if (tos == 10)
		return false;

	p[tos] = n;
	tos++;
	return true;
}

bool MyIntStack::pop(int& n) {
	if (tos == 0)
		return false;

	tos--;
	n = p[tos];
	return true;
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' '; //푸시된 값 에코
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' '; //팝 한 값 출력
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}
-----
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Person {
	string s[2];
	int n;
public:
	Person() {
		s[0] = "김인수";
		s[1] = "오은경";
		n = -1;
	}
	string getName() {
		n++;
		if (n == 2) {
			n = 0;
			return s[n];
		}
		else {
			return s[n];
		}
	}
};


class UpAndDownGame {
	static int result; // 랜덤 수
	static int start, end; // 시작과 끝
public:
	UpAndDownGame() { srand((unsigned)time(0)); }
	static void game();
};

int UpAndDownGame::result = 0;
int UpAndDownGame::start = 0;
int UpAndDownGame::end = 99;

void UpAndDownGame::game() {
	int number;
	Person p;
	cout << "Up & Down 게임을 시작합니다." << endl;
	result = rand() % 100;
	while (1) {
		string name = p.getName();
		cout << "답은" << start << "과" << end << "사이에 있습니다." << endl;
		cout << name << ">>";
		cin >> number;

	if (number > result) {
		end = number;
	}
	else if (number < result) {
		start = number;
	}
	else {
		cout << name << "이겼습니다." << endl;
		break;
	}

	}
}





int main() {
	UpAndDownGame gamestart;
	gamestart.game();

}

--------
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
	if (rand() % 2 == 0) return rand() % 26 + 'a';
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
----
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick;  this->punch = punch; }
	void show();
	friend Power& operator++(Power& op);
	friend Power operator++(Power& op, int x);
};

void Power::show() {
	cout << "kick : " << kick << ',' << "punch :" << punch << endl;
}

Power& operator++(Power& op) {
	op.kick++;
	op.punch++;
	return op;
}

Power operator++(Power& op, int x) {
	Power tmp=op;
	op.kick++;
	op.punch++;
	return tmp;
}
int main() {
	Power a(3, 5), b;
	b = ++a; // 전위 ++연산자
	a.show(); b.show();

	b = a++; //후위 ++연산자
	a.show(); b.show();
}

-----
#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text; //문자열
	int alpha[26] = { 0 }; // 각 알파벳 갯수 배열
public:
	Histogram(string text) { this->text = text; }
	Histogram& operator<<(string text);
	Histogram& operator<<(char c);
	void operator!();
};

Histogram& Histogram::operator<<(string text) {
	this->text += text;
	return *this;
}
Histogram& Histogram::operator<<(char c) {
	this->text += c;
	return *this;
}

void Histogram::operator!() {
	int count = 0; // 전체 알파벳 수
	char c;
	for (int i = 0; i < text.length(); i++) {
		c = text[i];
		if (isalpha(c) != 0) { // 만약 c가 알파벳 이라면
			c = tolower(text[i]); // 소문자로 변환 후
			alpha[(int)c - 97]++; // 해당 알파벳의 수 ++시키고
			count++; // 전체 알파벳 수도 ++시킨다.
		}
	}
	cout << text << endl << endl;
	cout << "총 알파벳 수" << count << endl;

	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 97) << ":";
		for (int j = 0; j < alpha[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
}


int main() {
	Histogram song("Wise men say,\nonly fools rush in But I can't help, \n");
	song << "falling" << "in love with you." << "- by "; //히스토그램에 문자열 추가
	song << 'k' << 'i' << 't'; //히스토 그램에 문자 추가
	!song; //히스토 그램 그리기


}
-------------
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x;}
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};


class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x=0, int y=0, string color = "BLACK") : Point(x, y) { this->color = color; }

	void setPoint(int x, int y) { move(x,y); }
	void setColor(string color) { this->color = color; }
	void show() { cout << color << "색으로" << "("<<getX()<<","<< getY()<<")" << "위치한 점입니다."<<endl; }
};

int main() {
	ColorPoint zeropoint;
	zeropoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10,20);
	cp.setColor("Blue");
	cp.show();
}



------------
#include <iostream>
using namespace std;

class BaseArray {
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() {
		delete[] mem;
	}

	void put(int index,int val) {
		mem[index] = val;
	}

	int get(int index) {
		return mem[index];
	}

	int getCapacity() {
		return capacity;
	}

};


class MyQueue : public BaseArray {
	int start, end;
public:
	MyQueue(int capacity) : BaseArray(capacity) {
		start = 0; end = 0;
	}

	int capacity() {
		return getCapacity();
	}

	int length() {
		return end - start;
	}

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

-------------------------------
#include <iostream>
using namespace std;

class BaseArray {
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() {
		delete[] mem;
	}

	void put(int index,int val) {
		mem[index] = val;
	}

	int get(int index) {
		return mem[index];
	}

	int getCapacity() {
		return capacity;
	}

};


class MyStack : public BaseArray {
	int top;
public:
	MyStack(int capacity) :BaseArray(capacity) {
		top = -1;
	}
	int capacity() {
		return getCapacity();
	}
	int length() {
		return top + 1;
	}
	void push(int n) {
		put(++top, n);
	}
	int pop() {
		return get(top--);
	}

};


int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라 >> ";

	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}

	cout << "스택 용량 :" << mStack.capacity() << "스택 크기 " << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다.>>";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}

	cout << endl << "스택의 현재 크기 : " << mStack.length()<<endl;
}

----
#include <iostream>
using namespace std;

class BaseMemory {
	char* mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	void setData(char x, int length) { mem[length] = x; }
	void setData(char x[], int length) {
		for (int i = 0; i < length; i++) {
			mem[i] = x[i];
		}
	}
	char getData(int index) {
		return mem[index];
	}
};

class ROM : public BaseMemory {
public:
	ROM(int size, char x[], int length) : BaseMemory(size) {
		setData(x,length);
	}
	char read(int index) {
		return getData(index);
	}
};


class RAM : public BaseMemory {
public:
	RAM(int size) : BaseMemory(size) {}
	void write(int index, char data) { setData(data, index); }
	char read(int index) { return getData(index); }
};


int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5); //10KB의 ROM 메모리. 배열 x로 초기화 됨
	RAM mainMemory(1024 * 1024); // 1MB의 RAM 메모리

	//0~4번지까지 biosRom에서 읽어 mainMemory에 복사
	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
	return 0;
}
-----
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

-------
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
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }
	void setModel(string model) { this->model = model; }
	void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
	void setPrintedCount(int printedCount) { this->printedCount = printedCount; }
	void setAvailableCount(int availableCount) { this->availableCount = availableCount; }

	virtual void print(int pages) = 0;
	virtual void show() = 0;
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0) : Printer(mo, me, a) { this->availableInk = i; }
	bool isValidInkJetPrint(int pages) {
		if (availableInk > pages) return true;
		else return false;
	}
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
	int getAvailableInk() { return availableInk; }
	void setAvailableInk(int availableInk) { this->availableInk = availableInk; }
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0) : Printer(mo, me, a) { this->availableToner = t; }
	bool isValidLaserPrint(int pages) {
		if (availableToner > pages) return true;
		else return false;
	}
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
	int getAvailableToner() { return availableToner; }
	void setAvailableToner(int availableToner) { this->availableToner = availableToner; }
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
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> paper;
		switch (printer) {
		case 1: ink->print(paper); break;
		case 2: laser->print(paper); break;
		default: break;
		}
		ink->show();
		laser->show();

		cout << "게속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		else continue;
	}

	return 0;
}
----------
#include <iostream>
using namespace std;

//순수 가상 함수 : 함수의 코드는 없고, 선언만 있는 가상 함수
//추상 클래스 : 최소 하나의 순수 가상 함수를 가진 클래스
class Shape {
	Shape* next; // 추상 클래스의 포인터 선언
protected:
	virtual void draw() = 0; //순수 가상 함수
public:
	Shape() { next = NULL; }
	virtual ~Shape(){}

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
----------
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << '\t';
	}
	cout << endl;
}

void print(char array[],int n) {
	for (int i = 0; i < n; i++)
		cout << (int)array[i] << '\t';
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
-------
#include <iostream>
using namespace std;

template <class T>
T add(T data[],int n){
	T sum = 0;
	for (int i = 0; i < n; i++) {
		sum += data[i];
	}
	return sum;
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[]={1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

	cout << "sum of x[]=" << add(x, 5) << endl;
	cout << "sum of d[]=" << add(d, 6) << endl;
}
------------
#include <iostream>
using namespace std;

template <class T1,class T2>
void mcopy(T1 src[], T2 dst[], int n) {
	for (int i = 0; i < n; i++) {
		dst[i] = (T2)src[i];
	}
}

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
}
----
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << '\t';
	}
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
--------
#include <iostream>
using namespace std;

template<class T>
class MyStack {
	int tos;
	T data[100];
public:
	MyStack();
	void push(T element);
	T pop();
};


template <class T>
MyStack<T>::MyStack() { // 생성자
	tos = -1; // 스택은 비어있음
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full";
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "stack empty";
		return 0;
	}
	retData = data[tos--];
	return retData;
}


int main() {
	MyStack<int> iStack;
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack;
	dStack.push(3.5);
	cout << dStack.pop() << endl;

	MyStack<char>* p = new MyStack<char>();
	p->push('a');
	cout << p->pop() << endl;
	delete p;
}
-------
//제네릭 스택의 제네릭 타입을 포인터나 클래스로 구체화 하는 예
#include <iostream>
#include <string>
using namespace std;


template<class T>
class MyStack {
	int tos;
	T data[100];
public:
	MyStack();
	void push(T element);
	T pop();
};


template <class T>
MyStack<T>::MyStack() { // 생성자
	tos = -1; // 스택은 비어있음
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full";
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "stack empty";
		return 0;
	}
	retData = data[tos--];
	return retData;
}

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() { cout << '(' << x << ',' << y << ')'<<endl; }
};

int main() {
	MyStack<int*> ipStack; //int *만 저장하는 스택
	int* p = new int[3];
	for (int i = 0; i < 3; i++) {
		p[i] = i * 10;
	}
	ipStack.push(p);
	int* q = ipStack.pop();
	for(int j = 0; j < 3; j++) {
		cout << q[j] << ' ';
	}
	cout << endl;

	delete[] p;

	MyStack<Point> pointStack;//Point만 저장하는 스택
	Point a(2, 3), b;
	pointStack.push(a); // Point 객체 push
	b = pointStack.pop();//Point 객체 pop
	b.show(); //Point 객체 출력

	MyStack<Point*> pStack;
	pStack.push(new Point(10, 20));
	Point* pPoint = pStack.pop();
	pPoint->show();

	MyStack<string> stringStack;
	string s = "c++";
	stringStack.push(s);
	stringStack.push("java");
	cout << stringStack.pop() << ' ';
	cout << stringStack.pop() << endl;

}
--------
#include <iostream>
#include <vector>
using namespace std;

int main() {

	// 빈 vector 생성
	vector<int> myVector;

	// push_back을 사용하여 요소 추가
	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);

	// begin()과 end()를 사용하여 벡터의 요소 순회
	cout << "Vector elements: ";
	for (auto it = myVector.begin(); it != myVector.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// empty()를 사용하여 벡터가 비어있는지 확인
	if (myVector.empty()) {
		cout << "Vector is empty." << endl;
	}
	else {
		cout << "Vector size: " << myVector.size() << endl;

		// operator[]를 사용하여 특정 인덱스의 요소에 접근
		cout << "Element at index 1: " << myVector[1] << endl;

		// at()을 사용하여 특정 인덱스의 요소에 접근
		cout << "Element at index 2: " << myVector.at(2) << endl;

		// erase()를 사용하여 특정 인덱스의 요소 제거
		myVector.erase(myVector.begin() + 1); // 두 번째 요소 제거

		// insert()를 사용하여 특정 인덱스에 요소 삽입
		myVector.insert(myVector.begin() + 1, 50); // 두 번째 위치에 50 삽입

		// operator=()를 사용하여 다른 vector로 복사
		vector<int> anotherVector = myVector;

		// 두 번째 vector 출력
		cout << "Copied vector elements: ";
		for (int num : anotherVector) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}
----
#include <iostream>
#include <map>
using namespace std;

int main() {

	// 빈 map 생성
	map<string, int> myMap;

	// insert()를 사용하여 키-값 쌍 추가
	myMap.insert(make_pair("one", 1));
	myMap.insert(make_pair("two", 2));
	myMap.insert(make_pair("three", 3));

	// begin()과 end()를 사용하여 map의 요소 순회
	cout << "Map elements: ";
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		cout << "(" << it->first << ":" << it->second << ") ";
	}
	cout << endl;

	// empty()를 사용하여 map이 비어있는지 확인
	if (myMap.empty()) {
		cout << "Map is empty." << endl;
	}

	else {
		cout << "Map size: " << myMap.size() << endl;

		// operator[]를 사용하여 특정 키의 값을 접근
		cout << "Value for key 'two': " << myMap["two"] << endl;

		// find()를 사용하여 특정 키를 검색
		auto found = myMap.find("three");
		if (found != myMap.end()) {
			cout << "Key 'three' found. Value: " << found->second << endl;
		}

		// erase()를 사용하여 특정 키의 요소 제거
		myMap.erase("two");

		// insert()를 사용하여 키-값 쌍 추가 (또 다른 방법)
		myMap["four"] = 4;

		// operator=()를 사용하여 다른 map으로 복사
		map<string, int> anotherMap = myMap;

		// 두 번째 map 출력
		cout << "Copied map elements: ";
		for (const auto& pair : anotherMap) {
			cout << "(" << pair.first << ":" << pair.second << ") ";
		}
		cout << endl;
	}

	return 0;
}
----------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;

	cout << "5개의 정수를 입력하세요:";
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());

	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

}
----
#include <iostream>
using namespace std;

int main() {
	double pi = 3.14;
	auto calc = [pi](int r)->double { return pi * r * r; };
	cout << "반지름이 3인 원의 면적은" << calc(3);

}

--------
#include <iostream>
using namespace std;

int main() {
	int sum = 0;

	[&sum](int x, int y) { sum = x + y; }(2, 3);

	cout << "합은 " << sum;
}
-----
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int n) {
	cout << n << " ";
}

int main() {
	vector<int> v = { 1,2,3,4,5 };

	for_each(v.begin(), v.end(), print);
}
----
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5 };

	for_each(v.begin(), v.end(),[](int n){cout << n << " ";});
}
----
C++에서 람다식의 의미
C++ 프로그램 작성 시 람다가 꼭 필요한 기능은 아니다. 다만 간단하고, 짧게 최적화 된 코드를 작성하는데 도움이 된다.
특별히 람다가 유용한 경우는 다음과 같다.

한 번만 호출하고 재사용하지 않기 때문에, 함수에 이름을 붙일 필요가 없는 경우
STL 알고리즘 함수의 매개 변수에 연산 코드를 넘기는 경우, 연산 코드를 익명의 람다식으로 작성

*/
