#include <iostream>
#include <vector>
using namespace std;

int main() {
  

    // 빈 vector 생성
    vector<int> myVector;

    // push_back을 사용하여 요소 추가
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // begin()과 end()를 사용하여 벡터의 요소 순회
    cout << "Vector elements: ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // empty()를 사용하여 벡터가 비어있는지 확인
    if (myVector.empty()) {
        cout << "Vector is empty." << endl;
    } else {
        cout << "Vector size: " << myVector.size() << endl;

        // operator[]를 사용하여 특정 인덱스의 요소에 접근
        cout << "Element at index 1: " << myVector[1] << endl;

        // at()을 사용하여 특정 인덱스의 요소에 접근
        cout << "Element at index 2: " << myVector.at(2) << endl;

        // erase()를 사용하여 특정 인덱스의 요소 제거
        myVector.erase(myVector.begin() + 1); // 두 번째 요소 제거

        // insert()를 사용하여 특정 인덱스에 요소 삽입
        myVector.insert(myVector.begin() + 1, 50); // 두 번째 위치에 50 삽입

        // operator=()를 사용하여 다른 vector로 복사
        vector<int> anotherVector = myVector;

        // 두 번째 vector 출력
        cout << "Copied vector elements: ";
        for (int num : anotherVector) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
