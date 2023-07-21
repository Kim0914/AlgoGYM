#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 999999999

vector<pair<int, int>> bus_map[1001];
int dist[1001], paths[1001];
vector<int> paths_vec;
struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second < b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> bus_q; 
// 도착지, 가중치 저장 후 가중치로 오름차순
void init_map(int start) {
	fill_n(dist, 1001, INF);
	dist[start] = 0;
}

void dijkstra(int start, int dest) {
	bus_q.push({start, 0});

	while (!bus_q.empty()) {
		int curr = bus_q.top().first;
		int curr_weight = bus_q.top().second;
		bus_q.pop();

		if (curr_weight > dist[curr])
			continue;

		for (int i = 0; i < bus_map[curr].size(); i++) {
				int next = bus_map[curr][i].first;
				int next_weight = dist[curr] + bus_map[curr][i].second;

				if (dist[next] > next_weight) {
					dist[next] = next_weight;
					paths[next] = curr;
					bus_q.push({ next, dist[next]});
				}
		}
	}
}

int main() {
	int vertex = 0, edge = 0, start = 0, dest = 0, weight = 0;

	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> start >> dest >> weight;
		bus_map[start].push_back({ dest, weight });
	}
	cin >> start >> dest;

	init_map(start);
	dijkstra(start, dest);

	int cursor = dest;
	while (cursor) {
		paths_vec.push_back(cursor);
		cursor = paths[cursor];
	}

	cout << dist[dest] << "\n" << paths_vec.size() << "\n";
	for (int i = paths_vec.size() - 1; i >= 0; i--)
		cout << paths_vec[i] << " ";

	return 0;
}
