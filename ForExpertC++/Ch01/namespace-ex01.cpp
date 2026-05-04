#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

/*
namespace는 이름 충돌응ㄹ 방지하고, 기능을 논리적으로 그룹화 하는 코드 영역으로
같은 이름의 함수/변수도 다른 namespace에 있으면 공존 가능
대형 프로젝트에서 모듈, 계층, 책임 분리할 때 필수
Company
 └─ Security
     ├─ Memory
     │   └─ SecureErase()
     └─ Auth
         └─ Login()
*/


namespace Company {
    namespace Security {
        namespace Memory {

            void SecureErase(void* ptr, size_t size) {
                if (ptr == nullptr || size == 0) return;
                SecureZeroMemory(ptr, size);
            }
        }

        namespace Auth {

            // 간단한 사용자 정보 (실무에서는 DB/해시 사용)
            struct User {
                string username;
                string password;
            };

            bool Login() {
                string inputId;
                string inputPw;

                cout << "ID 입력: ";
                cin >> inputId;

                cout << "PW 입력: ";
                cin >> inputPw;

                // 가짜 DB 사용자
                User dbUser = { "admin", "1234" };

                bool success = false;

                if (inputId == dbUser.username &&
                    inputPw == dbUser.password) {
                    cout << "Login success\n";
                    success = true;
                }
                else {
                    cout << "Login failed\n";
                }


                if (!inputPw.empty()) {
                    Company::Security::Memory::SecureErase(&inputPw[0], inputPw.size());
                }

                return success;
            }
        }
    }
}

int main() {
    Company::Security::Auth::Login();
    return 0;
}
