#include <string>
#include <vector>
#include <iostream>
using namespace std;

int row = 0, answer = 0;
int permutation[5], board[20][20], copied_board[20][20];
void copy_board() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			copied_board[i][j] = board[i][j];
}

void move_left() {
	// 블록을 왼쪽으로 옮기는 과정
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row - 1; j++) {
			bool can_move = false;

			if (copied_board[i][j] = 0) {
			// 보드의 해당 행에서 0이 아닌 칸을 만날 때 까지 탐색한다.
				int k = j + 1;
				while (k < row) {
					if (copied_board != 0) {
						can_move = true;
						break;
					}

					k++;
				}
			// 0이 아닌 칸을 만났으면, 해당 칸을 탐색 시작 위치로 옮긴다.
			// 예를 들어, 0 0 0 2 와 같은 칸이 있었다면?
			// k가 3에서 멈추고, 2 0 0 0 으로 만드는 과정이다.
				if (can_move) {
					copied_board[i][j] = copied_board[i][k];
					copied_board[i][k] = 0;
				}
			}
		}
	}

	// 여긴 같은 숫자의 블록이 있으면 합치는 로직
	// 위의 로직에서 수를 모두 왼쪽으로 옮겼다. 이제 합칠 차례!
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row - 1; j++) {
			if (copied_board[i][j] == copied_board[i][j + 1]) {
				copied_board[i][j] = copied_board[i][j] * 2;
				copied_board[i][j + 1] = 0;
			}
		}
	}

	// 위의 로직에서 미처 다 옮기지 못한 블럭이 있는 경우
	// 처음 로직과 동일한 방식으로 마저 다 옮김
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row - 1; j++) {
			bool can_move = false;
			if (copied_board[i][j] = 0) {

				int k = j + 1;
				while (k < row) {
					if (copied_board != 0) {
						can_move = true;
						break;
					}

					k++;
				}

				if (can_move) {
					copied_board[i][j] = copied_board[i][k];
					copied_board[i][k] = 0;
				}
			}
		}
	}
}

void move_right() {
	for (int i = 0; i < row; i++) {
		for (int j = row - 1; j >= 1; j--) {
			bool can_move = false;
			if (copied_board[i][j] == 0) {
				int k = j - 1;
				while (k >= 0) {
					if (copied_board[i][k] != 0) {
						can_move = true;
						break;
					}

					k--;
				}

				if (can_move) {
					copied_board[i][j] = copied_board[i][k];
					copied_board[i][k] = 0;
				}
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = row - 1; j >= 1; j--) {
			if (copied_board[i][j] == copied_board[i][j - 1]) {
				copied_board[i][j] = copied_board[i][j] * 2;
				copied_board[i][j - 1] = 0;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = row - 1; j >= 1; j--) {
			bool can_move = false;
			if (copied_board[i][j] == 0) {
				int k = j - 1;
				while (k >= 0) {
					if (copied_board[i][k] != 0) {
						can_move = true;
						break;
					}

					k--;
				}

				if (can_move) {
					copied_board[i][j] = copied_board[i][k];
					copied_board[i][k] = 0;
				}
			}
		}
	}
}

void move_upward() {
	for (int i = 0; i < row - 1; i++) {
		for (int j = 0; j < row; j++) {
			bool can_move = true;
			if (copied_board[i][j] == 0) {
				int k = i + 1;
				while (k < row) {
					if (copied_board[k][j] != 0) {
						can_move = true;
						break;
					}

					k++;
				}

				if (can_move) {
					copied_board[i][j] = copied_board[k][j];
					copied_board[k][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < row - 1; i++) {
		for (int j = 0; j < row; j++) {
			if (copied_board[i][j] == copied_board[i + 1][j]) {
				copied_board[i][j] = copied_board[i][j] * 2;
				copied_board[i + 1][j] = 0;
			}
		}
	}

	for (int i = 0; i < row - 1; i++) {
		for (int j = 0; j < row; j++) {
			bool can_move = true;
			if (copied_board[i][j] == 0) {
				int k = i + 1;
				while (k < row) {
					if (copied_board[k][j] != 0) {
						can_move = true;
						break;
					}

					k++;
				}

				if (can_move) {
					copied_board[i][j] = copied_board[k][j];
					copied_board[k][j] = 0;
				}
			}
		}
	}
}

void move_downward() {
	for (int i = row - 1; i >= 1; i--) {
		for (int j = 0; j < row; j++) {
			bool can_move = false;
			if (copied_board[i][j] == 0) {
				int k = i - 1;
				while (k >= 0) {
					if (copied_board[k][j] != 0) {
						can_move = true;
						break;
					}

					k--;
				}

				if (can_move) {
					copied_board[i][j] = copied_board[k][j];
					copied_board[k][j] = 0;
				}
			}
		}
	}

	for (int i = row - 1; i >= 1; i--) {
		for (int j = 0; j < row; j++) {
			if (copied_board[i][j] == copied_board[i - 1][j]) {
				copied_board[i][j] = copied_board[i][j] * 2;
				copied_board[i - 1][j] = 0;
			}
		}
	}

	for (int i = row - 1; i >= 1; i--) {
		for (int j = 0; j < row; j++) {
			bool can_move = false;
			if (copied_board[i][j] == 0) {
				int k = i - 1;
				while (k >= 0) {
					if (copied_board[k][j] != 0) {
						can_move = true;
						break;
					}

					k--;
				}

				if (can_move) {
					copied_board[i][j] = copied_board[k][j];
					copied_board[k][j] = 0;
				}
			}
		}
	}
}

int calculate_max() {
	int max_v = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			max_v = max(copied_board[i][j], max_v);

	return max_v;
}

void play_2048() {
	for (int i = 0; i < 5; i++) {
		int dir = permutation[i];
		switch (dir)
		{
		case 0:
			move_left();
			break;
		case 1:
			move_right();
			break;
		case 2:
			move_upward();
			break;
		case 3:
			move_downward();
			break;
		}
	}

	answer = max(answer, calculate_max());
}

void make_permutation(int depth) {
	if (depth == 5) {
		copy_board(); // 맵 복사
		play_2048(); // 여기서 만든 조합대로 게임 진행
		return;
	}

	for (int i = 0; i < 4; i++) {
		permutation[depth] = i;
		make_permutation(depth + 1);
	}
}

int main() {
	cin >> row;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> board[i][j];

	make_permutation(0);
	cout << answer;

	return 0;
}
