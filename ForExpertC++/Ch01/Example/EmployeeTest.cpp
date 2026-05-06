#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;
// Records::Employee → Employee로 간단히 사용 가능

int main() {
    cout << "Test Start" << endl;

    // 기본 생성자 사용
    Employee emp;

    // 값 설정
    emp.setFirstName("John");
    emp.setLastName("Doe");
    emp.setEmployeeNumber(71);
    emp.setSalary(50000);

    // 연봉 변경
    emp.promote();      // +1000 (기본값)
    emp.promote(50);    // +50

    // 고용 상태
    emp.hire();

    // 출력
    emp.display();

    return 0;
}
