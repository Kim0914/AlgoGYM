#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 999999999

vector<pair<int, int>> mount_road[50001];
int dist[50001];
bool summit[50001];
void make_map(vector<vector<int>> paths) {
	for (int i = 0; i < paths.size(); i++) {
		int from = paths[i][0];
		int to = paths[i][1];
		int cost = paths[i][2];

		mount_road[from].push_back({ cost, to });
		mount_road[to].push_back({ cost, from });
		// 다익스트라를 수행할 땐, cost가 앞으로 가는게 정렬에 좋다.
	}
}

void init_dist(int n) {
	for (int i = 0; i <= n; i++)
		dist[i] = INF;
}

void check_summit(vector<int> summits) {
	for (int i = 0; i < summits.size(); i++)
		summit[summits[i]] = true;
		// 꼭대기를 미리 표시해서 검사 과정을 간결하게
}

void dijkstra(vector<int>& answer, vector<int> gates) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk_q;
	int min_summit = INF, min_cost = INF;

	for (int i = 0; i < gates.size(); i++) {
		dijk_q.push({ 0, gates[i] });
		dist[gates[i]] = 0;
		// 이 부분도 중요하다.
		// 다익스트라를 여러번 돌리면 시간초과가 발생한다.
		// 그냥 동시에 출발 시켜버리면, 시간초과가 발생하지 않는다.
	}

	while (!dijk_q.empty()) {
		int curr_node = dijk_q.top().second; // 현재 목적지
		int curr_cost = dijk_q.top().first; // 현재 목적지로의 비용
		dijk_q.pop();

		if (dist[curr_node] < curr_cost)
			continue;
		// 이미 갱신된 거리보다 앞으로 계산할 거리가 크면 진행할 필요가 없음.

		if (summit[curr_node]) {
			// 꼭대기에 도착을 했습니다.
			// 당연히 저장해 온 최대 intensity가
			// 전체에서 최소보다 작은 경우 갱신한다.
			if (curr_cost <= min_cost) {
				min_cost = curr_cost;

				if (curr_cost == min_cost)
					// tie break의 경우, 산봉우리의 번호가 작은 것을 정답으로
					min_summit = min(curr_node, min_summit);
				else
					min_summit = curr_node;
			}

			continue;
			// 이후로는 더 이상 진행하지 않는다.
		}

		for (int i = 0; i < mount_road[curr_node].size(); i++) {
			// 여긴 기본적인 다익스트라 동작인데..
			int next_node = mount_road[curr_node][i].second;
			int next_cost = mount_road[curr_node][i].first;

			// 이 부분이 다르다.
			// 원래라면 현재 비용과 다음 목적지로의 비용을 더하도록 되어있다.
			// 하지만 우리는? 최대 intensity를 구하는 것!
			if (max(curr_cost, next_cost) < dist[next_node]){
				dist[next_node] = max(curr_cost, next_cost);
				// 지나가는 경로 중에서는 최대 intensity지만,
				// 전체적으로 보았을 때는 최소가 되어야 한다.
				dijk_q.push({ dist[next_node], next_node });
			}
		}
	}

	answer.push_back(min_summit);
	answer.push_back(min_cost);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;

	make_map(paths);
	check_summit(summits);
	init_dist(n);
	dijkstra(answer, gates);

	cout << answer[0] << " " << answer[1] << '\n';
	return answer;
}
