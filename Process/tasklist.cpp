#include <iostream>
#include <cstdio>   // for _popen, _pclose
#include <memory>   // for std::unique_ptr
#include <array>    // for std::array

using namespace std;

int main() {
    // 실행할 명령어
    string command = "tasklist";

    // _popen을 통해 명령어 실행 및 결과 읽기
    array<char, 128> buffer;
    unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(command.c_str(), "r"), _pclose);
    if (!pipe) {
        cerr << "_popen() failed!" << endl;
        return 1;
    }

    // 명령어의 출력을 한 줄씩 읽어와 출력
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        cout << buffer.data();
    }

    return 0;
}
