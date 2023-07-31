#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int story = 0, row = 0, col = 0;
int dx[6] = {1, -1, 0, 0, 0, 0 };
int dy[6] = {0, 0, -1, 0, 1, 0};
int dz[6] = {0, 0, 0, 1, 0, -1}; // 6방향
char building_map[31][31][31];
bool visit[31][31][31];

void clear_visit() {
	memset(visit, false, sizeof(visit));
}

int bfs(pair<pair<int, int>, pair<int, int>> start_pair) {
	queue<pair<pair<int, int>, pair<int, int>>> bfs_q;
	bfs_q.push(start_pair);
	visit[start_pair.first.second][start_pair.second.first][start_pair.second.second] = true;

	while (!bfs_q.empty()) {
		int curr_time = bfs_q.front().first.first;
		int curr_x = bfs_q.front().first.second; // z축
		int curr_y = bfs_q.front().second.first; // y축
		int curr_z = bfs_q.front().second.second; // x축

		if (building_map[curr_x][curr_y][curr_z] == 'E')
			return curr_time;

		bfs_q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = curr_x + dx[i]; // z축
			int ny = curr_y + dy[i]; // y축
			int nz = curr_z + dz[i]; // x축

			if ((nx >= 0 && nx < story) && (ny >= 0 && ny < row) && (nz >= 0 && nz < col)) {
				if (!visit[nx][ny][nz] && building_map[nx][ny][nz] != '#') {
					bfs_q.push({ {curr_time + 1 ,nx}, {ny, nz} });
					visit[nx][ny][nz] = true;
				}
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int result = 0;
		pair<pair<int, int>, pair<int, int>> start_pair;
		cin >> story >> row >> col;

		if (story == 0 && row == 0 && col == 0)
			break;

		clear_visit();
		for (int i = 0; i < story; i++) { // 층
			for (int j = 0; j < row; j++) { // 열
				for (int k = 0; k < col; k++) { // 행
					cin >> building_map[i][j][k];
					if (building_map[i][j][k] == 'S')
						start_pair = { {0, i}, {j, k} };
				}
			}
		}

		result = bfs(start_pair);
		if (result == -1)
			cout << "Trapped!";
		else
			cout << "Escaped in " << result << " minute(s).";
	}

	return 0;
}
