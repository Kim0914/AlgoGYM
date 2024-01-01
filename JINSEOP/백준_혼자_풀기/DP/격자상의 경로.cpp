#include <iostream>
#include <queue>
using namespace std;

int row = 0, col = 0, mark = 0;
int board[15][15];
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };
pair<int, int> marked_pos;
void fill_board(int start_x, int start_y, int target_x, int target_y) {
	queue<pair<int, int>> bfs_q;
	bfs_q.push({ start_x, start_y });

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 2; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (nx == target_x && ny == target_y) {
					board[nx][ny]++;
					continue;
				}

				bfs_q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> row >> col >> mark;

	if (mark != 0) {
		marked_pos = { (mark / col), (mark % col) - 1 };
		fill_board(0, 0, marked_pos.first, marked_pos.second);
		fill_board(marked_pos.first, marked_pos.second, row - 1, col - 1);
		cout << board[marked_pos.first][marked_pos.second] * board[row - 1][col - 1];
	}
	else {
		fill_board(0, 0, row - 1, col - 1);
		cout << board[row - 1][col - 1];
	}

	return 0;
}
