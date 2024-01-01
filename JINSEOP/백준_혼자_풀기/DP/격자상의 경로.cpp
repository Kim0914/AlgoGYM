#include <iostream>
using namespace std;

int row = 0, col = 0, mark = 0;
int board[16][16], marked_board[16][16];
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };
pair<int, int> marked_pos;
void make_marked_pos() {
	int digit = 1;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (digit == mark) {
				marked_pos = { i, j };
				return;
			}

			digit++;
		}
	}
}

void fill_board(int start_x, int start_y, int target_x, int target_y, int target_board[16][16]) {
	for (int i = start_x; i <= target_x; i++) {
		for (int j = start_y; j <= target_y; j++) {
			if (i == start_x && j == start_y)
				continue;

			target_board[i][j] = target_board[i - 1][j] + target_board[i][j - 1];
		}
	}
}

int main() {
	cin >> row >> col >> mark;
	board[1][1] = 1;

	if (mark != 0) {
		make_marked_pos();
		marked_board[marked_pos.first][marked_pos.second] = 1;

		fill_board(1, 1, marked_pos.first, marked_pos.second, board);
		fill_board(marked_pos.first, marked_pos.second, row, col, marked_board);
		cout << board[marked_pos.first][marked_pos.second] * marked_board[row][col];
	}
	else {
		fill_board(1, 1, row, col, board);
		cout << board[row][col];
	}

	return 0;
}
