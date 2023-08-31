#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999

int row = 0, answer = INF, cnt = 0, cave_map[125][125];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };
bool visit[125][125];
void bfs(pair<int, int> start) {
	queue<pair <int, pair<int, int>>> bfs_q;
	bfs_q.push({ cave_map[0][0], start });
	visit[0][0] = true;

	while (!bfs_q.empty()) {
		pair<int, int> curr = bfs_q.front().second;
		int curr_cost = bfs_q.front().first;
		bfs_q.pop();

		cout << curr.first << " " << curr.second << '\n';
		if (curr.first == row - 1 && curr.second == row - 1)
			answer = min(answer, curr_cost);

		for (int i = 0; i < 4; i++) {
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row)) {
				if (!visit[nx][ny]) {
					bfs_q.push({ curr_cost + cave_map[nx][ny], {nx, ny} });
					visit[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	while (true) {
		cin >> row;

		if (row == 0)
			break;

		answer = 0; cnt++;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < row; j++)
				cin >> cave_map[i][j];

		bfs({0, 0});
		cout << "Problem " << cnt << ": " << answer << '\n';
	}

	return 0;
}
