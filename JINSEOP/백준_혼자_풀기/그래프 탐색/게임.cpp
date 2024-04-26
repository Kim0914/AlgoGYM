#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 999999999
typedef tuple<int, int, int> tiii;

int danger_num = 0, death_num = 0, st_x = 0, st_y = 0, end_x = 0, end_y = 0;
int world_map[501][501], dist[501][501];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void init_dist() {
	for (int i = 0; i <= 500; i++)
		for (int j = 0; j <= 500; j++)
			dist[i][j] = INF;
	// O(N^2) => 250000
	dist[0][0] = 0;
}

void do_dijkstra() {
	priority_queue<tiii, vector<tiii>, greater<>> dijk_q;
	dijk_q.push({0, 0, 0}); // 제일 앞에 값이 비용

	while (!dijk_q.empty()) {
		int curr_x = get<1>(dijk_q.top());
		int curr_y = get<2>(dijk_q.top());
		int curr_cost = get<0>(dijk_q.top());
		dijk_q.pop();

		if (curr_cost > dist[curr_x][curr_y])
			continue;

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];
			int next_cost = curr_cost + world_map[nx][ny];

			if ((nx >= 0 && nx <= 500) && (ny >= 0 && ny <= 500)) {
				if (dist[nx][ny] > next_cost && world_map[nx][ny] != INF) {
					dist[nx][ny] = next_cost;
					dijk_q.push({ next_cost, nx, ny });
				}
			}
		}
	}
}

int main() {
	OPTIMIZE;

	init_dist();
	cin >> danger_num;
	for (int i = 0; i < danger_num; i++) {
		cin >> st_x >> st_y >> end_x >> end_y;

		for (int j = min(st_x, end_x); j <= max(st_x, end_x); j++)
			for (int k = min(st_y, end_y); k <= max(st_y, end_y); k++)
				world_map[j][k] = 1; // 생명 비용
	}

	cin >> death_num;
	for (int i = 0; i < death_num; i++) {
		cin >> st_x >> st_y >> end_x >> end_y;

		for (int j = min(st_x, end_x); j <= max(st_x, end_x); j++)
			for (int k = min(st_y, end_y); k <= max(st_y, end_y); k++)
				world_map[j][k] = INF; // 아예 못가는 구역
	}

	do_dijkstra();
	if (dist[500][500] == INF)
		cout << -1;
	else
		cout << dist[500][500];
	return 0;
}
