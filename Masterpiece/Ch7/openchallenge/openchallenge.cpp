#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text; //문자열
	int alpha[26] = {0}; // 각 알파벳 갯수 배열
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
	this->text +=c;
	return *this;
}

void Histogram::operator!() {
	int count = 0; // 전체 알파벳 수
	char c;
		for(int i = 0; i < text.length(); i++) {
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
			for (int j = 0; j<alpha[i]; j++) {
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
