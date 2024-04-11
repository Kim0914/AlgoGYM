#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 999999999

int vertices = 0, edges = 0, from = 0, to = 0, cost = 0;
int dist[5001];
vector<pii> edge_info[5001];
void init_dist() {
	for (int i = 0; i <= vertices; i++)
		dist[i] = INF;
}

int do_dijkstra(int start_node, int goal) {
	priority_queue<pii, vector<pii>, greater<>> dijk_q;
	dijk_q.push({ 0, start_node });
	int goal_cost = 0;

	while (!dijk_q.empty()) {
		int curr_node = dijk_q.top().second;
		int curr_cost = dijk_q.top().first;
		dijk_q.pop();

		if (curr_node == to)
			return curr_cost;
		if (curr_cost > dist[curr_node])
			continue;

		for (int i = 0; i < edge_info[curr_node].size(); i++) {
			int next_node = edge_info[curr_node][i].first;
			int next_cost = dist[curr_node] + edge_info[curr_node][i].second;

			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				dijk_q.push({ next_cost, next_node });
			}
		}
	}
}

int main() {
	OPTIMIZE;

	cin >> vertices >> edges;

	init_dist();
	for (int i = 0; i < edges; i++) {
		cin >> from >> to >> cost;
		edge_info[from].push_back({ to, cost });
		edge_info[to].push_back({ from, cost });
	}
	cin >> from >> to;
	dist[from] = 0; // 시작 지점

	cout << do_dijkstra(from, to);
	return 0;
}
