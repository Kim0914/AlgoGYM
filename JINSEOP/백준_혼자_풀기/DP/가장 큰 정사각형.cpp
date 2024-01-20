#include <iostream>
using namespace std;

int row = 0, col = 0;
int square_board[1001][1001];
int main() {
	cin >> row >> col;

	string str_for_input = "";
	for (int i = 1; i <= row; i++) {
		cin >> str_for_input;

		for (int j = 1; j <= col; j++) {
			square_board[i][j] = str_for_input[j - 1] - '0';
		}
	}

	int max_v = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (square_board[i][j] != 0) {
				square_board[i][j] = min(square_board[i - 1][j], min(square_board[i][j - 1], square_board[i - 1][j - 1])) + 1;
				max_v = max(max_v, square_board[i][j]);
			}

	cout << max_v * max_v;
	return 0;
}
