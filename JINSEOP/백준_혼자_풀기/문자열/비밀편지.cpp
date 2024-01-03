#include <iostream>
#include <unordered_map>
using namespace std;

int num = 0, answer = 0;
string target = "", answer_str = "";
unordered_map<string, char> alpha_map;
void init_map() {
	alpha_map["000000"] = 'A';
	alpha_map["001111"] = 'B';
	alpha_map["010011"] = 'C';
	alpha_map["011100"] = 'D';
	alpha_map["100110"] = 'E'; 
	alpha_map["101001"] = 'F';
	alpha_map["110101"] = 'G';
	alpha_map["111010"] = 'H';
}

char validate_string(string target) {
	char ch_to_ret = ' ';

	if (alpha_map[target] != NULL)
		return alpha_map[target];
	else {
		for (int i = 0; i < target.size(); i++) {
			target[i] == '0' ? target[i] = '1' : target[i] = '0';

			if (alpha_map[target] != NULL) {
				if (ch_to_ret != ' ')
					return 'X';
				else
					ch_to_ret = alpha_map[target];
			}

			target[i] == '0' ? target[i] = '1' : target[i] = '0';
		}
	}

	if (ch_to_ret == ' ')
		return 'X';

	return ch_to_ret;
}

int main() {
	cin >> num;
	cin >> target;

	init_map();
	string temp = "";
	for (int i = 1; i <= target.size(); i++) {
		temp += target[i - 1];

		if (i % 6 == 0) {
			char validated_char = validate_string(temp);
			if (validated_char == 'X') {
				cout << (i / 6);
				return 0;
			}
			else
				answer_str += validated_char;

			temp = "";
		}
	}

	cout << answer_str;
	return 0;
}
