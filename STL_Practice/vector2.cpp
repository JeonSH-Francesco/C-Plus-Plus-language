#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Word {
	string english;
	string korean;
public:
	Word(string eng, string kor) : english(eng), korean(kor) {}
	string getEng() const { return english; }
	string getKor() const { return korean; }
};

int main() {
	srand(static_cast<unsigned>(time(0)));
	cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다." << endl;

	vector<Word> v = {
		{"human", "인간"},
		{"baby", "아기"},
		{"society", "사회"},
		{"photo", "사진"},
		{"painting", "그림"},
		{"love", "사랑"},
		{"emotion", "감정"},
		{"doll", "인형"},
		{"animal", "동물"},
		{"bear", "곰"},
		{"trade", "거래"}
	};

	while (true) {
		int index = rand() % v.size();
		const string correctAnswer = v[index].getKor();

		vector<string> options;
		options.push_back(correctAnswer);

		while (options.size() < 4) {
			int randomIndex = rand() % v.size();
			const string newOption = v[randomIndex].getKor();

			if (newOption != correctAnswer && find(options.begin(), options.end(), newOption) == options.end()) {
				//조건 1 : 새로운 보기 newOption은 정답 correctAnswer과 달라야 한다.
				//이를 통해 같은 정답을 여러 번 보기로 제시하지 않도록 합니다.
				//조건 2 : 새로운 보기는 이미 options 벡터에 존재하지 않아야 한다.
				//중복된 보기를 피하기 위한 조건입니다.
		
				options.push_back(newOption);
				//위 두조건이 만족하는 경우에만. options 벡터에 추가한다.
			}
		}

		random_shuffle(options.begin(), options.end());

		cout << v[index].getEng() << "?" << endl;
		for (int i = 0; i < 4; ++i) {
			cout << "(" << i + 1 << ") " << options[i] << ' ';
		}

		cout << ":>";
		int answer;
		cin >> answer;

		if (answer >= 1 && answer <= 4) {
			if (options[answer - 1] == correctAnswer) {
				cout << "Excellent !!" << endl;
			}
			else {
				cout << "No. !!" << endl;
			}
		}
		else {
			break;
		}
	}

	return 0;
}
