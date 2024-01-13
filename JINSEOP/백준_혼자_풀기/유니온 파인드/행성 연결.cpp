#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int vertex = 0;
ll planets[1001][1001], span[1001];
vector<pair<ll, pair<ll, ll>>> paths;
void init_spanning_tree() {
	for (int i = 1; i <= vertex; i++)
		span[i] = i;
}

int find_parent(int node) {
	if (node == span[node])
		return node;

	return span[node] = find_parent(span[node]);
}

void do_union(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x < node_y)
		span[node_y] = node_x;
	else
		span[node_x] = node_y;
}

bool check_cycle(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x == node_y)
		return true;
	return false;
}

int main() {
	cin >> vertex;
	for (int i = 1; i <= vertex; i++)
		for (int j = 1; j <= vertex; j++)
			cin >> planets[i][j];
	// 문제는 인접행렬을 어떻게 정렬할 것인가?

	for (int i = 1; i <= vertex; i++)
		for (int j = i + 1; j <= vertex; j++)
			paths.push_back({ planets[i][j], {i, j} });

	sort(paths.begin(), paths.end());
	init_spanning_tree();

	ll min_cost = 0;
	for (int i = 0; i < paths.size(); i++) {
		if (!check_cycle(paths[i].second.first, paths[i].second.second)) {
			do_union(paths[i].second.first, paths[i].second.second);
			min_cost += paths[i].first;
		}
	}
	
	cout << min_cost;
	return 0;
}
