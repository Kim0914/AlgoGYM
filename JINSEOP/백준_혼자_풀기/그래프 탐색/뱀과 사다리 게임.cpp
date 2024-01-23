#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
#define pii pair<int, int>

int ladder = 0, snake = 0, from = 0, to = 0;
unordered_map<int, int> board_state;
bool visit[101];
int bfs() {
	queue<pair<int, int>> bfs_q;
	bfs_q.push({ 1, 0 }); // 시작 지점
	visit[1] = true;

	while (!bfs_q.empty()) {
		int curr_cell = bfs_q.front().first;
		int dice_count = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 1; i <= 6; i++) {
			// 주사위 눈 6개
			int next_cell = curr_cell + i;
			if (board_state[next_cell])
				next_cell = board_state[next_cell];
			// 뱀이나 사다리가 있으면 해당 위치로 이동
			if (next_cell == 100)
				return dice_count + 1;

			if (next_cell < 100 && !visit[next_cell]) {
				bfs_q.push({ next_cell, dice_count + 1 });
				visit[next_cell] = true;
			// 어차피 갔던데 또 가면 최소가 안됨
			}
		}
	}
}

int main() {
	cin >> ladder >> snake;
	for (int i = 0; i < ladder; i++) {
		cin >> from >> to;
		board_state[from] = to;
	}
	for (int i = 0; i < snake; i++) {
		cin >> from >> to;
		board_state[from] = to;
	}
	// 사다리와 뱀 모두 맵에 등록

	cout << bfs();
	return 0;
}
