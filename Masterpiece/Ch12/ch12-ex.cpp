#include <iostream>
#include <fstream>
using namespace std;

long getFileSize(ifstream& fin) {
	fin.seekg(0, ios::end); //get pointer를 파일의 맨 끝으로 옮김
	long length = fin.tellg(); // get pointer의 위치를 알아냄.

	return length;
}


int main() {
	const char* file = "C:\\windows\\system.ini";

	ifstream fin(file);

	if (!fin) {
		cout << file << "열기 오류" << endl;
		return 0;
	}

	cout << file << "의 크기는 " << getFileSize(fin);
	fin.close();

}



/*
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

	string name, dept,strsid;
	int sid;

	//키보드로부터 읽기
	cout << "이름 >> ";
	getline(cin, name);

	cout << "학번 >> ";
	cin >> sid;
	getline(cin, strsid);

	cout << "학과 >> ";
	getline(cin, dept);

	//파일 열기. students.txt 파일을 열고, 출력 스트림 생성

	ofstream fout("c:\\tempC++\\student.txt");

	if (!fout) {
		cout << "c:\\tempC++\\student.txt 파일을 열 수 없다.";
		return 0;
	}

	//파일 쓰기
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	//파일 종료
	fout.close();

}
-------
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	//스트림 객체 생성 및 파일 열기
	ifstream fin;
	fin.open("C:\\tempC++\\student.txt");

	if (!fin) {
		cout << "파일을 열 수 없다.";
		return 0;
	}

	string name,strsid, dept;

	fin >> name;
	fin >> strsid;
	fin >> dept;

	cout << name << endl;
	cout << strsid << endl;
	cout << dept << endl;

	fin.close();

}
---------
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	ifstream ifile;

	char line[200]; // 한 줄씩 읽어서 임시로 저장할 공간

	ifile.open("C:\\tempC++\\student.txt");  // 파일 열기

	if (ifile.is_open())
	{
		while (ifile.getline(line, sizeof(line))) // 한 줄씩 읽어 처리를 시작한다.
		{
			cout << line << endl; // 내용 출력
		}
	}

	ifile.close(); // 파일 닫기

	return 0;
}

----------
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini"; //읽을 파일 명
	ifstream fin(file);
	if (!fin) {
		cout << file << "열기 오류" << endl;
		return 0;
	}

	int count = 0;
	int c = 0;

	while ((c=fin.get())!=EOF) { //EOF를 만날 때까지 읽음
		cout << (char)c; //읽은 문자를 화면에 출력
		count++; //읽은 문자 개수 카운트
	}

	cout << "읽은 바이트 수는" << count << endl;
	fin.close();

}
-------
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* firstFile = "경로명과 파일명";
	const char* secondFile = "경로명과 파일명";

	fstream fout(firstFile, ios::out | ios::app); //쓰기 모드로 파일 열기
	
	if (!fout) {
		cout << firstFile << "열기 오류";
		return 0;
	}

	fstream fin(secondFile, ios::in); //읽기 모드로 파일 열기
	if (!fin) { //열기 실패 검사
		cout << secondFile << "열기 오류";
		return 0;
	}

	int c;
	while (c = fin.get() != EOF) {
		fout.put(c);
	}

	fin.close();
	fout.close();
}
---------
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void fileRead(vector<string>& v, ifstream& fin) { // fin 스트림으로부터 벡터 v에 읽어들임
	string line;
	while (getline(fin, line)) { // fin 파일에서 한 라인 읽기
		v.push_back(line); // 읽은 라인을 벡터에 저장
	}
}

void search(vector<string>& v, string word) { // 벡터 v에서 word를 찾아 출력
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);
		if (index != -1) // found
			cout << v[i] << endl;
	}
}

int main() {
	vector<string> wordVector;
	ifstream fin("C:\\tempC++\\words.txt");

	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다" << endl;
		return 0; // 열기 오류
	}
	fileRead(wordVector, fin); // fin 스트림으로부터 wordVector에 라인 별로 읽기
	fin.close();

	cout << "words.txt 파일을 읽었습니다." << endl;
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
-----
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream fin("C:\\tempC++\\words.txt");

	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다." << endl;
	}

	//fin.open("경로명 txt명");

	string line;

	while (!fin.eof()) {
		getline(fin, line);
		cout << line << endl;
	}


	fin.close();
}
--------
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//소스 파일과 목적 파일의 이름
	const char* srcFile = "c:\\tempC++\\a.jpg";
	const char* destFile = "c:\\tempC++\\a_copy.jpg";

	//소스 파일 열기
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc){
		cout << srcFile << "열기 오류" << endl;
		return 0;
	}

	//목적 파일 열기
	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << "열기 오류" << endl;
		return 0;
	}


	int c = 0;
	while ((c = fsrc.get()) != EOF) {
		fdest.put(c);
	}

	cout << srcFile << "을" << destFile << "로 복사 완료"<<endl;

	fsrc.close();
	fdest.close();

}
--------
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//소스 파일과 목적 파일의 이름
	const char* srcFile = "c:\\tempC++\\a.jpg";
	const char* destFile = "c:\\tempC++\\a_copy.jpg";

	//소스 파일 열기
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << "열기 오류" << endl;
		return 0;
	}

	//목적 파일 열기
	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << "열기 오류" << endl;
		return 0;
	}

	int c = 0;
	while ((c = fsrc.get()) != EOF) { //소스 파일을 끝가지 한 바이트 씩 읽는다.
		fdest.put(c); //읽은 바이트를 파일에 출력한다.
	}
	cout << srcFile << "을" << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();

}
------
#include <iostream>
#include <fstream>
using namespace std;

//istream& read(char *s,int n)
//->파일에서 최대 n개의 바이트를 배열 s에 읽어 들임. 파일의 끝을 만나면 읽기 중단
//ostream& write(char *s,int n)
//->배열 s에 있는 처음 n개의 바이트를 파일에 저장
//int gcount()
//->최근에 파일에서 읽은 바이트 수 리턴


int main() {
	const char* file = "c:\\windows\\system.ini";

	ifstream fin;
	fin.open(file, ios::in | ios::binary); //바이너리 I/O 모드로 파일 열기

	if (!fin) { //열기 실패 검사
		cout << "파일 열기 오류";
		return 0;
	}

	int count = 0;
	char s[32]; //블록 단위로 읽어 들일 버퍼

	while (!fin.eof()) { //파일 끝까지 읽는다.
		fin.read(s, 32);//최대 32바이트를 읽어 배열 s에 저장
		int n = fin.gcount(); //실제 읽은 바이트 수 알아냄.
		cout.write(s, n);//버퍼에 있는 n개의 바이트를 화면에 출력
		count+= n;
	}

	cout << "읽은 바이트 수: "<<count << endl;
	fin.close();//입력 파일 닫기


}
-------
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//소스 파일과 목적 파일의 이름
	const char* srcFile = "C:\\tempC++\\moon.jpg";
	const char* destFile = "C:\\tempC++\\copy_moon.jpg";

	//소스 파일 열기
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << "열기 오류" << endl;
		return 0;
	}
	//목적 파일 열기
	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << "열기 오류" << endl;
		return 0;
	}

	//소스 파일에서 목적 파일로 복사하기
	char buf[1024];
	while (!fsrc.eof()) {//파일 끝까지 읽는다/
		fsrc.read(buf, 1024);//최대 1024바이트를 읽어 배열 s에 저장
		int n = fsrc.gcount();//실제 읽은 바이트 수 알아냄.
		fdest.write(buf, n); //읽은 바이트 수 만큼 버퍼에서 목적 파일에 기록
	}
	cout << srcFile << "을" << destFile << "로 복사 완료" << endl;

	fsrc.close();
	fdest.close();
}
------
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\tempC++\\data.dat";

	ofstream fout;
	fout.open(file, ios::out | ios::binary); // 읽기 모드로 파일 열기
	if (!fout) { // 열기 실패 검사
		cout << "파일 열기 오류";
		return 0;
	}

	int n[] = { 0,1,2,3,4,5,6,7,8,9 };
	double d = 3.15;

	fout.write((char*)n, sizeof(n)); // int 배열 n을 한 번에 파일에 쓴다.
	fout.write((char*)(&d), sizeof(d)); // double 값 하나를 파일에 쓴다.

	fout.close();

	// 배열 n과 d 값을 임의의 값으로 변경시킨다.
	for (int i = 0; i < 10; i++) n[i] = 99;
	d = 8.15;

	// 배열 n과 d 값을 파일에서 읽어 온다.
	ifstream fin(file, ios::in);
	if (!fin) { // 열기 실패 검사
		cout << "파일 열기 오류";
		return 0;
	}

	fin.read((char*)n, sizeof(n)); // int 배열을 한 번에 읽오 온다.
	fin.read((char*)(&d), sizeof(d)); // double 값을 읽어 온다.

	for (int i = 0; i < 10; i++) // 읽은 배열 n을 확인한다.
		cout << n[i] << ' ';
	cout << endl << d << endl; // 읽은 double 값을 확인한다.
	fin.close();
}
----
#include <iostream>
#include <fstream>
using namespace std;

//eof() 파일의 끝을 만났을 때(eofbit=1) true를 리턴
//fail() failbit()나 badbit가 1로 세팅되었을 때 true 리턴
//bad() badbit이 1로 세팅되었을 때 true 리턴
//good() 스트림이 정상적(모든 비트가0)일때 true 리턴
//clear() 스트림 상태 변수를 0으로 지움

void showStreamState(ios& stream) {
	cout << "eof()" << stream.eof() << endl;
	cout << "fail()" << stream.fail() << endl;
	cout << "bad()" << stream.bad() << endl;
	cout << "good()" << stream.good() << endl;
}

int main() {
	const char* noExistFile = "c:\\tempC++\\noexist.txt";
	const char* existFile = "c:\\tempC++\\student.txt";

	ifstream fin(noExistFile);

	if (!fin) {
		cout << noExistFile << "열기 오류" << endl;
		showStreamState(fin); // 스트림 상태 출력

		cout << existFile << "파일 열기" << endl;
		fin.open(existFile);
		showStreamState(fin); // 스트림 상태 출력
	}

	//스트림을 끝까지 읽고 화면에 출력
	int c = 0;
	while ((c = fin.get()) != EOF) {
		cout.put((char)c);
	}
	cout << endl;
	showStreamState(fin); //스트림 상태 출력

	fin.close();
}

*/
