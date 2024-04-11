#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 999999999

int computers = 0, edges = 0, from = 0, to = 0, cost = 0;
vector<pii> graph[1001];
vector<pii> shortest_path;
int dist[1001], path_history[1001];
void init_dist() {
	for (int i = 0; i <= computers; i++)
		dist[i] = INF;
}

void connect_computers(int start_node) {
	priority_queue<pii, vector<pii>, greater<>> dijk_q;
	dijk_q.push({ 0, start_node });
	dist[start_node] = 0;

	while (!dijk_q.empty()) {
		int curr_node = dijk_q.top().second;
		int curr_cost = dijk_q.top().first;
		dijk_q.pop();

		if (curr_cost > dist[curr_node])
			continue;

		for (int i = 0; i < graph[curr_node].size(); i++) {
			int next_node = graph[curr_node][i].first;
			int next_cost = dist[curr_node] + graph[curr_node][i].second;

			if (dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				path_history[next_node] = curr_node;
				dijk_q.push({ next_cost, next_node });
			}
			// 관건은 최단 경로를 어떻게 저장할 것인가?
		}
	}
}

int main() {
	OPTIMIZE;
	
	cin >> computers >> edges;

	init_dist();
	for (int i = 0; i < edges; i++) {
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	connect_computers(1);

	cout << computers - 1 << '\n';
	for (int i = 2; i <= computers; i++)
		cout << path_history[i] << " " << i << '\n';
	return 0;
}
