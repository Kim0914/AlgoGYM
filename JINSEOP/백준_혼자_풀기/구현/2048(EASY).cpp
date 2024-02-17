#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int row = 0, answer = 0;
int copied_board[20][20], board[20][20];
void copy_board() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			copied_board[i][j] = board[i][j];
}

void recopy_board() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			board[i][j] = copied_board[i][j];
}

void move_left() {
	queue<int> move_q;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (board[i][j])
				move_q.push(board[i][j]);
			// 내가 옮겨야 하는 셀을 큐에 집어 넣는다.
			board[i][j] = 0;
		}

		int idx = 0; // 왼쪽으로 옮겨야 하니 0부터 시작
		while (!move_q.empty()) {
			int cell = move_q.front();
			move_q.pop();

			if (!board[i][idx]) // 0인 칸으로 셀을 옮김
				board[i][idx] = cell;
			else if (board[i][idx] == cell) {
				board[i][idx] *= 2;
				idx++;
			// 만약 같은 값이 이미 있다면, 합쳐주자!
			}
			else {
				idx++;
				board[i][idx] = cell;
			// 같은 값도 아니고 0도 아니라면?
			// 다음 칸으로 인덱스를 옮기고 셀 저장
			}
		}
	}
}

void move_right() {
	queue<int> move_q;
	// 왼쪽과 반대로!
	for (int i = 0; i < row; i++) {
		for (int j = row - 1; j >= 0; j--) {
			if (board[i][j])
				move_q.push(board[i][j]);
			board[i][j] = 0;
		}

		int idx = row - 1;
		while (!move_q.empty()) {
			int cell = move_q.front();
			move_q.pop();

			if (!board[i][idx])
				board[i][idx] = cell;
			else if (board[i][idx] == cell) {
				board[i][idx] *= 2;
				idx--;
			}
			else {
				idx--;
				board[i][idx] = cell;
			}
		}
	}
}

void move_upward() {
	queue<int> move_q;

	for (int j = 0; j < row; j++) {
		for (int i = 0; i < row; i++) {
			if (board[i][j])
				move_q.push(board[i][j]);
			board[i][j] = 0;
		}

		int idx = 0;
		while (!move_q.empty()) {
			int cell = move_q.front();
			move_q.pop();

			if (!board[idx][j])
				board[idx][j] = cell;
			else if (board[idx][j] == cell) {
				board[idx][j] *= 2;
				idx++;
			}
			else {
				idx++;
				board[idx][j] = cell;
			}
		}
	}
}

void move_downward() {
	queue<int> move_q;
	// 윗 방향이랑 반대로!
	for (int j = 0; j < row; j++) {
		for (int i = row - 1; i >= 0; i--) {
			if (board[i][j])
				move_q.push(board[i][j]);
			board[i][j] = 0;
		}

		int idx = row - 1;
		while (!move_q.empty()) {
			int cell = move_q.front();
			move_q.pop();

			if (!board[idx][j])
				board[idx][j] = cell;
			else if (board[idx][j] == cell) {
				board[idx][j] *= 2;
				idx--;
			}
			else {
				idx--;
				board[idx][j] = cell;
			}
		}
	}
}

int calculate_max() {
	int max_v = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			max_v = max(board[i][j], max_v);

	return max_v;
}

void play_2048(int depth) {
	if (depth == 5)
		return;

	copy_board();
	for (int i = 0; i < 4; i++) {
		switch (i)
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

		answer = max(answer, calculate_max());
		play_2048(depth + 1);
		recopy_board();
	}
}

int main() {
	cin >> row;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> board[i][j];

	play_2048(0);
	cout << answer;
	return 0;
}
