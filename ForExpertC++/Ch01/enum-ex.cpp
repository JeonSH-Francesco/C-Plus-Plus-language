#include <iostream>
using namespace std;

// 열거형 정의
enum Status {
    IDLE = 0,
    RUNNING = 1,
    STOPPED = 2
};

int main() {
    int input;

    cout << "상태를 입력하세요 (0: IDLE, 1: RUNNING, 2: STOPPED): ";
    cin >> input;

    // 입력값을 enum으로 변환
    Status current = static_cast<Status>(input);

    // 상태에 따라 처리
    switch (current) {
    case IDLE:
        cout << "대기 상태입니다." << endl;
        break;
    case RUNNING:
        cout << "프로그램 실행 중입니다." << endl;
        break;
    case STOPPED:
        cout << "프로그램이 중지되었습니다." << endl;
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
        break;
    }

    return 0;
}
