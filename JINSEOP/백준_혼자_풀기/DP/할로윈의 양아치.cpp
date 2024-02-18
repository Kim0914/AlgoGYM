#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define pii pair<int, int>

unordered_map<int, int> duplication_preventer;
vector<pii> group_store;
pii groups[30001];
int num = 0, edges = 0, limit = 0, from = 0, to = 0;
int dp[30001][3001];
void optimize() {
	cin.tie(NULL); 
	cout.tie(NULL); 
	ios::sync_with_stdio(false);
}

void init_groups() {
	for (int i = 1; i <= num; i++)
		groups[i].first = i;
}

int find_parent(int node) {
	if (node == groups[node].first)
		return groups[node].first;

	return groups[node].first = find_parent(groups[node].first);
}

void do_union(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x < node_y) {
		groups[node_y].first = node_x;
		groups[node_x].second += groups[node_y].second;
		// 사탕 수를 더해서 저장해준다.
	}
	else {
		groups[node_x].first = node_y;
		groups[node_y].second += groups[node_x].second;
	}
}

int main() {
	optimize();
	cin >> num >> edges >> limit;
	
	init_groups();
	for (int i = 1; i <= num; i++)
		cin >> groups[i].second;
	// 그룹화를 하기 위해 초기화

	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		do_union(from, to);
		// 사이클 체크가 필요할까?
	}

	for (int i = 1; i <= num; i++) {
		int target = groups[i].first;
		int target_candy = groups[i].second;

		if (duplication_preventer[target]) {
			duplication_preventer[target]++;
			continue;
		}

		group_store.push_back({ target, target_candy });
		duplication_preventer[target] = true;
	}

	for (int i = 1; i <= group_store.size(); i++) {
		for (int j = 1; j <= limit; j++) {
			int curr_kids = duplication_preventer[group_store[i - 1].first];
			int curr_value = group_store[i - 1].second;

			if (j - curr_kids > 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curr_kids] + curr_value);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[group_store.size()][limit];
	return 0;
}
