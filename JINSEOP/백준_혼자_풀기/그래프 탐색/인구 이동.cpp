#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> bfs_q;
vector<pair<int, int>> coord_store;
int num = 0, lo_bound = 0, up_bound = 0, world[51][51];
int sum = 0, days = 0;
bool isUnion = true, visit[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void clear_visit() {
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			visit[i][j] = false;
}

void bfs(int x, int y) {
	coord_store.push_back({ x, y });
	bfs_q.push({ x, y });
	visit[x][y] = true;
	sum = world[x][y];

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < num) && (ny >= 0 && ny < num)) {
				if (!visit[nx][ny]) {
					if (abs(world[curr_x][curr_y] - world[nx][ny]) >= lo_bound && abs(world[curr_x][curr_y] - world[nx][ny]) <= up_bound) {
						visit[nx][ny] = true;
						bfs_q.push({ nx, ny });

						coord_store.push_back({ nx, ny });
						sum += world[nx][ny];
					}
				}
			}
		}
	}
}

int main() {
	cin >> num >> lo_bound >> up_bound;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> world[i][j];
		}
	}

	while (isUnion) {
		isUnion = false;

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (!visit[i][j]) {
					coord_store.clear(); // 매번 마다 비워줘야 연합 확인 가능
					bfs(i, j);
				}

				if (coord_store.size() >= 2) {
					isUnion = true;

					for (int i = 0; i < coord_store.size(); i++)
						world[coord_store[i].first][coord_store[i].second] = (sum / coord_store.size());
				}
			}
		}

		if (isUnion)
			days++; // 바퀴 수 증가
		clear_visit();
	}

	cout << days;

	return 0;
}
