#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999

int vertex = 0, edge = 0, from = 0, to = 0, cost = 0, path_1 = 0, path_2 = 0;
int dist[801], answer = INF;
vector<pair<int, int>> graph[801];
void fill_dist() {
	for (int i = 0; i <= vertex; i++)
		dist[i] = INF;// 초기화
}

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk_q;
	
	dijk_q.push({ 0, start }); // 시작 지점 비용 0
	dist[start] = 0; // 시작 지점까지의 거리 0

	while (!dijk_q.empty()) {
		int curr_node = dijk_q.top().second;
		int curr_cost = dijk_q.top().first;
		dijk_q.pop();

		for (int i = 0; i < graph[curr_node].size(); i++) {
			int next_node = graph[curr_node][i].first;
			int next_cost = curr_cost + graph[curr_node][i].second;

			if (dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				dijk_q.push({ next_cost, next_node });
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
	cin >> path_1 >> path_2;

	fill_dist(); // 다익스트라를 3번 돌려야한다.
	dijkstra(1); // 시작 -> A node
	int start_to_path_1 = dist[path_1];
	int start_to_path_2 = dist[path_2];

	fill_dist();
	dijkstra(path_1); // A node -> B node
	int path_1_to_path_2 = dist[path_2];
	int path_1_to_dest = dist[vertex];

	fill_dist();
	dijkstra(path_2); // B node -> 도착점
	int path_2_to_dest = dist[vertex];

	// 총 두가지 경로가 가능하다.
	answer = min(answer, min((start_to_path_1 + path_1_to_path_2 + path_2_to_dest), 
		        (start_to_path_2 + path_1_to_path_2 + path_1_to_dest)));
	// Start -> A -> B -> Destination
	// Start -> B -> A -> Destination

	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}
