#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 999999999

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> bus_q; 
// 도착지, 가중치 저장 후 가중치로 오름차순
void init_map(int start, vector<int>& dist) {
	dist[start] = 0;
}

void dijkstra(int start, int dest, vector<vector<int>> bus_map, vector<int>& dist) {
	bus_q.push({start, 0});

	while (!bus_q.empty()) {
		int curr = bus_q.top().first;
		int curr_weight = bus_q.top().second;
		bus_q.pop();

		if (curr_weight > dist[curr])
			continue;

		for (int i = 0; i < bus_map[curr].size(); i++) {
			if (bus_map[curr][i] != INF) {
				int next = i;
				int next_weight = dist[curr] + bus_map[curr][i];

				if (dist[next] > next_weight) {
					dist[next] = next_weight;
					bus_q.push({ next, dist[next]});
				}
			}
		}
	}
}

int main() {
	int vertex = 0, edge = 0, start = 0, dest = 0, weight = 0;
	cin >> vertex >> edge;

	vector<vector<int>> bus_map(vertex + 1, vector<int>(vertex + 1, INF));
	vector<int> dist(vertex + 1, INF);

	for (int i = 0; i < edge; i++) {
		cin >> start >> dest >> weight;
		if(bus_map[start][dest] > weight) // 인접행렬은 이 부분이 중요하다!!
			bus_map[start][dest] = weight; 
		// 지도 초기화
	}

	cin >> start >> dest;

	init_map(start, dist);
	dijkstra(start, dest, bus_map, dist); // 다익스트라 알고리즘

	cout << dist[dest];
	return 0;
}
