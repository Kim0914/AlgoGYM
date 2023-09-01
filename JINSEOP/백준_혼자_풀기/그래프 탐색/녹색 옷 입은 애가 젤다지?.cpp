#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999

int row = 0, answer = INF, cnt = 0, cave_map[125][125], dist[125][125];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };
void fill_dist() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			dist[i][j] = INF;
}

void dijkstra(pair<int, int> start) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> dijk_q;
	dijk_q.push({ cave_map[0][0], start });
	dist[0][0] = cave_map[0][0];
	// 다익스트라 시작점 초기화

	while (!dijk_q.empty()) {
		pair<int, int> curr = dijk_q.top().second;
		int curr_cost = dijk_q.top().first;
		dijk_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i]; // BFS 동일하게 진행

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row)) {
				int next_cost = curr_cost + cave_map[nx][ny];

				if (dist[nx][ny] > next_cost) {
					dist[nx][ny] = next_cost; // 새로운 값이 더 작으면 갱신
					dijk_q.push({dist[nx][ny], {nx, ny}});
				}
			}
		}
	}
	
	answer = dist[row - 1][row - 1];
}

int main() {
	while (true) {
		cin >> row;

		if (row == 0)
			break;

		answer = 0; cnt++;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < row; j++)
				cin >> cave_map[i][j];
		
		fill_dist();
		dijkstra({0, 0});
		cout << "Problem " << cnt << ": " << answer << '\n';
	}

	return 0;
}
