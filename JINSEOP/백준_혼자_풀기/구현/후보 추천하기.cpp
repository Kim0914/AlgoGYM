#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candi_num = 0, num = 0, candidate = 0;
vector<pair<int, pair<int, int>>> candi_board;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.first == b.second.first)
		return a.second.second > b.second.second;
	return a.second.first > b.second.first;
}

int find_candidate(int candi) {
	for (int i = 0; i < candi_board.size(); i++) {
		if (candi == candi_board[i].first)
			return i;
	}

	return 9999;
}

int main() {
	cin >> candi_num >> num;
	for (int i = 0; i < num; i++) {
		cin >> candidate;

		sort(candi_board.begin(), candi_board.end(), cmp);
		int target_idx = find_candidate(candidate);

		if (candi_board.size() >= candi_num && target_idx == 9999) {
			candi_board.pop_back();
			candi_board.push_back({ candidate, {0, i} });
			continue;
		}

		if (target_idx == 9999)
			candi_board.push_back({ candidate, {0, i} });
		else
			candi_board[target_idx].second.first++;
	}

	sort(candi_board.begin(), candi_board.end());
	for (auto i : candi_board)
		cout << i.first << " ";
	return 0;
}
