#include <iostream>
#include <string>
using namespace std;

int num = 0;
string pattern = "", target = "";
bool check_asterisk(int idx) {
	if (pattern[idx] == '*')
		return true;
	else
		return false;
}

int main(){
	cin >> num;
	cin >> pattern;

	for (int i = 0; i < num; i++) {
		bool pattern_flag = true;
		cin >> target;
		
		if (pattern.size() - target.size() > 1)
			pattern_flag = false;

		for (int j = 0; j < target.size(); j++) {
			if (check_asterisk(j))
				break;

			if (pattern[j] != target[j]) {
				pattern_flag = false;
				break;
			}
		} // 앞자리 비교

		int pattern_idx = pattern.size() - 1;
		for (int j = target.size() - 1; j >= 0; j--) {
			if (check_asterisk(pattern_idx))
				break;

			if (pattern[pattern_idx] != target[j]) {
				pattern_flag = false;
				break;
			}

			pattern_idx--;
		} // 뒷자리 비교

		if (pattern_flag)
			cout << "DA" << '\n';
		else
			cout << "NE" << '\n';
	}

	return 0;
}
