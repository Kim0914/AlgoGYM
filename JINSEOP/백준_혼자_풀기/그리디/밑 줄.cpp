#include <iostream>
#include <string>
#include <vector>
using namespace std;

int num = 0, limit = 0;
int main()
{
	cin >> num >> limit;

	string whole_word = "", curr_word = "";
	vector<string> word_vec;
	int whole_length = 0, length_to_fill = 0;
	for (int i = 0; i < num; i++) {
		cin >> curr_word;
		word_vec.push_back(curr_word);
		whole_length += curr_word.size();
		// 단어 총 길이 저장
	}

	length_to_fill = limit - whole_length;
	// 우리는 이제 length_to_fill 만큼 채워야 함
	// ex) 50 - 33 = 17 -> 17 / (num - 1) = 2
	int diff = (length_to_fill / (num - 1));
	for (int i = 0; i < num - 1; i++) {
		whole_word += word_vec[i];

		for (int j = 0; j < diff; j++)
			whole_word += '_';
	}
	// 이러면 이제 length_to_fill % (num - 1) 만큼 남음
	// ex) 17 % 2 = 1 하나를 어디다 붙일지가 관건임
	
	int rest_of = (length_to_fill % (num - 1));
	for (int i = whole_word.size(); i >= 0; i--) {
		if (rest_of == 0)
			break;

		if ('A' <= whole_word[i] && whole_word[i] <= 'Z') {
		// 앞이 대문자인 단어를 찾았으면?
			int idx = i;
			for (int j = i; j < whole_word.size(); j++) {
				if (whole_word[j] == '_')
					break;

				idx++;
			}

			string left_sub = whole_word.substr(0, idx);
			string right_sub = whole_word.substr(idx, whole_word.size() - idx);

			whole_word = left_sub + '_' + right_sub;
			rest_of--;
		}
	}

	whole_word += word_vec.back();
	cout << whole_word;
	return 0;
}
