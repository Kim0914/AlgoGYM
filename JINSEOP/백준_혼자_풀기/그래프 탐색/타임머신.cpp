#include <iostream>
#include <vector>
using namespace std;
#define piii pair<pair<int, int>, int>
#define INF 1000000000
#define ll long long

int vertex = 0, edge = 0, from = 0, to = 0, cost = 0;
piii graph[6000];
ll dist[501];
void init_dist() {
	for (int i = 1; i <= vertex; i++)
		dist[i] = INF;
	dist[1] = 0;
}

void bellman_ford() {
	for (int i = 1; i <= vertex - 1; i++) {
	// 정점을 (N - 1)회 만큼 돌아야 한다.
	// 이후 순회 시, 갱신이 된다면, 사이클이 존재한다는 의미이다.
		for (int j = 0; j < edge; j++) {
			int curr_from = graph[j].first.first;
			int curr_to = graph[j].first.second;
			int curr_cost = graph[j].second;

			if (dist[curr_from] == INF)
				continue;
			// 방문하지 않은 정점은 갱신하지 않는다.
			if (dist[curr_to] > dist[curr_from] + curr_cost)
				dist[curr_to] = dist[curr_from] + curr_cost;
		}
	}
}

bool check_cycle() {
	for (int i = 0; i < edge; i++) {
		int curr_from = graph[i].first.first;
		int curr_to = graph[i].first.second;
		int curr_cost = graph[i].second;

		if (dist[curr_from] == INF)
			continue;
		if (dist[curr_to] > dist[curr_from] + curr_cost)
			return false;
		// 사이클이 발생한 것이다.
	}

	return true;
}

int main() {
	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> cost;
		graph[i] = { {from, to}, cost };
	}
	// 시작 도시는 반드시 1번, dist[1] = 0
	
	init_dist();
	bellman_ford();

	if (!check_cycle())
		cout << -1;
	else {
		for (int i = 2; i <= vertex; i++) {
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}

	return 0;
}
