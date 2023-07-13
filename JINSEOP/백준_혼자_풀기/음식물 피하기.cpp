#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int, int>> bfs_q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int row = 0, col = 0, cnt = 0, max_cnt = 0;
void bfs(int x, int y, vector<vector<bool>> food_map, vector<vector<bool>> &visit) {
	bfs_q.push({ x, y });
	visit[x][y] = true;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx <= row) && (ny >= 0 && ny <= col)) {
				if (!visit[nx][ny] && food_map[nx][ny]) {
					visit[nx][ny] = true;
					bfs_q.push({ nx, ny });
					cnt++;
				}
			}
		}
	}
}

int main() {
	int food = 0, trash_x = 0, trash_y = 0;

	cin >> row >> col >> food;
	vector<vector<bool>> food_map(row, vector<bool>(col, false));
	vector<vector<bool>> visit(row, vector<bool>(col, false));
		
	for (int i = 0; i < food; i++) {
		cin >> trash_x >> trash_y;
		food_map[trash_x - 1][trash_y - 1] = true;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!visit[i][j] && food_map[i][j]) {
				cnt = 0;
				bfs(i, j, food_map, visit);
				if (max_cnt < cnt)
					max_cnt = cnt;
			}
		}
	}

	return 0;
}
