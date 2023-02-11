#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {

	int countStack = 0, numCount = 0;
	char buf[10000];

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;

	cin.getline(buf, 10000, ';');

	for (int i = 0; i <= strlen(buf); i++)
	{
		//isalpha(char c)->알파벳인지 검사하기 위한 함수
		//tolower(char c)->대문자를 소문자로 바꾸기 위한 함수
		if (isalpha(buf[i]) != 0)
		{
			buf[i] = tolower(buf[i]);
			numCount++;
		}
	}

	cout << "총 알파벳 수 " << numCount << endl;

	for (char i = 'a'; i <= 'z'; i++)
	{
		for (int j = 0; j <= strlen(buf); j++)
			if (buf[j] == i)
				countStack++;
		cout << i << "(" << countStack << ")" << " : ";
		for (int k = 0; k < countStack; k++)
			cout << "*";
		cout << endl;
		countStack = 0;
	}
}


/*
-------------
1번문제
#include <iostream>

using namespace std;

int main() {
	for (int i = 1; i <= 100; i++) {
		cout << i << "\t";
	
		if (i % 10 == 0)
			cout << endl;
	}


}
---------
2번문제
#include <iostream>

using namespace std;

int main() {

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << j<<"x"<<i <<"="<<i*j<<"\t";
		}
		cout << endl;
	}

	return 0;
}

--------
3번 문제
#include <iostream>

using namespace std;

int main() {
	int a, b;
	cout << "두 수를 입력하라>>";
	cin >> a >> b;

	if (a > b)
		cout <<"큰 수="<< a;
	else if (b > a)
		cout << "큰 수="<< b;

	//cout << "큰 수="<<(a>b? a:b);

}
-------
4번문제
#include <iostream>

using namespace std;

int main() {
	double num[5] = { 0 }, max = 0;

	cout << "5개의 실수를 입력하라>>";
	for(int i=0;i<5;i++)
	{
		cin >> num[i];
		if(num[i] > max)
			max = num[i];
	}
	cout << "제일 큰 수 =" << max;
}
----------
5번문제
#include <iostream>
using namespace std;

int main() {
	char x[100];
	int cnt=0;

	cout << "문자들을 입력하라(100개 미만).";
	cin.getline(x, 100);
	for (int i = 0; i <= sizeof(x); i++) {
		if (x[i] == 'x') {
			cnt++;
		}
	}
	cout<<"x의 개수는 "<< cnt <<endl;

}
--------
6번문제
//공백 없이 입력된 문자열 읽기
#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cout << "새 암호를 입력하세요>>";
	//getline()은 string 타입의 C++문자열을 입력받기 위해 제공되는 전역함수
	getline(cin, a);
	cout << "새로운 암호를 다시 한 번 더 입력하세요>>";
	getline(cin, b);

	if (a == b) {
		cout << "같습니다." << endl;
	}
	else {
		cout << "같지 않습니다." << endl;
	}

}
---------
7번문제
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char a[100];

	while (true) {
		cout << "종료하고 싶으면 yes를 입력하세요>>";
		cin.getline(a, 100);

		if (strcmp(a, "yes") == 0) {

			break;
		}

	}
	cout << "종료합니다...\n";
}
--------
8번문제
#include <iostream>
#include <string>
using namespace std;

int main() {

	string top_name = {};
	char name[100] = {};
	int max = 0;

	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << endl << ">>";

	for (int i = 0; i < 5; i++)
	{
		cin.getline(name, 100, ';');
		cout << (i + 1) << ":" << name << endl;

		if (max < strlen(name))
		{
			max = strlen(name);
			top_name = name;
		}
	}

	cout << "가장 긴 이름은 " << top_name << endl;
}
-----
9번문제
#include <iostream>
#include <string>
using namespace std;

int main() {
	string name = {};
	string address = {};
	string age = {};

	cout << "이름은?"<<endl;
	getline(cin, name);
	cout << "주소는?" << endl;
	getline(cin,address);
	cout << "나이는?" << endl;
	getline(cin, age);
	cout << name << ',' <<address<<','<<age<<"세"<<endl;
}
-----------
10번문제
#include <iostream>
#include <cstring>
using namespace std;

int main() {

	char a[50];
	cout << "문자열 입력>> ";
	cin.getline(a, 50);

	for (int i = 0; i < strlen(a); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << a[j];
		}
		cout << endl;
	}
}
-------
11번문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int k = 0, n = 0;
	int sum = 0;
	printf("끝 수를 입력하세요>>");
	scanf("%d", &n);
	for (k = 1; k <= n; k++) {
		sum += k;
	}
	printf("1에서 %d까지의 합은 %d입니다.\n", n, sum);
	return 0;
}
------
12번문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int a,int b);

int main() {
	int n = 0;
	printf("끝 수를 입력하세요>>");
	scanf("%d", &n);
	printf("1에서 %d까지의 합은 %d입니다.\n", n, sum(1, n));
	return 0;
}
int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {
		res += k;
	}
	return res;
}
-----------
13번문제
#include <iostream>
#include <cstring>
using namespace std;

int main() {

	int i = 0, j = 0;

	cout << "***** 맛집에 오신 것을 환영합니다. *****" << endl;
	while (1)
	{
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>";
		cin >> i;
		if (i == 1)
		{
			cout << "몇인분?";
			cin >> j;
			cout << "짬뽕 " << j << "인분 나왔습니다." << endl;
		}
		else if (i == 2)
		{
			cout << "몇인분?";
			cin >> j;
			cout << "짜장 :" << j << "인분 나왔습니다." << endl;
		}
		else if (i == 3)
		{
			cout << "몇개?";
			cin >> j;
			cout << "군만두 " << j << "개 나왔습니다." << endl;
		}
		else if (i == 4)
		{
			cout << "오늘 영업은 끝났습니다.";
			break;
		}
		else
		{
			cout << "다시 주문하세요!!" << endl;
		}
	}
}
---------
14번문제
#include <iostream>
#include <string>
using namespace std;

int main() {
	char a[50];
	int x;
	int sum = 0;
	int total_sum = 0;
	cout << "에소프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;

	while (total_sum <= 20000) {
		cout << "주문>>";
		cin >>a>>x;
		if (strcmp(a, "에소프레소") == 0) {
			sum = 2000 * x;
			total_sum += sum;
			cout << sum << "원 입니다. 맛있게 드세요" << endl;
		}
		else if (strcmp(a, "아메리카노") == 0) {
			sum = 2300 * x;
			total_sum += sum;
			cout << sum << "원 입니다. 맛있게 드세요" << endl;
		}
		else if (strcmp(a, "카푸치노") == 0) {
			sum = 2500 * x;
			total_sum += sum;
			cout << sum << "원 입니다. 맛있게 드세요"<<endl;
		}
		else {
			cout << "잘 못 입력하셨어요"<<endl;
		}

	}
	cout << "오늘" << total_sum << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
}
-------------
15번문제
#include <iostream>
#include <cstring>
using namespace std;

int main() {

	int num1, num2;
	char Cal;

	while (true)
	{
		cout << "? ";
		cin >> num1 >> Cal >> num2;
		switch (Cal)
		{
		case '+': cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n" << endl;
			break;
		case '-': cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n" << endl;
			break;
		case '*': cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n" << endl;
			break;
		case '/': cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n" << endl;
			break;
		case '%': cout << num1 << " % " << num2 << " = " << num1 % num2 << "\n" << endl;
			break;
		default:
			cout << "잘못입력하셨습니다.";
			break;
		}
	}
}
-----------
16번문제
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {

	int countStack = 0, numCount = 0;
	char buf[10000];

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;

	cin.getline(buf, 10000, ';');

	for (int i = 0; i <= strlen(buf); i++)
	{
		//isalpha(char c)->알파벳인지 검사하기 위한 함수
		//tolower(char c)->대문자를 소문자로 바꾸기 위한 함수
		if (isalpha(buf[i]) != 0)
		{
			buf[i] = tolower(buf[i]);
			numCount++;
		}
	}

	cout << "총 알파벳 수 " << numCount << endl;

	for (char i = 'a'; i <= 'z'; i++)
	{
		for (int j = 0; j <= strlen(buf); j++)
			if (buf[j] == i)
				countStack++;
		cout << i << "(" << countStack << ")" << " : ";
		for (int k = 0; k < countStack; k++)
			cout << "*";
		cout << endl;
		countStack = 0;
	}
}


Wise men say, only fools rush in
But I can't help, falling in love with you

Shall I stay? Would it be a sin?
If I can't help, falling in love with you

Like a river flows, surely to the sea
Darling so it goes, some things aren't meant to be;
*/
