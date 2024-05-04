#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int num = 0;
unordered_map<char, bool> shortcut_map;
vector<string> answer_vec;
int main() {
	cin >> num;
	cin.ignore();

	string cmd = "";
	for (int i = 0; i < num; i++) {
		getline(cin, cmd);

		int target_idx = -1;
		string temp_for_target = "";
		bool is_first = true;
		for (int j = 0; j < cmd.size(); j++) {
			char target = tolower(cmd[j]);
			if (cmd[j] == ' ') {
				is_first = true;
				continue;
			}

			if (!shortcut_map[target] && is_first) {
				shortcut_map[target] = true;
				temp_for_target = cmd[j];
				target_idx = j;
				break;
			}

			is_first = false;
		}

		if (target_idx == -1) {
			for (int j = 0; j < cmd.size(); j++) {
				char target = tolower(cmd[j]);

				if (!shortcut_map[target] && cmd[j] != ' ') {
					shortcut_map[target] = true;
					temp_for_target = cmd[j];
					target_idx = j;
					break;
				}
			}
		}

		if (target_idx != -1) {
			temp_for_target = '[' + temp_for_target + ']';
			string prev = cmd.substr(0, target_idx);
			string post = cmd.substr(target_idx + 1, cmd.size() - target_idx);
			answer_vec.push_back(prev + temp_for_target + post);
		}
		else
			answer_vec.push_back(cmd);
	}

	for (string s : answer_vec)
		cout << s << '\n';
	return 0;
}
