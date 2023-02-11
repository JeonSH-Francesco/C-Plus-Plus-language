#include <iostream>
using namespace std;
// 값에 의한 호출
void copy(int dest, int src) {
	dest = src;
}

int main() {
	int a = 4, b = 5;
	copy(a, b);
	cout << "a: "<< a <<" b: "<< b<< endl;
}
----------
#include <iostream>
using namespace std;
// 주소에 의한 호출
void copy(int *dest, int *src) {
	*dest = *src;
}

int main() {
	int a = 4, b = 5;
	copy(&a, &b);
	cout << "a: " << a << " b: " << b << endl;
}

----------
#include <iostream>
using namespace std;
// 참조에 의한 호출
void copy(int &dest, int src) {
	dest = src;
}

int main() {
	int a = 4, b = 5;
	copy(a, b);
	cout << "a: " << a << " b: " << b << endl;
}
