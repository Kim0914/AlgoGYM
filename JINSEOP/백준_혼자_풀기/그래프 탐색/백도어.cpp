#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define INF 10000000000000

ll vertex = 0, edge = 0, from = 0, to = 0, cost = 0;
ll dist[100001];
bool warded[100001];
vector<pair<ll, ll>> summoners_lift[100001];
void init_dist() {
	for (int i = 0; i < vertex; i++)
		dist[i] = INF;
}

void dijkstra(int start_jc) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> dijk_q;
	dijk_q.push({ 0, start_jc });
	dist[0] = 0; // 시작지점 초기화

	while (!dijk_q.empty()) {
		ll curr_node = dijk_q.top().second;
		ll curr_cost = dijk_q.top().first;
		dijk_q.pop();

		if (dist[curr_node] < curr_cost)
			continue;
		// 현재 노드 -> 목적지 > 출발지 -> 목적지
		// 최단 경로 후보에서 이미 탈락

		for (int i = 0; i < summoners_lift[curr_node].size(); i++) {
			ll next_node = summoners_lift[curr_node][i].second;
			ll next_cost = dist[curr_node] + summoners_lift[curr_node][i].first;

			if (dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				dijk_q.push({ next_cost, next_node });
			}
		}
	}
}

int main(){
	cin >> vertex >> edge;
	for (int i = 0; i < vertex; i++)
		cin >> warded[i];
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> cost;

		if ((from != (vertex-1) && to != (vertex - 1)) && (warded[to] || warded[from]))
			continue; // 출발지 / 도착지 모두 와드가 없어야 갈 수 있음
		// 단, 넥서스는 원래 시야가 보임

		summoners_lift[from].push_back({ cost, to });
		summoners_lift[to].push_back({ cost, from });
	}

	init_dist();
	dijkstra(0);

	ll answer = dist[vertex - 1];
	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}
