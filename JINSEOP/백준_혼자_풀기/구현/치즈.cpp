#include <iostream>
#include <queue>
using namespace std;
#define pii pair<int, int>

int row = 0, col = 0;
int cheese_map[100][100];
bool visit[100][100], rot_check[100][100];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 , -1 };
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

void bfs(int st_x, int st_y) {
	queue<pii> bfs_q;
	bfs_q.push({ st_x, st_y });
	visit[st_x][st_y] = true;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		int rot_count = 0;
		bfs_q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if (cheese_map[nx][ny] == 9)
				rot_count++;
			if (rot_count >= 2)
				rot_check[curr_x][curr_y] = true;

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (!visit[nx][ny] && cheese_map[nx][ny] == 1) {
					bfs_q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
		}
	}
}

void fill_external(int st_x, int st_y) {
	queue<pii> bfs_q;
	bfs_q.push({ st_x, st_y });
	visit[st_x][st_y] = true;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (cheese_map[nx][ny] == 1)
					continue;

				if (!visit[nx][ny]) {
					bfs_q.push({ nx, ny });
					cheese_map[nx][ny] = 9;
					visit[nx][ny] = true;
				}
			}
		}
	}
}

void clear_visit() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			visit[i][j] = false;
}

int main() {
	optimize();
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> cheese_map[i][j];
	cheese_map[0][0] = 9;

	int answer = 0;
	while (true) {
		bool is_rotten = true;
		// 처음 위치부터 bfs를 돌려 내부 공간을 파악한다.
		fill_external(0, 0);
		// 이 부분에서 bfs를 돌려 지울 부분을 체크한다.
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (!visit[i][j] && cheese_map[i][j])
					bfs(i, j);
		// 이 부분에서 맵을 훑어 체크한 부분을 지운다.
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (rot_check[i][j]) {
					cheese_map[i][j] = 9;
					rot_check[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (cheese_map[i][j] == 1) {
					is_rotten = false;
					break;
				}
			}
		}

		answer++;
		if (is_rotten)
			break;
		clear_visit();
	}

	cout << answer;
	return 0;
}
