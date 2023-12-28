#include <iostream>
using namespace std;

int board[19][19];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = {  0, 1, 1, 1, 0, -1, -1, -1 };
bool visit[19][19], is_found = false;
void dfs(int target, int depth, int dir, int curr_x, int curr_y, int st_x, int st_y) {
	visit[st_x][st_y] = true;

	if (depth == 5) {
		if (board[curr_x + dx[dir]][curr_y + dy[dir]] == target) {
			visit[curr_x + dx[dir]][curr_y + dy[dir]] = true;
			return;
		}
		else {
			is_found = true;

			cout << target << '\n';
			if(dir == 1 || dir == 2 || dir == 3 || dir == 4)
				cout << st_x + 1 << " " << st_y + 1;
			if(dir == 0 || dir == 5 || dir == 6 || dir == 7)
				cout << curr_x + 1 << " " << curr_y + 1;

			return;
		}
	}

	for (int i = 0; i < 8; i++) {
		int nx = curr_x + dx[i];
		int ny = curr_y + dy[i];

		if ((nx >= 0 && nx < 19) && (ny >= 0 && ny < 19)) {
			if (board[nx][ny] == target && !visit[nx][ny]) {
				if (dir == i || dir == 9)
					dfs(target, depth + 1, i, nx, ny, st_x, st_y);
			}
		}
	}
}

int main() {
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board[i][j] == 1 && !is_found) {
				dfs(1, 1, 9, i, j, i, j);
			}

			if (board[i][j] == 2 && !is_found) {
				dfs(2, 1, 9, i, j, i, j);
			}
		}
	}
	
	if (!is_found)
		cout << 0;
			
	return 0;
}
