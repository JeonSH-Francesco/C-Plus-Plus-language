
/*
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1;}
	Circle(int r) {	radius = r;}
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

// .연산자를 이용하여 객체 이름으로 멤버 함수 호출
// 포인터로 ->연산자를 이용하여 멤버 함수 호출

int main() {
	Circle donut;
	Circle pizza(30);

	cout << donut.getArea() << endl;

	Circle* p;
	p = &donut;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	p = &pizza;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

}

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {

	Circle circleArray[3];

	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++) {
		cout << "Circle" << i << "의 면적은 " << circleArray[i].getArea() << endl;
		//cout << "Circle" << i << "의 면적은 " << (circleArray+i)->getArea() << endl;

	}
	Circle* p;
	p = circleArray;

	for (int i = 0; i < 3; i++) {

		cout << "Circle" << i << "의 면적은 " << p->getArea() << endl;
	
		p++;
	}

}


#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea() {
		return 3.14 * radius * radius;
	};
};

int main() {
	Circle circleArray[3] = { Circle(10),Circle(20),Circle() };

	for (int i = 0; i < 3; i++) {
		cout << "Circle" << i << "의 면적은" << circleArray[i].getArea() << endl;
	}
}


#include <iostream>
using namespace std;


class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea() {
		return 3.14 * radius * radius;
	};
};

int main() {
	Circle circles[2][3];

	circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);
	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			
			cout << "Circle[" << i << "]" << "[" << j << "]" << "의 면적은 ";
			cout <<circles[i][j].getArea() << endl;
		}
	}

}

#include <iostream>
using namespace std;

class Sample {
	int a;
public:
	Sample() { a = 100; cout << a << ' '; }
	Sample(int x) { a = x; cout << a << ' '; }
	Sample(int x, int y) { a = x * y; cout << a << ' ';  }
	int get() { return a; }
};

int main() {

	Sample arr[3];
	cout << endl;
	Sample arr2D[2][2] = { {Sample(2,3),Sample(2,4)},{Sample(5),Sample()} };
	cout << endl;
	Sample* p = arr;
	int sum = 0;

	for (int i = 0; i < 3; i++) {
		sum += p->get();
		p++;
	}
	cout << "Sum arr= " << sum << endl;

	sum = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			sum += arr2D[i][j].get();
		}
	}
	cout << "Sum arr2D= " << sum << endl;
}

#include <iostream>
using namespace std;

int main() {
	int* p;
	p = new int;

	if (!*p) {
		cout << "메모리 할당 실패";
		return 0;
	}

	*p = 5;
	int n = *p;
	cout << "*p=" << *p << endl;
	cout << "n=" << n << endl;
	
	delete p;
}

#include <iostream>
using namespace std;

int main() {
	cout << "입력할 정수의 개수는? : ";
	int n;
	cin >> n; // 정수 개수 입력
	if (n <= 0) return 0;

	int *p= new int[n]; //n개의 정수 배열 동적 할당

	if (!p) {
		cout << "메모리 할당 실패";
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		cout << i + 1<<"번째 정수 : "; 
		cin >> p[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i];
	}
	cout << "평균 : " << sum / n << endl;
	delete [] p;
}

#include <iostream>
using namespace std;

int main() {
	int* p = new int[5];

	if (!p) {
		cout << "메모리 할당 실패";
		return 0;
	}
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 정수 : ";
		cin >> p[i];
	}
	int biggest = p[0];

	for (int i = 0; i < 5; i++) {
		if (biggest < p[i]) {
			biggest = p[i];
		}
	}
	cout << "제일 큰 수는 " << biggest << endl;

	delete [] p;
}



#include <iostream>
using namespace std;

//new와 delete를 이용하여 객체를 동적으로 생성하고 반환하는 방법

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r){ radius =r};
	double getArea() {
		return 3.14 * radius*radius;
	}
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius= " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius=" << radius << endl;
}

Circle::~Circle(){
	cout << "소멸자 실행 radius =" << radius << endl;
}

int main() {
	Circle *p, *q;
	p = new Circle;
	q = new Circle(30);

	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q;
}


#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
		cout << "생성자 실행 radius ="<<radius<<endl;
	};
	Circle(int r) {
		radius = r;
		cout << "생성자 실행 radius =" << radius << endl;
	};
	~Circle() {
		cout << "소멸자 실행 radius =" << radius << endl;
	};
	void setRadius(int r) { radius = r; }
	double getArea() {
		return 3.14 * radius * radius;
	}
};

int main() {
	int radius;
	while (true) {
		cout << "정수 반지름 입력(음수이면 종료): ";
		cin >> radius;
		if (radius < 0) break;
		Circle* p = new Circle(radius); //동적 객체 생성
		cout << "원의 면적은 " << p->getArea() <<endl;
		delete p;
	}
}

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
		cout << "생성자 실행 radius ="<<radius<<endl;
	};
	Circle(int r) {
		radius = r;
		cout << "생성자 실행 radius =" << radius << endl;
	};
	~Circle() {
		cout << "소멸자 실행 radius =" << radius << endl;
	};
	void setRadius(int r) { radius = r; }
	double getArea() {
		return 3.14 * radius * radius;
	}
};

int main() {
	Circle* pArray = new Circle[3];
	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for (int i = 0; i < 3; i++) {
		cout << pArray[i].getArea() << endl;
	}
	Circle* p = pArray;
	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << endl;
		p++;
	}

	delete[]pArray;
}

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() {	radius = 1;	};
	
	~Circle() {	};
	void setRadius(int r) { radius = r; }
	double getArea() {
		return 3.14 * radius * radius;
	}
};

int main() {
	cout << "생성 하고자 하는 원의 개수 : " << endl;
	int n, radius;
	cin >> n;
	if (n <= 0) return 0;
	Circle* pArray = new Circle[n];
	
	for (int i = 0; i < n; i++) {
		cout << "원" << i + 1 << " : ";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	int count = 0;
	Circle* p = pArray;
	for (int i = 0; i < n; i++) {
		cout << p->getArea() << ' ';
		if (p->getArea() >= 100 && p->getArea() <= 200)
			count++;
		p++;
	}
	cout << endl << "면적이 100에서 200 사이의 원의 개수는 " << count << endl;
	delete[]pArray;
}


#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	string address("서울시 노원구 상계동 123");
	string copyAddress(address); //address의 문자열을 복사한 스트링 객체 생성


	char text[] = {'L','O', 'V', 'E', ' ', 'C', '+', '+', '\0' }; //C-string
	string title(text);

	cout << str << endl;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;

}



#include <iostream>
#include <string>
using namespace std;

int main() {

	string name[5];
	
	for (int i = 0; i < 5; i++) {
		cout << "이름 : ";
		getline(cin, name[i], '\n');
	}

	string latter = name[0];

	for (int i = 0; i < 5; i++) {
		if (latter < name[i])
			latter = name[i];
	}

	cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;

}

#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	
	cout << "아래의 문자열을 입력하세요. (only english) : "<<endl;
	getline(cin, s, '\n');
	int len = s.length();

	for (int i = 0; i < len; i++) {
		string first = s.substr(0, 1);
		string sub = s.substr(1,len - 1);
		s = sub + first;
		cout << s << endl;
	}

}

#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	
	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요."<<endl;
	getline(cin, s, '\n');
	int sum = 0;
	int startIndex = 0;
	
	while (true) {
		int fIndex = s.find('+', startIndex); // '+'문자 검색
		if (fIndex == -1) {
			string part=s.substr(startIndex);
			if (part == "") break; // "2+3+", 즉 +로 끝나는 경우
			cout << part << endl;
			sum += stoi(part); //문자열을 수로 변환하여 더하기
		}
		int count = fIndex - startIndex; // 서브스트링으로 자를 문자 개수
		string part = s.substr(startIndex, count); //startIndex부터 count개의 문자로 서브스트링 만들기

		cout << part << endl;
		sum += stoi(part); //문자열을 수로 변환하여 더하기
		startIndex = fIndex + 1; //검색을 시작할 인덱스 진전시킴
	}
	cout << "숫자들의 합은 " << sum;
}

#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
	getline(cin, s, '&'); // 문자열 입력
	cin.ignore(); // '&' 뒤에 따라 오는 <Enter>키를 제거하기 위한 코드 !!!

	string f, r;
	cout << endl << "find : ";
	getline(cin, f, '\n'); //문자열 입력
	cout << "replace : ";
	getline(cin, r, '\n'); // 대체할 문자열 입력

	int startIndex = 0;

	while (true) {
		int fIndex = s.find(f, startIndex); // startIndex부터 문자열 f 검색
		if (fIndex == -1)  //문자열 s의 끝까지 변경해서 찾을 수 없음.
			break;
		s.replace(fIndex, f.length(), r); // fIndex부터 문자열 f의 길이만큼 문자열 r로 변경
		startIndex = fIndex + r.length();
	}
	cout << s << endl;

	/*
	I like you. -> I love you.
	*/

}
*/
