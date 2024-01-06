#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int house = 0, road = 0, from = 0, to = 0, cost = 0;
pair<int, int> trash_val;
int reduced_road[200000];
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first < b.first;
	// 각 간선의 비용 기준 오름차순 정렬
}

void init_road() {
	for (int i = 0; i <= house; i++)
		reduced_road[i] = i;
}

int find_parent(int node) {
	if (reduced_road[node] == node)
		return node;

	return reduced_road[node] = find_parent(reduced_road[node]);
}

void do_union(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x < node_y)
		reduced_road[node_x] = node_y;
	else
		reduced_road[node_y] = node_x;
}

bool check_cycle(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x == node_y)
		return true;
	return false;
}

int main() {
	while (true) {
		vector<pair<int, pair<int, int>>> graph;
		int origin_cost = 0, reduced_cost = 0;

		cin >> house >> road;
		if (house == 0 && road == 0)
			break;

		for (int i = 0; i < road; i++) {
			cin >> from >> to >> cost;
			origin_cost += cost;

			graph.push_back({ cost, {from, to} });
		}

		init_road();
		sort(graph.begin(), graph.end(), cmp);
		for (int i = 0; i < graph.size(); i++) {
			if (!check_cycle(graph[i].second.first, graph[i].second.second)) {
				do_union(graph[i].second.first, graph[i].second.second);
				reduced_cost += graph[i].first;
			}
		}

		cout << origin_cost - reduced_cost << '\n';
	}

	return 0;
}
