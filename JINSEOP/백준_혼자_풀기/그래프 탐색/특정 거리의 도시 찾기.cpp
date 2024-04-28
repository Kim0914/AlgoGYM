#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 99999999
typedef pair<int, int> pii;

int vertices = 0, edges = 0, deadline = 0, start_node = 0;
vector<int> graph[300001];
int dist[300001];
void init_dist() {
	for (int i = 1; i <= vertices; i++)
		dist[i] = INF;
	dist[start_node] = 0; // 시작 지점 0으로 초기화
}

void do_dijkstra() {
	priority_queue<pii, vector<pii>, greater<>> dijkstra_q;
	dijkstra_q.push({ 0, start_node });
	
	while (!dijkstra_q.empty()) {
		int curr_node = dijkstra_q.top().second;
		int curr_cost = dijkstra_q.top().first;
		dijkstra_q.pop();

		if (curr_cost > dist[curr_node])
			continue; // 할 필요가 없음, 가지치기

		for (int i = 0; i < graph[curr_node].size(); i++) {
			int next_node = graph[curr_node][i];
			int next_cost = curr_cost + 1;

			if (dist[next_node] > next_cost) {
				dijkstra_q.push({ next_cost, next_node });
				dist[next_node] = next_cost;
			}
		}
	}
}

void print_answer() {
	bool no_answer = true;

	for (int i = 1; i <= vertices; i++) {
		if (dist[i] == deadline) {
			no_answer = false;
			cout << i << '\n';
		}
	}

	if (no_answer)
		cout << -1 << '\n';
}

int main() {
	OPTIMIZE;
	cin >> vertices >> edges >> deadline >> start_node;

	int from = 0, to = 0;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
	}

	init_dist();
	do_dijkstra();
	print_answer();

	return 0;
}
