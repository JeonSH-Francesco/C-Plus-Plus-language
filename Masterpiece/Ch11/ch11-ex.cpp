#include <iostream>
using namespace std;

ostream& fivestar(ostream& outs) {
	return outs << "*****";
}

ostream& rightarrow(ostream& outs) {
	return outs << "----->";
}

ostream& beep(ostream& outs) {
	return outs << '\a';
}

int main() {
	cout << "벨이 울립니다." << beep << endl;
	cout << "C" << rightarrow << "C++" << rightarrow << endl;
	cout << "Visual" << fivestar << "C++" << endl;
}



/*
#include <iostream>
using namespace std;


//put()은 문자 단위로 출력하는 함수
//put()함수는 ostream&를 리턴하므로 다음과 같이 연결하여 사용 가능
//write()는 char 배열에 들어 있는 문자들을 출력하는 함수
//write(str,n); str 배열에 있는 n개의 문자 출력
//flush()는 출력 버퍼에 있는 문자들을 모두 강제로 출력


int main() {
	cout.put('H');
	cout.put('i');
	cout.put(33);
	cout.put('\n');

	cout.put('C').put('+').put('+').put(' ');

	char str[] = "I love programming";
	cout.write(str, 6);

}
-----------
#include <iostream>
using namespace std;

void get1() {
	cout << "cin.get()로 <Enter> 키까지 입력 받고 출력합니다.>>";
	int ch;

	while ((ch = cin.get()) != EOF) {
		cout.put(ch);

		if (ch == '\n')
			break; //Enter 키가 입력되면 읽기 중단
	}
}


void get2() {
	cout << "cin.get(char &)로 <Enter> 키까지 입력 받고 출력합니다.>>";
	char ch;

	while (true) {
		cin.get(ch);//문자 읽기

		if (cin.eof()) break; //EOF를 만나면 읽기 종료
		cout.put(ch); // ch의 문자 출력

		if (ch == '\n')
			break; //Enter 키가 입력되면 읽기 중단
	}

}


int main() {
	get1();
	get2();
}
----------
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char cmd[80];
	cout << "cin.get(char*,int)로 문자열을 읽습니다." << endl;
	while (true) {
		cout << "종료하려면 exit를 입력하세요>>";
		cin.get(cmd, 80); // <Enter>키까지 문자열 읽기, 79개까지 문자 읽음.

		if (strcmp(cmd, "exit") == 0) {
			cout << "프로그램을 종료합니다...";
			return 0;
		}
		else
			cin.ignore(1); //버퍼에 남아 있는 <Enter>키('\n') 제거
	}


}
-------
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char line[80];

	cout << "cin.getline()함수로 라인을 읽습니다." << endl;
	cout << "exit을 입력하면 루프가 끝납니다." << endl;
	int no = 1;//라인 번호

	while (true) {
		cout << "라인" << no << " >>";
		cin.getline(line, 80); // 한 라인의 문자열 읽기, 79개까지 문자 읽음
		if (strcmp(line, "exit") == 0)
			break;
		cout << "echo---->";
		cout << line << endl; // 읽은 라인을 화면에 출력
		no++; // 라인 번호 증가
	}
}
-------
#include <iostream>
using namespace std;

//long setf(long flags) -> flags를 스트림의 포맷 플래그로 설정하고 이전 플래그를 리턴한다.
//long unsetf(long flags) -> flags에 설정된 비트 값에 따라 스트림의 포맷 플래그를 해제하고 이전 플래그를 리턴한다.

int main() {
	cout << 30 << endl;

	cout.unsetf(ios::dec); //10진수로 출력
	cout.setf(ios::hex);//16진수로 설정
	cout << 30 << endl;

	cout.setf(ios::showbase);// 16진수이면 0X를, 8진수이면 0을 숫자 앞에 붙여 출력
	cout << 30 << endl;

	cout.setf(ios::uppercase); // 16진수의 A~F를 대문자로 출력

	cout << 30 << endl;

	cout.setf(ios::dec | ios::showpoint); //10진수 표현과 동시에 실수에 소숫점 이하 나머지는 0으로 출력

	cout << 23.5 << endl;

	cout.setf(ios::scientific); // 실수를 과학산술용 표현으로 출력
	cout << 23.5 << endl;

	cout.setf(ios::showpos); // 양수인 경우 + 부호도 함께 출력
	cout << 23.5;

}
------
#include <iostream>
using namespace std;

void showWidth() {
	cout.width(10);
	cout << "Hello" << endl;
	cout.width(5); // 다음에 출력되는 정수 12를 5칸으로 지정
	cout << 12 << endl;

	cout << '%';
	cout.width(10); // 다음에 출력되는 "Korea/"만 10칸으로 지정
	cout << "Korea/" << "Seoul/" << "City" << endl;
}

int main() {
	showWidth(); //width() 사용 사례
	cout << endl;

	cout.fill('^');//fill()을 적용한 후 width()의 사례를 보여준다.
	showWidth();
	cout << endl;

	cout.precision(5);//precision() 사용 예
	cout << 11./ 3. << endl;

}
-----
#include <iostream>
using namespace std;

int main() {
	cout << hex << showbase << 30 << endl;
	cout << dec << showpos << 100 << endl;
	cout << true << ' ' << false << endl;
	cout << boolalpha << true << ' ' << false << endl;
}
------
#include <iostream>
#include <iomanip>
using namespace std;

//매개변수를 가지는 조작자
//setw(int minWidth) -> I/O -> O 필드의 최소 너비를 minWidth로 지정
//setfill(char cFill) ->I/O -> I 필드를 출력하고 남은 공간에 cFill 문자로 채움

int main() {

	cout << showbase;

	cout << setw(8) << "Number";

	cout << setw(10) << "Octal";

	cout << setw(10) << "Hexa" << endl;

	for (int i = 0; i < 50; i += 5) {
		cout << setw(8) << setfill('.') << dec << i; //10진수
		cout << setw(10) << setfill(' ') << oct << i; //8진수
		cout << setw(10) << setfill(' ') << hex << i << endl; //16진수
	}

}
--------
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend ostream& operator << (ostream& stream, Point a); //private 필드 x,y를 접근하기 위해
	//이 함수를 Point 클래스에 freind로 선언함.
};

// << 연산자 함수
ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p(3, 4); // Point 객체 생성
	cout << p << endl; // Point 객체 화면 출력

	Point q(1, 100), r(2, 200); // Point 객체 생성
	cout << q << r << endl; // Point 객체들 연속하여 화면 출력
}

------
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	string press;
	string author;
public:
	Book(string title = "", string press = "", string author = "") {
		this->title = title;
		this->press = press;
		this->author = author;
	}
	friend ostream& operator << (ostream& stream, Book b); //friend 선언
};

// << 연산자 함수
ostream& operator << (ostream& stream, Book b) {
	stream << b.title << "," << b.press << "," << b.author;
	return stream;
}

int main() {
	Book book("소유냐 존재냐", "한국출판사", "에리히프롬"); //Book 클래스 객체 생성
	cout << book; //book 객체 화면 출력

}

--------
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend istream& operator >> (istream& ins, Point& a); //friend 선언
	friend ostream& operator << (ostream& stream, Point a); //friend 선언
};


istream& operator >> (istream& ins, Point& a) { // >> 연산자 함수
	cout << "x 좌표>>";
	ins >> a.x;
	cout << "y 좌표>>";
	ins >> a.y;
	return ins;
}

ostream& operator << (ostream& stream, Point a) { // << 연산자 함수
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p; // Point 객체 생성
	cin >> p; // >> 연산자를 호출하여 x 좌표와 y 좌표를 키보드로부터 읽어 객체 p 완성
	cout << p; // << 연산자를 호출하여 객체 p 출력
}

*/
