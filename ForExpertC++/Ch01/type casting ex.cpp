#include <iostream>
using namespace std;

int main() {
    float myFloat = 3.14f;

    // C 스타일 캐스팅 (옛날 방식)
    int i1 = (int)myFloat;

    //함수 스타일 캐스팅
    int i2 = int(myFloat);

    //  C++ 스타일 캐스팅 (권장)
    int i3 = static_cast<int>(myFloat);

    cout << "Original float: " << myFloat << endl;
    cout << "C-style cast: " << i1 << endl;
    cout << "Function-style cast: " << i2 << endl;
    cout << "static_cast: " << i3 << endl;

    return 0;
}
