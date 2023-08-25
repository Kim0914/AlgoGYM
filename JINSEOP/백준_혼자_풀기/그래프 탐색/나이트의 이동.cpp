#include <iostream>
#include <queue>
using namespace std;

int tc = 0, row = 0, knight_x = 0;
pair<int, int> knight_start, goal;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1}; // 나이트는 총 8방향으로 움직일 수 있다.
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
         // 상좌, 상우, 우상, 우하, 하우, 하좌, 좌하, 좌상
int chess_board[301][301];
bool visit[301][301];
void clear_visit() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			visit[i][j] = false;
}

int bfs() {
	queue<pair<int, pair<int, int>>> bfs_q; // 초기화를 위해

	bfs_q.push({ 0, knight_start }); // 시작
	visit[knight_start.first][knight_start.second] = true;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().second.first;
		int curr_y = bfs_q.front().second.second;
		int curr_cnt = bfs_q.front().first;
		bfs_q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row)) {
				if (!visit[nx][ny]) {
					if (nx == goal.first && ny == goal.second)
						return (curr_cnt + 1);

					bfs_q.push({ curr_cnt + 1, { nx, ny }});
					visit[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> row;
		cin >> knight_start.first >> knight_start.second;
		cin >> goal.first >> goal.second;

		if ((knight_start.first == goal.first) && (knight_start.second == goal.second))
			cout << 0 << '\n';
		else
			cout << bfs() << "\n";
		clear_visit();
	}

	return 0;
}
