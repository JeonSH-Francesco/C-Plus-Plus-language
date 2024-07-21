#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>  //std::hex 및 std::setw 사용을 위해 필요

using namespace std;

int main() {
	//현재 시간을 time_t 형식으로 가져오기
	time_t currentTime = time(nullptr);

	//time_t를 16진수 형식으로 출력
	cout << "Current timestamp in hex: 0x" << hex << currentTime << endl;

	//현재 시간을 tm 구조체 형식으로 변환
	tm* localTime = localtime(&currentTime);


	//tm 구조체를 사용하여 현재 시간을 사람이 읽을 수 있는 형식으로 출력
	cout << "Current local time: " << asctime(localTime);

	// tm 구조체의 각 필드를 16진수 형식으로 출력
	cout << "Year: 0x" << hex << (localTime->tm_year + 1900) << endl;
	cout << "Month: 0x" << hex << (localTime->tm_mon + 1) << endl;
	cout << "Day: 0x" << hex << localTime->tm_mday << endl;
	cout << "Hour: 0x" << hex << localTime->tm_hour << endl;
	cout << "Minute: 0x" << hex << localTime->tm_min << endl;
	cout << "Second: 0x" << hex << localTime->tm_sec << endl;


	//각 필드를 이어 붙여 하나의 16진수 문자열로 만들기
	//setw(n)은 출력 필드의 너비를 n으로 설정합니다.
	//setfill('0')은 필드의 남은 공간을 '0'으로 채웁니다.
	//예를 들어, setw(4) << setfill('0') << hex << (localTime->tm_year + 1900)는 년도를 4자리 16진수로 출력합니다.
	//년도는 4자리, 월, 일, 시간, 분, 초는 각각 2자리로 포맷팅 Go Go.
	cout << "Combined Hex Time: 0x"
		<< setw(4) << setfill('0') << hex << (localTime->tm_year + 1900)
		<< setw(2) << setfill('0') << hex << (localTime->tm_mon + 1)
		<< setw(2) << setfill('0') << hex << localTime->tm_mday
		<< setw(2) << setfill('0') << hex << localTime->tm_hour
		<< setw(2) << setfill('0') << hex << localTime->tm_min
		<< setw(2) << setfill('0') << hex << localTime->tm_sec
		<< endl;

	return 0;
}
