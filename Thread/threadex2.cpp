#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::vector;
using namespace std;


//worker 함수는 덧셈을 수행할 데이터의 시작점과 끝점을 받아서 해당 범위 내의 원소들을 모두 더한 후
//결과를 result에 저장하게 됩니다.
//참고로 쓰레드는 리턴 값이란 것이 없기 때문에 만일 어떠한 결과를 반환하고 싶다면 포인터의 형태로 전달하면 됩니다.
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

//std::cout << "쓰레드 " << hex << this_id << " 에서 " << dec << *start << " 부터 "<< *(end - 1) << " 까지 계산한 결과 : " << sum << std::endl;
//->이렇게 하면 뒤죽박죽으로 실행 결과가 나오게 된다.
//-> 이유 : std :: cout << A; 의 경우 
//A의 내용이 출력되는 동안 중간에 다른 쓰레드가 내용을 출력할 수 없게 보장을 해줌.
//하지만, std:: cout << A << B;를 하게 되면 A를 출력한 이후에 B를 출력하기 전에 다른 쓰레드가 내용을 출력할 수 있어서 그렇게 됨.
//따라서 printf를 사용하게 되면 context switching이 되더라도 다른 쓰레드들이 그 사이에 메시지를 집어넣지 못하게 막습니다.
//ref : https://stackoverflow.com/questions/23586682/how-to-use-printf-in-multiple-threads

int main() {
    vector<int> data(10000);
    for (int i = 0; i < 10000; i++) {
        data[i] = i;
    }

    //각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
    vector<int> partial_sums(4);
    vector<thread> workers;
    //각 worker 들이 덧셈을 수행해야 할 범위는 2500씩 끊어서 수행할 수 있도록
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
