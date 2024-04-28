#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 99999999
typedef pair<int, pair<int, int>> piii;

int row = 0;
vector<string> maze;
int dist[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void init_dist() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			dist[i][j] = INF;
	dist[0][0] = 0;
}

void do_dijkstra() {
	queue<piii> dijk_q;
	dijk_q.push({ 0, {0, 0} });

	while (!dijk_q.empty()) {
		int curr_x = dijk_q.front().second.first;
		int curr_y = dijk_q.front().second.second;
		int curr_cost = dijk_q.front().first;
		dijk_q.pop();

		if (curr_cost > dist[curr_x][curr_y])
			continue; // 지금 가려는 곳 비용이 더 크면 진행안해도 됨

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];
			int next_cost = curr_cost;

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row)) {
				if (maze[nx][ny] == '0')
					next_cost += 1; // 검은 방의 경우 비용을 1 늘려야 함

				if ((dist[nx][ny] > next_cost)) {
					dijk_q.push({ next_cost, {nx, ny} });
					dist[nx][ny] = next_cost;
				}
			}
		}
	}
}

int main() {
	OPTIMIZE;
	cin >> row;
	
	string map_row = "";
	for (int i = 0; i < row; i++) {
		cin >> map_row;
		maze.push_back(map_row);
	} // 1이 적힌 곳만 지나갈 수 있다.

	// 검은 방을 지나는 비용이 1이라고 생각하면?
	// 마지막 출구까지 최소 비용을 계산하면 될 것이다.
	init_dist();
	do_dijkstra();
	
	cout << dist[row - 1][row - 1];
	return 0;
}
