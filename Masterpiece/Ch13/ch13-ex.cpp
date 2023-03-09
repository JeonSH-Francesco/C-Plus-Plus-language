#include <iostream>
#include <string>
using namespace std;

class MyException {
	int lineNo;
	string func, msg;
public:
	MyException(int n, string f, string m) {
		lineNo = n;
		func = f;
		msg = m;
	}
	void print() {
		cout << func << ":" << lineNo << ", " << msg << endl;
	}
};


class DivideByZeroException : public MyException {
public:
	DivideByZeroException(int lineNo, string func, string msg)
		: MyException(lineNo, func, msg) { }
};


class InvalidInputException : public MyException {
public:
	InvalidInputException(int lineNo, string func, string msg)
		: MyException(lineNo, func, msg) { }
};

int main() {
	int x, y;
	try {
		cout << "나눗셈을 합니다. 두개의 양의 정수를 입력하세요>>";
		cin >> x >> y;

		if (x < 0 || y < 0) {
			throw InvalidInputException(39, "main()", "음수 입력 예외 발생");
		}
		if (y == 0) {
			throw DivideByZeroException(42, "main()", "0으로 나누는 예외 발생");
		}
		cout << (double)x / (double)y;
	}

	catch (DivideByZeroException& e) {
		e.print();
	}
	catch (InvalidInputException& e) {
		e.print();
	}


}


/*
#include <iostream>
using namespace std;

int getExp(int base, int exp) {
	int value = 1;
	if (base <= 0 || exp <= 0) {
		return -1;
	}
	for (int n = 0; n < exp; n++) {
		value = value * base;
	}
	return value;
}

int main() {
	int v = 0;
	v=getExp(2, 3);

	if(v!=-1)
		cout << "2의 3승은 " << v << "입니다." << endl;
	else
		cout << "계산 불가!! 오류 입니다." << endl;


	int e = 0;
	e=getExp(2, -3);

	if (e != -1)
		cout << "2의 -3승은" << v << "입니다." << endl;
	else
		cout << "계산 불가!! 오류 입니다." << endl;

}
---------
#include <iostream>
using namespace std;

bool getExp(int base, int exp, int& ret) {
	if (base <= 0 || exp <= 0) {
		return false; // 오류 리턴
	}

	int value = 1;
	for (int n = 0; n < exp; n++)
		value = value * base;
	ret = value; // 계산 값을 ret에 저장
	return true; //정상 리턴
}

int main() {
	int v = 0;
	if (getExp(2, 3, v))
		cout << "2의 3승은" << v << "입니다." << endl;
	else
		cout << "계산 불가!! 오류 입니다." << endl;

	int e = 0;
	if (getExp(2, -3, e))
		cout << "2의 -3승은" << e << "입니다." << endl;
	else
		cout << "계산 불가!! 오류 입니다." << endl;

}
-------
#include <iostream>
using namespace std;

int main() {
	int n, sum, average;

	while (true) {
		cout << "합을 입력하세요>>";
		cin >> sum;
		cout << "인원수를 입력하세요>>";
		cin >> n;

		try {
			if (n <= 0)
				throw n;
			else
				average = sum / n;
		}

		catch (int x) {
			cout << "예외 발생!!" << x << "으로 나눌 수 없음" << endl;
			average = 0;
			cout << endl;
			continue;
		}

		cout << "평균= " << average << endl << endl;
	}


}

----
#include <iostream>
using namespace std;

int getExp(int base, int exp) { //base의 exp 지수승을 계산하여 리턴
	if (base <= 0 || exp <= 0) { //오류 검사
		throw "음수 사용 불가"; //예외 발생
	}
	int value = 1;
	for (int n = 0; n < exp; n++) {
		value = value * base;
	}
	return value;
}


int main() {
	int v = 0;
	try {
		v = getExp(2, 3);
		cout << "2의 3승은 " << v << "입니다." << endl;

		v = getExp(2, -3);
		cout << "2의 -3승은" << v << "입니다." << endl;
	}
	catch (const char* s) {
		cout << "예외 발생" << s << endl;
	}

}
----------
#include <iostream>
#include <cstring>
using namespace std;

int stringToInt(const char x[]) {
	int sum = 0;
	int len = strlen(x);
	for (int i = 0; i < len; i++) {
		if (x[i] > '0' && x[i] <= '9')
			sum = sum * 10 + x[i] - '0';
		else
			throw x;
	}
	return sum;
}

int main() {
	int n;
	try {
		n = stringToInt("123");
		cout << "\"123\"은 정수" << n << "로 변환됨" << endl;
		n = stringToInt("1A3");
		cout << "\"1A3\"은 정수" << n << "로 변환됨" << endl;
	}
	catch (const char* s) {
		cout << s << "처리에서 예외 발생!!" << endl;
		return 0;
	}
}


*/
