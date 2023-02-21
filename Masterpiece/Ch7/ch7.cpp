#include <iostream>
using namespace std;

class Stack {
	int s[100];
	int top;
public:
	Stack() { top = -1; }
	bool operator !() {
		if (top == -1) return true;
		else return false;
	}
	Stack& operator<<(int x) {
		s[top++] = x;
		return *this;
	}
	Stack& operator>>(int& x) {
		x = s[top--];
		return *this;
	}
};

int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
	return 0;
}



/*
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
------
1-1번문제
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price=0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	Book& operator +=(int price) {
		this->price += price;
		return *this;
	}
	Book& operator -=(int price) {
		this->price -= price;
		return *this;
	}

};


int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();

	return 0;
}
----------
1-2번문제
#include <iostream>
#include <string>

using namespace std;
class Book;
Book& operator +=(Book& b, int price);
Book& operator -=(Book& b, int price);

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	friend Book& operator +=(Book& b, int price);
	friend Book& operator -=(Book& b, int price);
};

Book& operator +=(Book& b, int price) {
	b.price += price;
	return b;
}

Book& operator -=(Book& b, int price) {
	b.price -= price;
	return b;
}

int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();

	return 0;
}
-------
2-1번문제
#include <iostream>
#include <string>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	bool operator== (int price);
	bool operator== (string title);
	bool operator== (Book& b);

};

bool Book::operator==(int price){
	if (this->price == price)
		return true;
	else
		return false;
}

bool Book::operator==(string title) {
	if (this->title == title)
		return true;
	else
		return false;

}

bool Book::operator==(Book& b) {
	if (this->price == b.price && this->title == b.title && this->pages==b.pages)
		return true;
	else
		return false;
}

int main() {
	Book a("명품 C++", 30000, 500), b("고품", 30000, 500), c("명품 C++", 30000, 500);

	if (a == 30000) cout << "정가 30000원" << endl; // price 비교
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl; // title 비교
	if (a == c) cout << "두 책이 같은 책입니다." << endl; // title, price, pages 모두 비교


	return 0;
}
-----
2-2번문제
#include <iostream>
#include <string>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	friend bool operator== (Book a,int price);
	friend bool operator== (Book a,string title);
	friend bool operator== (Book a,Book& b);

};

bool operator==(Book a,int price) {
	if (a.price == price)
		return true;
	else
		return false;
}

bool operator==(Book a,string title) {
	if (a.title == title)
		return true;
	else
		return false;

}

bool operator==(Book a,Book& b) {
	if (a.price == b.price && a.title == b.title && a.pages == b.pages)
		return true;
	else
		return false;
}

int main() {
	Book a("명품 C++", 30000, 500), b("고품", 30000, 500), c("명품 C++", 30000, 500);

	if (a == 30000) cout << "정가 30000원" << endl; // price 비교
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl; // title 비교
	if (a == c) cout << "두 책이 같은 책입니다." << endl; // title, price, pages 모두 비교


	return 0;
}
-----------
3번문제
#include <iostream>
#include <string>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	bool operator !() {
		if (this->price == 0)
			return true;
		else
			return false;
	}

};


int main() {
	Book book("벼룩시장", 0, 50); // 가격이 0인 경우
	if (!book) cout << "공짜다." << endl;

	return 0;
}
------
4번문제
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	friend bool operator< (string str, Book b);

};
bool operator <(string str, Book b) {
	if (str.compare(b.title) < 0)
		return true;
	else
		return false;
}
int main() {
	Book a("청춘", 20000, 300);
	string b;
	cout << "책 이름을 입력하세요>>";
	getline(cin, b);

	if (b < a)
		cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
	else
		cout << a.getTitle() << "이 " << b << "보다 앞에 있구나!" << endl;
	return 0;
}
-----
5-1번문제
#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color():Color(0, 0, 0){}
	Color(int r, int g, int b) {
		this->red = r;
		this->green = g;
		this->blue = b;
	}
	void show() {
		cout << red << ' ' << green << ' ' << blue << endl;
	}
	Color operator +(Color c) {
		Color tmp;
		tmp.red = this->red + c.red;
		tmp.green = this->green + c.green;
		tmp.blue = this->blue + c.blue;
		return tmp;
	}
	bool operator ==(Color c) {
		if (this->red == c.red && this->green == c.green && this->blue == c.blue)
			return true;
		else
			return false;
	}
};


int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";

}
-----------
5-2번문제
#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color():Color(0, 0, 0) {}
	Color(int r, int g, int b) {
		this->red = r;
		this->green = g;
		this->blue = b;
	}
	void show() {
		cout << red << ' ' << green << ' ' << blue << endl;
	}
	friend Color operator+(Color c1, Color c2);
	friend bool operator ==(Color c1, Color c2);

};
Color operator+(Color c1,Color c2) {
	Color tmp;
	tmp.red = c1.red + c2.red;
	tmp.green = c1.green + c2.green;
	tmp.blue = c1.blue + c2.blue;
	return tmp;
}
bool operator==(Color c1,Color c2) {
	if (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue)
		return true;
	else
		return false;
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}
--------
6-1번문제
#include <iostream>
using namespace std;

class Matrix {
	int mArray[2][2];
public:
	Matrix():Matrix(0,0,0,0) {}
	Matrix(int m1, int m2, int m3, int m4) {
		mArray[0][0] = m1;
		mArray[0][1] = m2;
		mArray[1][0] = m3;
		mArray[1][1] = m4;
	}
	void show() {
		cout << "Matrix = {";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cout << mArray[i][j] << ' ';
			}
		}
		cout << "}" << endl;
	}
	Matrix operator +(Matrix mat) {
		Matrix tmp;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				tmp.mArray[i][j] = mArray[i][j] + mat.mArray[i][j];
			}
		}
		return tmp;
	}
	Matrix& operator +=(Matrix mat) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				mArray[i][j] += mat.mArray[i][j];
			}
		}
		return *this;
	}
	bool operator ==(Matrix mat) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (mArray[i][j] != mat.mArray[i][j]) return false;
				else return true;
			}
		}
	}
};

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;

	return 0;
}
-----
6-2번문제
#include <iostream>
using namespace std;

class Matrix;
Matrix operator +(Matrix mat1, Matrix mat2);
Matrix& operator +=(Matrix& mat1, Matrix mat2);
bool operator ==(Matrix mat1, Matrix mat2);

class Matrix {
	int mArray[2][2];
public:
	Matrix():Matrix(0,0,0,0) {}
	Matrix(int m1, int m2, int m3, int m4) {
		mArray[0][0] = m1;
		mArray[0][1] = m2;
		mArray[1][0] = m3;
		mArray[1][1] = m4;
	}
	void show() {
		cout << "Matrix = {";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cout << mArray[i][j] << ' ';
			}
		}
		cout << "}" << endl;
	}
	friend Matrix operator +(Matrix mat1, Matrix mat2);
	friend Matrix& operator +=(Matrix& mat1, Matrix mat2);
	friend bool operator ==(Matrix mat1, Matrix mat2);
};

Matrix operator +(Matrix mat1,Matrix mat2) {
	Matrix tmp;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			tmp.mArray[i][j] = mat1.mArray[i][j] + mat2.mArray[i][j];
		}
	}
	return tmp;
}

Matrix& operator +=(Matrix &mat1,Matrix mat2) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			mat1.mArray[i][j] += mat2.mArray[i][j];
		}
	}
	return mat1;
}
bool operator ==(Matrix mat1,Matrix mat2) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (mat1.mArray[i][j] != mat2.mArray[i][j]) return false;
			else return true;
		}
	}
}
int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;

	return 0;
}
*/
