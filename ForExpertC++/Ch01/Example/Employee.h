#pragma once
// pragma once는 같은 파일을 여러 번 include 하지 않도록 방지

#include <string>

namespace Records {
    const int kDefaultStartingSalary = 30000;

    class Employee {
    public:
        Employee() = default;
        Employee(const std::string& firstName, const std::string& lastName);

        void promote(int raiseAmount = 1000);
        void demote(int demeritAmount = 1000);

        void hire();
        void fire();
        void display() const; // 직원 정보 출력

        // getter & setter
        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;

        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;

        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;

        void setSalary(int newSalary);
        int getSalary() const;

        bool isHired() const;

    private:
        std::string mFirstName;
        std::string mLastName;
        int mEmployeeNumber = 1;
        int mSalary = kDefaultStartingSalary;
        bool mHired = false;
    };

}
