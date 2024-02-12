#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::vector;
using namespace std;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
    int sum = 0;
    for (auto itr = start; itr < end; ++itr) {
        sum += *itr;
    }
    *result = sum;


//스레드의 id를 구한다.
thread::id this_id = std::this_thread::get_id();
printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start,*(end - 1), sum);
}

int main() {
    vector<int> data(10000);
    for (int i = 0; i < 10000; i++) {
        data[i] = i;
    }

    //각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
    vector<int> partial_sums(4);
    vector<thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += partial_sums[i];
    }
    cout << "전체 합 : " << total << endl;
}
