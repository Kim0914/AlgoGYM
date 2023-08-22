#include <iostream>
#include <unordered_set>
using namespace std;

int num = 0, post_num = 0;
unordered_set<string> keyword_set;
int main() {
	string keyword = "", used_keywords = "";
	cin >> num >> post_num;

	for (int i = 0; i < num; i++) {
		cin >> keyword;
		keyword_set.insert(keyword);
	}

	for (int i = 0; i < post_num; i++) {
		cin >> used_keywords;
		int answer = 0;
		string temp = "";

		for (int j = 0; j < used_keywords.size(); j++) {
			if (used_keywords[j] == ',') {
				if (keyword_map[temp] > 0)
					keyword_map[temp]--;
				temp = "";
			}
			else
				temp += used_keywords[j];
		}

		if (keyword_map[temp] > 0)
			keyword_map[temp]--;

		for (auto val : keyword_map)
			answer += val.second;

		cout << answer << '\n';
	}

	return 0;
}
