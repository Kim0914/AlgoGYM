#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll vertex = 0, edge = 0, level = 0, employee = 0, score = 0;
vector<ll> company[100001];
ll score_board[100001];
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void dfs(ll curr_node) {
	for (int i = 0; i < company[curr_node].size(); i++) {
		int next_node = company[curr_node][i];
		score_board[next_node] += score_board[curr_node];
		dfs(next_node);
	}
}

int main() {
	optimize();
	cin >> vertex >> edge;
	for (int i = 1; i <= vertex; i++) {
		cin >> level;
		
		if (level != -1)
			company[level].push_back(i);
	}

	for (int i = 0; i < edge; i++) {
		cin >> employee >> score;
		score_board[employee] += score;
	}

	dfs(1);
	for (int i = 1; i <= vertex; i++)
		cout << score_board[i] << ' ';

	return 0;
}
