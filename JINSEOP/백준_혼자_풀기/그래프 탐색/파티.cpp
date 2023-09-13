#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999;

int num = 0, edge = 0, goal = 0, start_p = 0, end_p = 0, cost = 0;
vector<pair<int, int>> map_to_party[1001];
vector<pair<int, int>> map_to_home[1001];
int dist[1001], dist_from_home[1001];
void init_dist() {
	for (int i = 0; i <= num; i++) {
		dist[i] = INF;// 초기화
		dist_from_home[i] = INF;
	}
}

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk_q;
	dijk_q.push({goal, 0});
	dist[goal] = 0;

	while (!dijk_q.empty()) {
		int curr = dijk_q.top().first;
		int curr_cost = dijk_q.top().second;
		dijk_q.pop();

		if (curr_cost > dist[curr])
			continue;

		for (int i = 0; i < map_to_home[curr].size(); i++) {
			int next = map_to_home[curr][i].first;
			int next_cost = curr_cost + map_to_home[curr][i].second;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				dijk_q.push({ next, next_cost });
			}
		}
	}
}

void dijkstra_to_party() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk_q;
	dijk_q.push({ goal, 0 });
	dist_from_home[goal] = 0;

	while (!dijk_q.empty()) {
		int curr = dijk_q.top().first;
		int curr_cost = dijk_q.top().second;
		dijk_q.pop();

		if (curr_cost > dist_from_home[curr])
			continue;

		for (int i = 0; i < map_to_party[curr].size(); i++) {
			int next = map_to_party[curr][i].first;
			int next_cost = curr_cost + map_to_party[curr][i].second;

			if (dist_from_home[next] > next_cost) {
				dist_from_home[next] = next_cost;
				dijk_q.push({ next, next_cost });
			}
		}
	}
}

int main() {
	cin >> num >> edge >> goal;
	for (int i = 0; i < edge; i++) {
		cin >> start_p >> end_p >> cost;
		map_to_home[start_p].push_back({ end_p, cost }); // 단방향
		map_to_party[end_p].push_back({ start_p, cost });
    // 집에서 파티장까지 가는 경우는 원래 모든 정점에서 파티장까지 반복문을 돌리려 했다.
    // 하지만 반대로 생각해보자.
    // 파티장에서 집까지 다익스트라를 돌리는데, 길을 역방향으로 저장한다면?
    // 그럼 집에서 파티장까지 가는 길을 거꾸로 돌아갈 수 있을 것이다.
	}

	init_dist();
	dijkstra_to_party(); // 파티까지 거리를 구할 수 있음
	dijkstra(); // 집까지 거리 구할 수 있음
	
	int answer = 0;
	for (int i = 1; i <= num; i++)
		answer = max(answer, dist[i] + dist_from_home[i]);

	cout << answer;
	return 0;
}
