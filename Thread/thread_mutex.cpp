#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
  for (int i = 0; i < 10000; i++) {
    m.lock();
    result += 1;
    m.unlock();
  }
}

int main() {
  int counter = 0;
  std::mutex m;  // 우리의 mutex 객체

  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++) {
    workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;
}
/*

#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::vector;

void worker(int& counter) {
  for (int i = 0; i < 10000; i++) {
    counter += 1;
  }
}

int main() {
  int counter = 0;

  vector<thread> workers;
  for (int i = 0; i < 4; i++) {
    // 레퍼런스로 전달하려면 ref 함수로 감싸야 한다 (지난 강좌 bind 함수 참조)
    workers.push_back(thread(worker, std::ref(counter)));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;
}*/
