#include <iostream>
using namespace std;

// 같은 타입 → int
auto addInt(int a, int b) {
    return a + b;  // int
}

// 다른 타입 → double로 승격
auto addMixed(double a, int b) {
    return a + b;  // double
}

// 조건 분기 → 반드시 같은 타입이어야 함
auto getValue(bool flag) {
    if (flag)
        return 10.0;   // double
    else
        return 20.5;   // double (같은 타입으로 맞춤)
}

int main() {
    auto r1 = addInt(3, 2);        // int
    auto r2 = addMixed(3.5, 2);    // double
    auto r3 = getValue(true);      // double

    cout << "r1 (int): " << r1 << endl;
    cout << "r2 (double): " << r2 << endl;
    cout << "r3 (double): " << r3 << endl;

    return 0;
}
