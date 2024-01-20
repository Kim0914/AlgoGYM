#include <iostream>
#include <queue>
using namespace std;

int limit = 0, row = 0, col = 0;
int monkey_map[200][200];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 }; // 기본 4방향
int knight_dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knight_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // 나이트 이동 8방향
bool visit[200][200][31];
int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> bfs_q;
	// <현재 위치>, <나이트 위치, 현재 이동 횟수>
	bfs_q.push({ {0, 0}, {0, 0} });
	visit[0][0][0] = true;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first.first;
		int curr_y = bfs_q.front().first.second;
		int curr_knight = bfs_q.front().second.first;
		int curr_walk = bfs_q.front().second.second;
		bfs_q.pop();
		
		if (curr_x == row - 1 && curr_y == col - 1)
			return curr_walk;

		if (curr_knight < limit) {
		// 나이트 이동이 가능하면, 큐에 삽입
			for (int i = 0; i < 8; i++) {
				int nx = curr_x + knight_dx[i];
				int ny = curr_y + knight_dy[i];

				if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
					if (!visit[nx][ny][curr_knight + 1] && !monkey_map[nx][ny]) {
						bfs_q.push({ {nx, ny}, {curr_knight + 1, curr_walk + 1 } });
						// 나이트 횟수 1 감소
						visit[nx][ny][curr_knight + 1] = true;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
		// 나이트 이동이 가능하든 불가능 하든 기본 이동
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (!visit[nx][ny][curr_knight] && !monkey_map[nx][ny]) {
					bfs_q.push({ {nx, ny}, {curr_knight, curr_walk + 1 } });
					// 대신 나이트 횟수 감소 안함
					visit[nx][ny][curr_knight] = true;
				}
			}
		}
	}

	return -1;
}

int main() {
	cin >> limit >> col >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> monkey_map[i][j];
	// 시작점 0, 0 -> 도착점 row, col

	cout << bfs();
	return 0;
}
