#pragma once
// #pragma once:
// 헤더 파일이 여러 번 include 되는 것을 방지 (중복 정의 에러 방지)

#include <string>

namespace Records {

    // 기본 시작 연봉 (상수)
    const int kDefaultStartingSalary = 30000;

    // 직원 클래스 (데이터 + 행동을 묶는 객체)
    class Employee {
    public:
        // 기본 생성자 (아무 값도 초기화 안 함)
        Employee() = default;

        // 이름을 받아서 생성하는 생성자
        Employee(const std::string& firstName, const std::string& lastName);

        // 연봉 인상 (기본값: 1000)
        void promote(int raiseAmount = 1000);

        // 연봉 삭감 (기본값: 1000)
        void demote(int demeritAmount = 1000);

        // 고용 상태 변경
        void hire();  // 고용
        void fire();  // 해고

        // 직원 정보 출력 (멤버 변경 없음 → const)
        void display() const;

        // ===== Getter / Setter =====
        // 외부에서 직접 접근 못하게 하고, 함수로 통제

        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;
        // const reference:
        // 복사 없이 반환 + 수정 불가

        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;

        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;

        void setSalary(int newSalary);
        int getSalary() const;

        bool isHired() const;

    private:
        // ===== 멤버 변수 (외부 접근 불가) =====
        std::string mFirstName;
        std::string mLastName;

        int mEmployeeNumber = 1;
        int mSalary = kDefaultStartingSalary;

        bool mHired = false;
    };

}
