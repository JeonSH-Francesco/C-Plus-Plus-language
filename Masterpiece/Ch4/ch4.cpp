
/*
#include <iostream>
#include <string>

using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);
	Color* p;
	p = &screenColor;
	p->show();

	Color colors[3];
	p = colors;
	p->setColor(255, 0, 0);
	(p+1)->setColor(0, 255, 0);
	(p+2)->setColor(0, 0, 255);

	for (int i = 0; i < 3; i++) {
		(p + i)->show();
	}
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
	int* arr = new int[5];
	float average = 0.0f;

	cout << "정수 5개 입력>>";
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		average += arr[i];
	}

	average /= 5;
	cout << "평균 " << average << endl;

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int cnt = 0;

	cout << "문자열 입력>>";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a') cnt++;
	}

	cout << "문자 a는 " << cnt << "개 있습니다." << endl;

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int cnt = 0, ind = 0;

	cout << "문자열 입력>>";
	getline(cin, str);

	while (true) {
		ind = str.find('a', ind+1);
		if (ind == -1) break;
		else cnt++;
	}
	cout << "문자 a는 " << cnt << "개 있습니다." << endl;

	return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Sample{
	int* p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int[n];
	}
	void read(); // 키보드에서 정수 배열 읽기
	void write(); // 정수 배열 출력
	int big(); // 정수 배열에서 가장 큰 수 리턴
	~Sample(); // 소멸자
};

void Sample::read() {
	cout << "10개의 정수를 입력하세요 : " ;
	for (int i = 0; i < size; i++) {
		cin >> p[i];
	}
}

void Sample::write() {
	cout << "10개의 정수를 출력합니다."<< endl;
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
		cout << endl;
	}
}

int Sample::big() {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (p[i] > max)
			max = p[i];
	}
	return max;
}

Sample::~Sample() {
	delete[]p;
}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;

	return 0;
}


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	string str;

	while (true) {
		cout << "아래에 한 줄을 입력하세요(exit를 입력하면 종료)"<<endl;
		getline(cin, str);
		if (str.compare("exit") == 0) break;

		srand((unsigned)time(0));
		int n = rand() % (str.length());

		srand((unsigned)time(0));
		char ch = 'a' + rand() % 26;

		str[n] = ch;

		cout << ">>" << str << endl;
	}

	return 0;
}

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	string str;

	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, str);
		if (str.compare("exit") == 0) break;

		for (int i = str.length() - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout << endl;
	}

	return 0;
}

#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea();
};

void Circle::setRadius(int radius) {
	this->radius = radius;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle circles[3];
	int cnt = 0;

	for (int i = 0; i < 3; i++) {
		int r;
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		circles[i].setRadius(r);

		if (circles[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다." << endl;

	return 0;
}


#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea();
};

void Circle::setRadius(int radius) {
	this->radius = radius;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	int cnt = 0, numOfCircles;

	cout << "원의 개수>>";
	cin >> numOfCircles;
	Circle *circles = new Circle[numOfCircles];

	for (int i = 0; i < numOfCircles; i++) {
		int r;
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		circles[i].setRadius(r);

		if (circles[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다." << endl;

	return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};
Person::Person() {

}

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	Person person[3];
	cout << "이름과 전화번호를 입력해 주세요" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1 << ">> ";
		string name, tel;
		cin >> name >> tel;
		person[i].set(name, tel);
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << person[i].getName() << ' ';
	}
	cout << endl;

	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	string find;
	cin >> find;
	for (int i = 0; i < 3; i++) {
		if (find.compare(person[i].getName()) == 0) {
			cout << "전화 번호는 " << person[i].getTel() << endl;
			break;
		}
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person() { }
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class Family {
	Person* p;
	string familyName;
	int size;
public:
	Family(string name, int size);
	void show();
	void setName(int index, string name) { p[index].setName(name); }
	~Family();
};

Family::Family(string name, int size) {
	p = new Person[size];
	this->familyName = name;
	this->size = size;
}
void Family::show() {
	cout << familyName << "가족은 다음과 같이 " << size << "명 입니다." << endl;
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << '\t';
	}
	cout << endl;
}
Family::~Family() {
	delete [] p;
}

int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr.Simpson");
	simpson->setName(1, "Mrs.Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
	return 0;
}

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
void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
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

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) {
		this->name = name; this->radius = radius;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleManager {
	Circle *p;
	int size;
public:
	CircleManager(int size) { p = new Circle[size]; this->size = size; }
	~CircleManager() { delete [] p; }
	Circle * getCircle() { return p; }
	void searchByName();
	void searchByArea();
};

void CircleManager::searchByName() {
	string find;
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> find;

	for (int i = 0; i < size; i++) {
		if (find==p[i].getName()) {
		//if (find.compare(p[i].getName()) == 0) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
			break;
		}
	}
}
void CircleManager::searchByArea() {
	int minArea;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> minArea;
	cout << minArea << "보다 큰 원을 검색합니다." << endl;

	for (int i = 0; i < size; i++) {
		if (p[i].getArea()>minArea) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
		}
	}
	cout << endl;
}

int main() {
	int numOfCircles;
	cout << "원의 개수 >> ";
	cin >> numOfCircles;

	CircleManager circles(numOfCircles);

	for (int i = 0; i < numOfCircles; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		string name;
		int r;
		cin >> name >> r;
		circles.getCircle()[i].setCircle(name, r);
	}
	circles.searchByName();
	circles.searchByArea();

	return 0;
}

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
		if (str[i] >= 'a' && str[i] <= 'z'){
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

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
	int card[3];
	string name;
public:
	Player() :Player("플레이어") { }
	Player(string name) { this->name = name; }
	string getName() { return name; }
	bool playGambling();
};
bool Player::playGambling() {
	for (int i = 0; i < 3; i++) {
		card[i] = rand() % 3;
		cout << "\t" << card[i];
	}
	for (int i = 0; i < 2; i++) {
		if (card[i] != card[i + 1]) {
			return false;
		}
	}
	return true;
}

class GamblingGame {
	Player player[2];
	bool isGameCompleted = false;
public:
	GamblingGame();
	void play();
};

GamblingGame::GamblingGame() {
	cout << "*****갬블링 게임을 시작합니다. *****" << endl;
	string name;
	cout << "첫번째 선수 이름>>";
	cin >> name;
	player[0] = Player(name);
	cout << "두번째 선수 이름>>";
	cin >> name;
	player[1] = Player(name);
	getchar();
}

void GamblingGame::play() {
	int i = 0;
	while (!isGameCompleted) {
		cout << player[i % 2].getName() << ":<Enter>";
		getchar();
		if (player[i % 2].playGambling()) {
			isGameCompleted = true;
			cout << "\t" << player[i % 2].getName() << "님 승리!!" << endl;
		}
		else {
			cout << "\t아쉽군요!" << endl;
		}
		i++;
	}
}

int main() {
	GamblingGame game;
	game.play();

	return 0;
}
*/
