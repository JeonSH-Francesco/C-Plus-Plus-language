#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

 // fin 스트림으로부터 벡터 v에 읽어들임
void fileRead(vector<string>& v, ifstream& fin) {
	string line;
  
	while (getline(fin, line)) { // fin 파일에서 한 라인 읽기
		v.push_back(line); // 읽은 라인을 벡터에 저장
	}
  
}

 // 벡터 v에서 word를 찾아 출력
void search(vector<string>& v, string word) {
  
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);
		if (index != -1) // found
			cout << v[i] << endl;
	}
  
}

int main() {
	vector<string> wordVector;
	ifstream fin("경로명 파일명"); //사용자 맞게 수정 필요

	if (!fin) {
		cout << "파일을 열 수 없습니다" << endl;
		return 0; // 열기 오류
	}
  
	fileRead(wordVector, fin); // fin 스트림으로부터 wordVector에 라인 별로 읽기
	fin.close();

	cout << "파일을 읽었습니다." << endl;
	while (true) {
		cout << "검색할 단어를 입력하세요 >>";
		string word;
		getline(cin, word); // 키보드로부터 문자열 읽기
		if (word == "exit")
			break; // 프로그램 종료
		search(wordVector, word); // 문자열을 words.txt에서 검색하여 출력
	}
	cout << "프로그램을 종료합니다." << endl;
}
