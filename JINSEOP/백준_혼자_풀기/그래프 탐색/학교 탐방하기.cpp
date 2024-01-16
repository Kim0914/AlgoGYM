#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vertex = 0, edge = 0, from = 0, to = 0, hill = 0;
int spanning_tree[1001];
vector<pair<pair<int, int>, int>> path_info;
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	return a.second > b.second;
}

bool r_cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

void init_map() {
	for (int i = 1; i <= vertex; i++)
		spanning_tree[i] = i;
}

int find_parent(int node) {
	if (spanning_tree[node] == node)
		return node;

	return spanning_tree[node] = find_parent(spanning_tree[node]);
}

void do_union(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x < node_y)
		spanning_tree[node_y] = node_x;
	else
		spanning_tree[node_x] = node_y;
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
	
	cin >> vertex >> edge;
	for (int i = 0; i < edge + 1; i++) {
		cin >> from >> to >> hill;
		// 이 때, 0 - 1번은 무조건 연결되어야 함
		path_info.push_back({ {from, to}, hill });
	}

	int max_uphill = 0, min_uphill = 0;
	init_map();
	sort(path_info.begin() + 1, path_info.end(), cmp);
	for (int i = 0; i < path_info.size(); i++) {
		int curr_from = path_info[i].first.first;
		int curr_to = path_info[i].first.second;
		int curr_hill = path_info[i].second;

		if (!check_cycle(curr_from, curr_to)) {
			do_union(curr_from, curr_to);

			if(curr_hill == 0)
				min_uphill += 1;
		}
	}
	// 내리막길 우선 설치

	init_map();
	sort(path_info.begin() + 1, path_info.end(), r_cmp);
	for (int i = 0; i < path_info.size(); i++) {
		int curr_from = path_info[i].first.first;
		int curr_to = path_info[i].first.second;
		int curr_hill = path_info[i].second;

		if (!check_cycle(curr_from, curr_to)) {
			do_union(curr_from, curr_to);

			if(curr_hill == 0)
				max_uphill += 1;
		}
	}
	// 오르막길 우선 설치

	max_uphill *= max_uphill;
	min_uphill *= min_uphill;
	cout << max_uphill - min_uphill;
	return 0;
}
