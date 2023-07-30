#include <iostream>
#include <vector>
using namespace std;

char home_map[5][5];
bool visit[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0 };
int row = 0, col = 0, target_dist = 0, cnt = 0;
void backtrack(int curr_x, int curr_y, int dist) {
	visit[curr_x][curr_y] = true;

	if (curr_x == 0 && curr_y == col - 1) {
		if (dist == target_dist)
			cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = curr_x + dx[i];
		int ny = curr_y + dy[i];

		if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
			if (!visit[nx][ny] && home_map[nx][ny] == '.') {
				backtrack(nx, ny, dist + 1);
				visit[nx][ny] = false;
			}
		}
 	}
}

int main() {
	cin >> row >> col >> target_dist;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> home_map[i][j];
		}
	}

	backtrack(row - 1, 0, 1);
	cout << cnt;
	return 0;
}
