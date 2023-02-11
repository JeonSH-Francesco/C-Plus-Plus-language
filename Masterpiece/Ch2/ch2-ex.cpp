/*

#include <iostream>

using namespace std;

int main() {
	int i=0, j=0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j <=i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;

}
#include <iostream>

using namespace std;

int main() {
	int i=0, j=0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j <4-i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;

}
-----------
#include <iostream>
using namespace std;

int main() {
	int r;
	cin >> r;
	double a;
	a = 3.14 * r * r;
	cout << a;

	return 0;
}

----------
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char password[11];
	cout << "프로그램을 종료하려면 암호를 입력하세요."<<endl;
	while (true) {
		cout << "암호 : ";
		cin >> password;
		if (strcmp(password, "C++") == 0) {
			cout << "접근이 허가되었습니다." << endl;
			break;
		}
		else {
			cout << "암호가 틀립니다!" << endl;
		}
	}


}
-----------

#include <iostream>
using namespace std;

int main() {
	cout << "주소를 입력하세요>>\n";
	char address[100];

	cin.getline(address, 100, '\n'); //키보드로부터 주소 읽기

	cout << "주소는 " << address << "입니다.\n";
}
// cin.getline(char buf[],int size,char delimitChar)
//buf : 키보드로부터 읽은 문자열을 저장할 배열
//size : buf[]의 배열의 크기
//delimitChar : 문자열 입력 끝을 지정하는 구분 문자

----------------------------------
#include <iostream>
#include <string>
using namespace std;

int main() {
	string year("2022");
	string topgun("Top gun Maverick");

	string movie;

	cout << year + "년도에 가장 유명한 영화는?";
	cout << "(힌트 : 첫 글자는" << topgun[0] << ") :";

	getline(cin, movie);

	if (movie == topgun) {
		cout << "Correct"<<endl;
	}
	else {
		cout << "No. The answer is Top gun Maverick."<<endl;
	}

}






*/
