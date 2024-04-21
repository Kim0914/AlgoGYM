#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define piii pair<pair<int, int>, int>

int row = 0, col = 0, max_dist = 0, answer = 0;
int maze[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[51][51];
void clear_visit(){
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			visit[i][j] = false;
}

void bfs(int st_x, int st_y) {
	queue<piii> bfs_q;
	visit[st_x][st_y] = true;
	bfs_q.push({ {st_x, st_y}, 0 });

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first.first;
		int curr_y = bfs_q.front().first.second;
		int curr_dist = bfs_q.front().second;
		bfs_q.pop();

		if (curr_dist >= max_dist) {
			int passwd = maze[st_x][st_y] + maze[curr_x][curr_y];

			if (max_dist == curr_dist)
				answer = max(answer, passwd);
			else
				answer = passwd;

			max_dist = curr_dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (!visit[nx][ny] && maze[nx][ny]) {
					bfs_q.push({ { nx, ny }, curr_dist + 1});
					visit[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	OPTIMIZE;

	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> maze[i][j];

	// 1. 항상 두 방 사이의 최단 경로로 이동한다.
	// 2. 1번 규칙을 만족하는 경로 중 가장 긴 경로의 시작 방 끝 방 숫자의 합
	// 3. 0이 적힌 방은 들어갈 수 없다.
	// 4. 시작 방과 끝 방은 동일한 방일 수도 있다!
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (maze[i][j]) {
				bfs(i, j);
				clear_visit();
			}
		}
	}

	cout << answer;
	return 0;
}
