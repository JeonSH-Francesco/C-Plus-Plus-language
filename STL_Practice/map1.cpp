#include <iostream>
#include <map>
using namespace std;

int main() {

    // 빈 map 생성
    map<string, int> myMap;

    // insert()를 사용하여 키-값 쌍 추가
    myMap.insert(make_pair("one", 1));
    myMap.insert(make_pair("two", 2));
    myMap.insert(make_pair("three", 3));

    // begin()과 end()를 사용하여 map의 요소 순회
    cout << "Map elements: ";
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "(" << it->first << ":" << it->second << ") ";
    }
    cout << endl;

    // empty()를 사용하여 map이 비어있는지 확인
    if (myMap.empty()) {
        cout << "Map is empty." << endl;
    } else {
        cout << "Map size: " << myMap.size() << endl;

        // operator[]를 사용하여 특정 키의 값을 접근
        cout << "Value for key 'two': " << myMap["two"] << endl;

        // find()를 사용하여 특정 키를 검색
        auto found = myMap.find("three");
        if (found != myMap.end()) {
            cout << "Key 'three' found. Value: " << found->second << endl;
        }

        // erase()를 사용하여 특정 키의 요소 제거
        myMap.erase("two");

        // insert()를 사용하여 키-값 쌍 추가 (또 다른 방법)
        myMap["four"] = 4;

        // operator=()를 사용하여 다른 map으로 복사
        map<string, int> anotherMap = myMap;

        // 두 번째 map 출력
        cout << "Copied map elements: ";
        for (const auto& pair : anotherMap) {
            cout << "(" << pair.first << ":" << pair.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
