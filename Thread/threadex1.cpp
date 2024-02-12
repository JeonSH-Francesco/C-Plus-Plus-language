#include <iostream>
#include <thread>
using std::thread;

void func1() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 1 작동중! \n";
    }
}

void func2() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 2 작동중! \n";
    }
}

void func3() {
    for (int i = 0; i < 10; i++) {
        std::cout << "쓰레드 3 작동중! \n";
    }
}

int main() {
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);

    t1.join();
    t2.join();
    t3.join();

}
//join 함수는 해당하는 쓰레드들이 실행을 종료하면 리턴하는 함수 입니다.
//join 함수를 사용하지 않으면 쓰레드들의 내용이 채 실행되기 전에 main 함수가 종료되어서
//쓰레드 객체들의 소멸자가 호출됩니다.

//C++ 표준에 따르면, join 되거나 detach 되지 않는 쓰레드들의 소멸자가 호출된다면 예외를 발생시키도록 명시되어 있습니다.

//detach 함수를 해당 쓰레드를 실행 시킨 후, 잊어버리는 것이다.
