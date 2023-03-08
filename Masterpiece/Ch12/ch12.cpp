#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class SearchWords {
	ifstream fin;
	vector<string> v;
public:
	SearchWords();
	void fileRead(vector<string>& v, ifstream& fin);
	bool exist(string word);
	void search(string word);
	void run();
	~SearchWords();
};

SearchWords::SearchWords() {
	ifstream fin("C:\\tempC++\\words.txt");
	if (!fin) {
		cout << "파일 열기 실패" << endl;
		exit(1);
	}
}

void SearchWords::fileRead(vector<string>& v, ifstream& fin) {
	string line;
	while (getline(fin, line)) {
		v.push_back(line);
	}
	cout << "... words.txt 파일 로딩 완료" << endl;
}

bool SearchWords::exist(string word) {
	for (int i = 0; i < v.size(); i++) {
		if (word == v[i])
			return true;
	}
	return false;
}

void SearchWords::search(string word) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].find(word) == 0)
			cout << v[i] << endl;
	}
}

void SearchWords::run() {
	fileRead(v, fin);

	cout << "검색을 시작합니다. 단어를 입력해주세요." << endl;

	while (true) {
		cout << "단어>>";
		string word;
		getline(cin, word);
		if (word == "exit")
			return;
		if (!exist(word))
			cout << "발견할 수 없음" << endl;
		search(word);
	}

}

SearchWords::~SearchWords() {
	fin.close();
}

int main() {
	SearchWords a;
	a.run();
}



/*
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	fstream fin("c:\\windows\\system.ini", ios::in);
	if(!fin){
		cout<<"파일 열기 실패"<<endl;
		return 0;
	}

	int ch;
	while((ch=fin.get())!=EOF)cout<<(char)toupper(ch);
	fin.close();
}

------
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\Windows\\system.ini");
	ofstream fout("c:\\TempC++\\system.txt");

	if (!fin || !fout) {
		cout << "파일 과정 실패" << endl;
		return 0;
	}

	int ch;
	while ((ch = fin.get()) != EOF) 
		fout << (char)toupper(ch);
		
	fin.close();
	fout.close();
}
----------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;


// 16진수로 출력
void printHexa(char* buf, int n) {
	for (int i = 0; i < 16; i++) {
		cout << setw(2) << setfill('0') << hex << (int)buf[i];

		if (i == n - 1) { //읽은 실제 값 보다 하나 작은 경우 나머지 값들 공백
			cout << ' ';
			for (int j = i + 1; j < 16; j++) {
				cout << setw(2) << setfill(' ') << hex << ' ';
			}
			break;
		}

		if (i == 7)
		{ cout << setw(4) << setfill(' ') << ' '; } //8~9번째 문자 사이에는 4칸의 공백

		else cout << ' '; // 문자 하나 출력 후에는 공백 한 칸
	}
}

// 문자로 출력
void printChar(char* buf, int n) {
	cout << setw(4) << setfill(' ') << ' ';	// hex 라인 출력 후 띄기 위해

	for (int i = 0; i < 16; i++) {
		if (isprint(buf[i]))
			cout << buf[i];
		else
			cout << '.';
		//문자를 읽을 수 있다면 출력하고 아닌 경우에는 .으로 출력

		if (i == n - 1) {  // 읽은 값보다 i가 작다면, 나머지는 그냥 출력 x
			break;
		}

		if (i == 7) cout << setw(4) << setfill(' ') << ' '; // 8-9번쨰 문자 사이에는 4칸의 공백
		else cout << ' ';
	}

}


int main() {
	fstream fin("c:\\Windows\\system.ini", ios::in | ios::binary); // 파일 스트림 객체, 바이너르 모드로 입력을 위해 생성

	if (!fin) {
		cout << "파일 열기 오류" << endl;
		return 0;
	}

	char buf[16];

	while (true) {
		fin.read(buf, 16); // 16바이트만큼씩 읽어서 buf에 저장
		int gc = fin.gcount();
		printHexa(buf, gc);
		printChar(buf, gc);
		cout << endl;

		if (gc < 16) break; // 마지막 줄 읽게 되면 while문 종료
	}

	fin.close();
}

*/

