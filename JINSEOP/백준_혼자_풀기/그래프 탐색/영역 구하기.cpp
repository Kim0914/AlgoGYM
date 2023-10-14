#include <iostream>
#include <queue>
using namespace std;

char grid[100][100];
bool visit[100][100];
int row = 0, col = 0, rects = 0;
int start_x = 0, start_y = 0, end_x = 0, end_y = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> bfs_q;
int bfs(int st_x, int st_y) {
	int cnt = 1;

	bfs_q.push({ st_x, st_y });
	visit[st_x][st_y] = true;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col) && grid[nx][ny] != '#') {
				if (!visit[nx][ny]) {
					bfs_q.push({ nx, ny });
					visit[nx][ny] = true;
					cnt++;
				}
			}
		}
	}

	return cnt;
}

int main(){
	priority_queue<int, vector<int>, greater<>> answer_q;
	cin >> row >> col >> rects;

	for (int i = 0; i < rects; i++) {
		cin >> start_y >> start_x >> end_y >> end_x;

		for (int i = start_x; i < end_x; i++)
			for (int j = start_y; j < end_y; j++)
				grid[i][j] = '#';
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!visit[i][j] && grid[i][j] != '#')
				answer_q.push(bfs(i, j));
		}
	}

	cout << answer_q.size() << '\n';
	while (!answer_q.empty()) {
		cout << answer_q.top() << " ";
		answer_q.pop();
	}

	return 0;
}
