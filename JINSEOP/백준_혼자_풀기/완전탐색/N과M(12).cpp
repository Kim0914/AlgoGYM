#include <iostream>
#include <vector>
#include <set>
using namespace std;

int num = 0, limit = 0;
int seq[8];
bool visit[8];
vector<int> selected;
set<vector<int>> duplication_eliminator;
void backtrack(int curr_node, int depth){
	if (depth == limit) {
		duplication_eliminator.insert(selected);
		return;
	}

	for (int i = 0; i < num; i++) {
		if (seq[i] >= seq[curr_node]) {
			selected.push_back(seq[i]);
			backtrack(i, depth + 1);
			selected.pop_back();
		}
	}
}

int main() {
	cin >> num >> limit;
	for (int i = 0; i < num; i++)
		cin >> seq[i];

	for (int i = 0; i < num; i++) {
		selected.push_back(seq[i]);
		backtrack(i, 1);
		selected.pop_back();
	}

	for (auto i : duplication_eliminator) {
		for (int k : i)
			cout << k << " ";
		cout << '\n';
	}

	return 0;
}
