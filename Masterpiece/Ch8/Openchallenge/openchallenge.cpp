#include <iostream>
#include <string>
using namespace std;

class Product {
	int id;
	string price, description, producer;
public:
	Product(){}
	Product(int id, string price, string des, string pro) {
		this->id = id;
		this->price = price;
		this->description = des;
		this->producer = pro;
	}
	virtual void show() = 0; // 부모 클래스에서 자식 클래스의 함수를 접근을 위해
	//순수 가상 함수 사용
	int getId() { return id; }
	string getPrice(){ return price; }
	string getDes() { return description; }
	string getPro() { return producer; }
};
//id, price,description, producer


//Product 클래스를 상속받는 Book 클래스
class Book : public Product {
	string ISBN, author, Bookname;
public:
	Book(int id, string des, string pro, string price, string Bookname, string author, string ISBN) : Product(id, price, des, pro) {
		this->ISBN = ISBN; this->author = author; this->Bookname = Bookname;
	}
	void show();
	string getName() { return Bookname; }
	string getAut() { return author; }
	string getISBN() { return ISBN; }
};

//상품 ID, 상품 설명, 생산자, 가격, 책 제목, 저자, ISBN
void Book::show() {
	cout << "--- 상품ID : " << getId() << endl;
	cout << "상품설명 : " << getDes() << endl;
	cout << "생산자 : " << getPro() << endl;
	cout << "가격 : " << getPrice() << endl;
	cout << "책제목 : " << Bookname << endl;
	cout << "저자 : " << author << endl;
	cout << "ISBN : " << ISBN << endl;
}



//Product 클래스를 상속받는 CompactDisc 클래스
class CompactDisc : public Product {
	string Albumname,Singer;
public:
	CompactDisc(int id,string des,string pro,string price,string Albumname,string Singer) : Product(id, price, des, pro) {
		this->Albumname= Albumname; this->Singer = Singer;
	}
	void show();
};

//상품 ID, 상품 설명, 생산자, 가격,앨범 제목, 가수
void CompactDisc::show() {
	cout << "--- 상품 ID : " << getId() << endl;
	cout << "상품 설명 : " << getDes() << endl;
	cout << "생산자: " << getPro() << endl;
	cout << "가격: " << getPrice() << endl;
	cout << "앨범제목: " << Albumname << endl;
	cout << "가수: " << Singer << endl;
}

//Book 클래스를 상속받는 ConversationBook 클래스
class ConversationBook : public Book{
	string lan;
public:
	ConversationBook(int id, string des, string pro, string price, string Bookname, string author, string lan, string isbn)
		:Book(id, des, pro, price, Bookname, author, isbn) {
		this->lan = lan;
	}
	void show();
};
//상품 ID, 상품 설명, 생산자, 가격,책 제목,저자,언어, ISBN
void ConversationBook::show() {
	cout << "--- 상품ID : " << getId() << endl;
	cout << "상품설명 : " << getDes() << endl;
	cout << "생산자 : " << getPro() << endl;
	cout << "가격 : " << getPrice() << endl;
	cout << "책제목 : " << getName() << endl;
	cout << "저자 : " << getAut() << endl;
	cout << "언어 : " << lan << endl;
	cout << "ISBN : " << getISBN() << endl;
}

int main() {
	Product* p[100];

	int id = 0;
	string des, pro, price;//상품의 식별자, 설명,생산자, 가격-->Product 클래스
	string ISBN, author, Bookname; //ISBN 번호, 저자, 책 제목 정보-->Book 클래스
	string Albumname, Singer;//앨범 제목, 가수 이름-->CompactDisc 클래스
	string lan;// 언어 --> ConversationBook 클래스
	
	int num = 0; // 상품 관리 프로그램 선택 번호
	int detailNum=0;// 세부 선택 번호

	cout << "***** 상품 관리 프로그램을 작동합니다 *****"<<endl;
	for (;;)
	{
		cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ?";
		cin >> num;

		if (num == 1) {
			if (id >= 100) break;
			cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ?";
			cin >> detailNum;
			cin.ignore();
			if (detailNum == 1) {
				cout << "상품설명>>";
				getline(cin, des);

				cout << "생산자>>";
				getline(cin, pro);

				cout << "가격>>";
				getline(cin, price);

				cout << "책제목>>";
				getline(cin, Bookname);

				cout << "저자>>";
				getline(cin, author);

				cout << "ISBN>>";
				getline(cin, ISBN);

				Book* b = new Book(id, des, pro, price, Bookname, author, ISBN);
				p[id] = b;
				id++;

			}
			else if (detailNum == 2) {
				cout << "상품설명>>";
				getline(cin, des);

				cout << "생산자>>";
				getline(cin, pro);

				cout << "가격>>";
				getline(cin, price);

				cout << "앨범제목>>";
				getline(cin, Albumname);

				cout << "가수>>";
				getline(cin, Singer);


				CompactDisc* c = new CompactDisc(id, des, pro, price, Albumname, Singer);
				p[id] = c;
				id++;

			}
			else if (detailNum == 3) {
				cout << "상품설명>>";
				getline(cin, des);

				cout << "생산자>>";
				getline(cin, pro);

				cout << "가격>>";
				getline(cin, price);

				cout << "책제목>>";
				getline(cin, Bookname);

				cout << "저자>>";
				getline(cin, author);

				cout << "언어>>";
				getline(cin, lan);

				cout << "ISBN>>";
				getline(cin, ISBN);

				ConversationBook* cb = new ConversationBook(id, des, pro, price, Bookname, author, lan, ISBN);
				p[id] = cb;
				id++;


			}
			else {
				cout << "숫자 입력 오류" << endl;
			}

		}

		else if (num == 2) {
			for (int i = 0; i < id; i++) {
				p[i]->show();
			}
		}
		else if (num == 3) {
			break;
		}
		else {
			cout << "숫자 입력 오류" << endl;
		}
		cout << endl;

	}


}
/*
***** 상품 관리 프로그램을 작동합니다 *****
상품 추가(1), 모든 상품 조회(2), 끝내기(3) ?1
상품 종류 책(1), 음악CD(2), 회화책(3) ?2
상품설명>>조수미 기념 음반
생산자>>한성기획
가격>>15000
앨범제목>>조수미 forever
가수>>조수미

상품 추가(1), 모든 상품 조회(2), 끝내기(3) ?1
상품 종류 책(1), 음악CD(2), 회화책(3) ?3
상품설명>>팝으로 배우는 영어회화
생산자>>한성기획
가격>>20000
책제목>>팝 영어
저자>>제인
언어>>영어
ISBN>>000111

상품 추가(1), 모든 상품 조회(2), 끝내기(3) ?2
--- 상품 ID : 0
상품 설명 : 조수미 기념 음반
생산자: 한성기획
가격: 15000
앨범제목: 조수미 forever
가수: 조수미
--- 상품ID : 1
상품설명 : 팝으로 배우는 영어회화
생산자 : 한성기획
가격 : 20000
책제목 : 팝 영어
저자 : 제인
언어 : 영어
ISBN : 000111

상품 추가(1), 모든 상품 조회(2), 끝내기(3) ?3*/
