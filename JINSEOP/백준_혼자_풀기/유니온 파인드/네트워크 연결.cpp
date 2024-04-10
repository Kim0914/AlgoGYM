#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define piii pair<pair<int, int>, int>

int vertices = 0, edges = 0, from = 0, to = 0, cost = 0, answer = 0;
int graph[1001];
struct cmp {
	bool operator()(piii a, piii b) {
		return a.second > b.second;
	}
};
void init_graph() {
	for (int i = 1; i <= vertices; i++)
		graph[i] = i;
}

int find_parent(int node) {
	if (graph[node] == node)
		return node;

	return graph[node] = find_parent(graph[node]);
}

void do_union(int node_x, int node_y, int cost) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x == node_y)
		return; // Check cycle

	if (node_x < node_y)
		graph[node_x] = node_y;
	else
		graph[node_y] = node_x;

	answer += cost;
}

int main() {
	OPTIMIZE;

	cin >> vertices >> edges;

	init_graph();
	priority_queue<piii, vector<piii>, cmp> edge_q;

	for (int i = 0; i < edges; i++) {
		cin >> from >> to >> cost;
		edge_q.push({ {from, to}, cost });
	}
	
	while (!edge_q.empty()) {
		int curr_from = edge_q.top().first.first;
		int curr_to = edge_q.top().first.second;
		int curr_cost = edge_q.top().second;
		edge_q.pop();

		do_union(curr_from, curr_to, curr_cost);
	}

	cout << answer;
	return 0;
}
