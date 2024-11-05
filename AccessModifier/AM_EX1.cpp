#include <iostream>
using namespace std;

class Example {
public:
    int publicVar;           // public 멤버
protected:
    int protectedVar;        // protected 멤버
private:
    int privateVar;          // private 멤버

public:
    Example(int pub, int prot, int priv) {
        this->publicVar = pub;           // public 멤버 접근
        this->protectedVar = prot;       // protected 멤버 접근
        this->privateVar = priv;         // private 멤버 접근
    }

    void display() {
        cout << "Public: " << this->publicVar << endl;
        cout << "Protected: " << this->protectedVar << endl;
        cout << "Private: " << this->privateVar << endl;
    }
};

class Derived : public Example {
public:
    Derived(int pub, int prot, int priv) : Example(pub, prot, priv) {}

    void show() {
        cout << "Accessing from Derived class:" << endl;
        cout << "Public: " << this->publicVar << endl;        // 접근 가능
        cout << "Protected: " << this->protectedVar << endl;  // 접근 가능
        // cout << "Private: " << this->privateVar << endl;   // 접근 불가 (컴파일 오류)
    }
};

int main() {
    Example ex(1, 2, 3);
    ex.display();

    Derived d(4, 5, 6);
    d.show();

    return 0;
}


/*
Public: 1
Protected: 2
Private: 3
Accessing from Derived class:
Public: 4
Protected: 5

*/
