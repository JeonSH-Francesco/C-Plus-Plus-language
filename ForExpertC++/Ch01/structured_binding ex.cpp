#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
    pair<int, string> p = { 1, "Alice" };

    // 구조적 바인딩 (참조 사용: 복사 방지)
    const auto& [id, name] = p;

    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;

    return 0;
}
