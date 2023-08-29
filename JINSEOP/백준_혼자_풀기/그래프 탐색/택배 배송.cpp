#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999

int vertex = 0, edge = 0, from = 0, to = 0, cost = 0;
int dist[50001];
vector<pair<int, int>> graph[50001];
priority_queue <pair<int, int>> dijk_q;
void fill_dist() {
	for (int i = 1; i <= vertex; i++)
		dist[i] = INF;
}

void dijkstra(int start) {
	dijk_q.push({ start, 0 });
	dist[start] = 0;

	while (!dijk_q.empty()) {
		int curr_node = dijk_q.top().first;
		int curr_cost = dijk_q.top().second;
		dijk_q.pop();

		if (dist[curr_node] < curr_cost)
			continue;

		for (int i = 0; i < graph[curr_node].size(); i++) {
			int next_node = graph[curr_node][i].first;
			int next_cost = curr_cost + graph[curr_node][i].second;

			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				dijk_q.push({ next_node, next_cost });
			}
		}
	}

}

int main() {
	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	fill_dist();
	dijkstra(1);

	cout << dist[vertex];
	return 0;
}
