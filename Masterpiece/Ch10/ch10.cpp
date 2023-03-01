#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    virtual void draw() = 0;
public:
    void paint() { draw(); }
};

class Circle : public Shape {
protected:
    virtual void draw() { cout << "Circle" << endl; }
};

class Rect : public Shape {
protected:
    virtual void draw() { cout << "Rectangle" << endl; }
};

class Line : public Shape {
protected:
    virtual void draw() { cout << "Line" << endl; }
};

class UI {
public:
    static int selectMenu() {
        int n;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> n;

        return n;
    }
    static int selectShape() {
        int n;
        cout << "선:1, 원:2, 사각형:3 >> ";
        cin >> n;
        return n;
    }
    static int selectDelIndex() {
        int n;
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        cin >> n;
        return n;
    }
    static void showAll(vector<Shape*>& v, vector<Shape*>::iterator& it) {
        int i = 0;
        for (it = v.begin(); it != v.end(); it++, i++) { // vector v의 첫 원소부터 끝 원소까지 탐색 및 출력
            cout << i << ": ";
            v.at(i)->paint();
        }
    }
};

class GraphicEditor {
    vector<Shape*> v;
    vector<Shape*>::iterator it;
public:
    GraphicEditor() {
        cout << "그래픽 에디터입니다.\n";
        start();
    }
    void start() {
        
        while (true) {
            int n;
            n = UI::selectMenu();


            switch (n) {
            case 1: //삽입을 선택한 경우
                n = UI::selectShape();
                switch (n) {
                case 1: //선을 선택한 경우
                    v.push_back(new Line());
                    break;
                case 2: //원을 선택한 경우
                    v.push_back(new Circle());
                    break;
                case 3: //사각형을 선택한 경우
                    v.push_back(new Rect());
                    break;
                default:
                    cout << "잘못 선택하셨습니다.\n";
                    break;
                }
                break;

            case 2: { //삭제를 선택한 경우
                n = UI::selectDelIndex();
                if (n >= v.size() || n < 0) { // 없는 인덱스에 대한 예외처리
                    cout << "없는 인덱스 입니다.\n";
                    break;
                }
                it = v.begin();
                Shape* tmp = *(it + n); // vector에서 원소가 삭제되고 난 후 객체 delete를 위해 저장
                v.erase(it + n); // it+n 위치에 있는 원소 삭제
                delete tmp; // vector에서 삭제된 객체 delete
                break;
            }

            case 3: //모두 보기를 선택한 경우
                UI::showAll(v, it); //매개변수로 vector v와 v의 iterator를 넘김
                break;

            case 4: // 종료를 선택한 경우
                return; //프로그램 종료

            default:
                cout << "잘못 입력하셨습니다.\n";
                break;
            }
        }
    }

};

int main() {
    new GraphicEditor();
}







/*
#include <iostream>
using namespace std;

template <class T> class Container {
    T* p; //T 타입의 포인터  p 선언
    int size; //배열 크기를 나타내는 변수 size 선언
public:
    Container(int n); //멤버 변수 p에 n개의 동적 배열을 할당 받는 생성자
    ~Container();
    void set(int index, T value) { //index 위치에 value 저장
        p[index] = value;
    }
    T get(int index); //index 위치 값 리턴
};


template <class T> Container<T> ::Container(int n) {
    p = new T[n];
    size = n;
}

template <class T> Container<T> ::~Container() {
    delete []p;
}

template <class T> T Container <T> ::get(int index) {
    return p[index];
}

int main() {

    Container <char> c(26);
    for (int i = 0; i < 26; i++) {
        c.set(i, 'a' + i);
    }
    for (int i = 25; i >= 0; i--) {
        cout << c.get(i) << ' ';
    }
}
-----------
1번문제
#include <iostream>
using namespace std;

template <class T>
T biggest(T arr[], T n) {
    T big = arr[0];
    for (int i = 0; i <= n; i++)
        if (arr[i] > big)
            big = arr[i];
    return big;
}

int main() {
    int big = 0;
    int x[] = { 1, 10, 100, 5, 4 };
    cout << biggest(x, 5) << endl;
}
------
2번문제
#include <iostream>
using namespace std;

template <class T>
bool equalArrays(T a[], T b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}


int main() {
    int x[] = { 1,10,100,5,4 };
    int y[] = { 1,10,100,5,4 };

    if (equalArrays(x, y, 5)) cout << "같다" << endl;
    else cout << "다르다" << endl;

}
-------
3번문제
#include <iostream>
using namespace std;

template <class T>
void reverseArray(T a[],int n) {
    for (int i = 0; i < n / 2; i++) {
        T tmp= a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmp;
    }
}


int main() {
    int x[] = { 1,10,100,5,4 };


    reverseArray(x, 5);
    for (int i = 0; i < 5; i++) cout << x[i] << ' ';

}
----
4번문제
#include <iostream>
using namespace std;

template <class T>
bool search(T target, T arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return true;
    }
    return false;
}

int main() {
    int x[] = { 1,10,100,5,4 };

    if (search(100,x,5)) cout << "100이 배열 x에 포함되어 있다";
    else cout << "100이 배열 x에 포함되어 있지 않다.";

}
----
5번문제
#include <iostream>
using namespace std;

template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
    T* p = new T[sizea + sizeb];
    for (int i = 0; i < sizea; i++) {
        p[i] = a[i];
    }
    for (int i = 0; i <sizeb; i++) {
        p[i+sizea] = b[i];
    }
    return p;
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };
    int y[] = { 12, 13, 14, 15 };
    int* a = concat(x, 5, y, 4);

    int aSize = sizeof(x) / sizeof(x[0]) + sizeof(y) / sizeof(y[0]); // a에 들어있는 원소의 개수

    for (int i = 0; i < aSize; i++)
        cout << a[i] << ' ';
}
---
6번문제
#include <iostream>
using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus,int &retSize) {
    T* tmp = new T[sizeSrc + sizeMinus];

    int size = 0, i, j;

    for (i = 0; i < sizeSrc; i++) {
        for (j = 0; j < sizeMinus; j++) {
            if (src[i] == minus[j]) break;

        }
        if (j == sizeMinus) tmp[retSize++] = src[i];
    }

    return tmp;
}

int main() {
    int x[] = { 1,2,3,4,5};
    int y[] = { 1,3,5 };
    int retSize = 0;

    int* p = remove(x, 5, y, 4, retSize);
    for (int i = 0; i < retSize; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;

    delete[] p;

}
--
13번문제
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, int> Score; //map 컨테이너 생성->key = 이름, value= 점수

    cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다. *****" << endl;

    while (true) {
        int num;

        string name;
        int score;

        cout << "입력 :1, 조회:2, 종료:3>>";
        cin >> num;
        switch (num) {
            case 1:
                cout << "이름과 점수>>";
                cin >> name >> score;
                Score.insert(make_pair(name, score)); //map에 저장
                break;
            case 2:
                cout << "이름 >>";
                cin >> name;
                if (Score.find(name) == Score.end()) //name(key)를 끝까지 찾았는데 없는 경우
                    cout << "없음" << endl;
                else
                    cout << name << "의 점수는" << Score[name] << endl;
                break;
            case 3:
                cout << "프로그램을 종료합니다..." << endl;
                return 0;
            default:
                break;
        }

    }

}
----
14번문제
#include <iostream>
#include <map>
using namespace std;

void insert(map<string, string>& pwManager) {
    string name, pw;
    cout << "이름과 암호를 입력하세요>>";
    cin >> name >> pw;
    pwManager.insert(make_pair(name, pw));
}

void checkNamePw(map<string, string>& pwManager) {
    string name, pw;
    cout << "이름?";
    cin >> name;

    while (true) {
        cout << "암호?";
        cin >> pw;
        if (pwManager[name] == pw) {
            cout << "통과!!" << endl;
            break;
        }
        else
            cout << "실패~~" << endl;
    }
}

int main() {
    map<string, string> pwManager;
    cout << "***** 암호 프로그램 WHO를 시작합니다. *****" << endl;

    while (true) {
        cout << "삽입:1, 검사:2, 종료:3";
        int n;
        cin >> n;
        switch (n) {
            case 1:
                insert(pwManager);
                break;
            case 2:
                checkNamePw(pwManager);
                break;
            case 3:
                cout << "프로그램을 종료합니다...";
                return 0;
        }
    }
}

-----------
15번문제
#include<iostream>
#include<vector>
using namespace std;

class Circle {
    string name;
    int radius;
public:
    Circle(int radius, string name) {
        this->radius = radius;
        this->name = name;
    }
    double getArea() { return 3.14 * radius * radius; }
    string getName() { return name; }
};



int main() {
    cout << "원을 삽입하고 삭제하는 프로그램입니다.\n";
    vector<Circle*> v;

    while (true) {
        int num;
        int radius;
        string name;

        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> num;

        switch (num) {
        case 1:
            cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
            cin >> radius >> name;
            v.push_back(new Circle(radius, name));
            break;

        case 2: {
            cout << "삭제하고자 하는 원의 이름은 >> ";
            cin >> name;
            vector<Circle*>::iterator it = v.begin();
            while (it != v.end()) {
                Circle* p = *it;
                if (p->getName() == name) {
                    it = v.erase(it);
                    delete p;
                }
                else
                    it++;
            }
            break;
        }

        case 3: {
            vector<Circle*>::iterator it;
            for (it = v.begin(); it != v.end(); it++) {
                Circle* p = *it;
                cout << p->getName() << endl;
            }
            cout << endl;
            break;
        }

        case 4:
            return 0;
        }

    }
}

*/
