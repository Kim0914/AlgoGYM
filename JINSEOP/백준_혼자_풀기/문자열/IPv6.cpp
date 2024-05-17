#include <iostream>
#include <string>
using namespace std;

string target = "";
int main() {
	cin >> target;

	int colon_cnt = 0, omitted_idx = -1;
	char prev_char = 'X';
	for (int i = 0; i < target.size(); i++) {
		if (prev_char == ':' && target[i] == ':')
			omitted_idx = i;

		if (target[i] == ':')
			colon_cnt++;

		prev_char = target[i];
	}
	
	if (colon_cnt > 7) {
		if (target[target.size() - 1] == ':')
			target.pop_back();
		if (target[0] == ':')
			target = target.substr(1, target.size() - 1);

		omitted_idx = -1;
	}

	string partial_colon = "";
	for (int i = 0; i < (7 - colon_cnt); i++)
		partial_colon += ':';

	if (omitted_idx != -1) {
		string prev_str = target.substr(0, omitted_idx);
		string post_str = target.substr(omitted_idx, target.size() - omitted_idx);
		target = prev_str + partial_colon + post_str;
	}

	string temp = "", answer = "";
	for (int i = 0; i < target.size(); i++) {
		if (target[i] == ':') {
			int size = temp.size();
			for (int i = 0; i < (4 - size); i++)
				temp = '0' + temp;
			
			answer += (temp + ':');
			temp = "";

			continue;
		}

		temp += target[i];
	}

	int size = temp.size();
	for (int i = 0; i < (4 - size); i++)
		temp = '0' + temp;
	answer += temp;

	cout << answer;
	return 0;
}
