#include <iostream>
#include "Employee.h"

using namespace std;

namespace Records {

    // 생성자: 이름 초기화
    Employee::Employee(const std::string& firstName, const std::string& lastName)
        : mFirstName(firstName), mLastName(lastName) {
    }

    // 연봉 증가
    void Employee::promote(int raiseAmount) {
        setSalary(getSalary() + raiseAmount);
    }

    // 연봉 감소
    void Employee::demote(int demeritAmount) {
        setSalary(getSalary() - demeritAmount);
    }

    // 고용 상태 설정
    void Employee::hire() {
        mHired = true;
    }

    void Employee::fire() {
        mHired = false;
    }

    // 직원 정보 출력
    void Employee::display() const {
        cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
        cout << "------------------------" << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << "Employee Number: " << getEmployeeNumber() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;
    }

    // ===== Setter =====
    void Employee::setFirstName(const string& firstName) {
        mFirstName = firstName;
    }

    void Employee::setLastName(const string& lastName) {
        mLastName = lastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber) {
        mEmployeeNumber = employeeNumber;
    }

    void Employee::setSalary(int newSalary) {
        mSalary = newSalary;
    }

    // ===== Getter =====
    const string& Employee::getFirstName() const {
        return mFirstName;
    }

    const string& Employee::getLastName() const {
        return mLastName;
    }

    int Employee::getEmployeeNumber() const {
        return mEmployeeNumber;
    }

    int Employee::getSalary() const {
        return mSalary;
    }

    bool Employee::isHired() const {
        return mHired;
    }

}
