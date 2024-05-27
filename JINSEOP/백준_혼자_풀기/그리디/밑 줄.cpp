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
	int rest_of = (length_to_fill % (num - 1));

	for (int i = 1; i < num; i++) {
		if (rest_of == 0)
			break;

		if ('a' <= word_vec[i][0] && word_vec[i][0] <= 'z') {
			word_vec[i] = '_' + word_vec[i];
			rest_of--;
		}
	}

	for (int i = num - 1; i >= 0; i--) {
		if (rest_of == 0)
			break;

		if ('A' <= word_vec[i][0] && word_vec[i][0] <= 'Z') {
			word_vec[i] = '_' + word_vec[i];
			rest_of--;
		}
	}

	whole_word += word_vec[0];
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < diff; j++) {
			word_vec[i] = '_' + word_vec[i];
		}

		whole_word += word_vec[i];
	}

	cout << whole_word;
	return 0;
}
