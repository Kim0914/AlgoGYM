#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int num = 0, max_cnt = 0, max_first_idx = 0, max_second_idx = 0;
string word = "";
unordered_map<string, pair<int, int>> word_map;
vector<string> word_list;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> word; 
		word_list.push_back(word);
		string temp = "";
		int overlap_cnt = 0;

		for (int j = 0; j < word.size(); j++) {
			temp += word[j];

			if (word_map[temp].first > 0) {
				overlap_cnt = word_map[temp].first;

				if (overlap_cnt > max_cnt) {
					max_cnt = overlap_cnt;
					max_first_idx = word_map[temp].second;
					max_second_idx = i;
				}

				if (overlap_cnt == max_cnt) { // 동일할 때, 더 앞에 있는 것을 결과로
					if (max_first_idx > word_map[temp].second) {
						max_first_idx = word_map[temp].second;
						max_second_idx = i;
					}
				}
			}

			word_map[temp] = { temp.size() , i };
		}
	}

	cout << word_list[max_first_idx] << '\n';
	cout << word_list[max_second_idx];

	return 0;
}
