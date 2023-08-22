#include <iostream>
#include <unordered_set>
using namespace std;

int num = 0, post_num = 0;
unordered_set<string> keyword_set;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string keyword = "", used_keywords = "";
	cin >> num >> post_num;

	for (int i = 0; i < num; i++) {
		cin >> keyword;
		keyword_set.insert(keyword);
	}

	for (int i = 0; i < post_num; i++) {
		cin >> used_keywords;
		string temp = "";

		for (int j = 0; j < used_keywords.size(); j++) {
			if (used_keywords[j] == ',') {
				if (keyword_set.find(temp) != keyword_set.end())
					keyword_set.erase(temp);
				temp = "";
			}
			else
				temp += used_keywords[j];
		}

		if (keyword_set.find(temp) != keyword_set.end()) 
			keyword_set.erase(temp);

		cout << keyword_set.size() << '\n';
	}

	return 0;
}

// Unordered Map이 아닌 Unordered Set이 더 빠름!
// 왜? Unordered Map은 수를 세기 위해 한번 더 순회해야함.
// Unordered Set은 사이즈만 반환하면 됨!
