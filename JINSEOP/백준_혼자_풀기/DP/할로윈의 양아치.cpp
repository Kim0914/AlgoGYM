#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define pii pair<int, int>

vector<pii> group_store;
pii groups[30001];
int dp[30001][3001], popularity[30001];
int num = 0, edges = 0, limit = 0, from = 0, to = 0;
void optimize() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void init_groups() {
	for (int i = 1; i <= num; i++) {
		groups[i].first = i;
		popularity[i] = 1;
	}
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
		popularity[node_x] += popularity[node_y];
	}
	else {
		groups[node_x].first = node_y;
		groups[node_y].second += groups[node_x].second;
		popularity[node_y] += popularity[node_x];
	}
}

bool check_cycle(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x == node_y)
		return true;
	return false;
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
		if(!check_cycle(from, to))
			do_union(from, to);
	}

	for (int i = 1; i <= num; i++) {
		int target = groups[i].first;
		int target_candy = groups[i].second;

		if (target == i) // root인 경우 배열에 저장
			group_store.push_back({ target, target_candy });
	}

	for (int i = 0; i < group_store.size(); i++) {
		for (int j = 0; j < limit; j++) {
			int curr_kids = popularity[group_store[i].first];
			int curr_value = group_store[i].second;

			if (j - curr_kids >= 0)
				dp[i + 1][j] = max(dp[i][j], dp[i][j - curr_kids] + curr_value);
			else
				dp[i + 1][j] = dp[i][j];
		}
	}

	cout << dp[group_store.size()][limit - 1];
	return 0;
}
