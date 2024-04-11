#include <iostream>
#include <queue>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define piii pair<pair<int, int>, int>

int eleph_x = 0, eleph_y = 0, king_x = 0, king_y = 0;
int dx[8] = {-3, -2, 2, 3, 3, 2, -2, -3};
int dy[8] = {2, 3, 3, 2, -2, -3, -3, -2};
bool visit[10][9];
bool validate(int nx, int ny, int curr_x, int curr_y, int goal_x, int goal_y) {
	if (nx - curr_x == -3 && ny - curr_y == 2)
		if ((curr_x - 1 == goal_x && curr_y == goal_y) || (curr_x - 2 == goal_x && curr_y + 1 == goal_y))
			return false;
	if (nx - curr_x == -2 && ny - curr_y == 3)
		if ((curr_x == goal_x && curr_y + 1 == goal_y) || (curr_x - 1 == goal_x && curr_y + 2 == goal_y))
			return false;
	if (nx - curr_x == 2 && ny - curr_y == 3)
		if ((curr_x == goal_x && curr_y + 1 == goal_y) || (curr_x + 1 == goal_x && curr_y + 2 == goal_y))
			return false;
	if (nx - curr_x == 3 && ny - curr_y == 2)
		if ((curr_x + 1 == goal_x && curr_y == goal_y) || (curr_x + 2 == goal_x && curr_y + 1 == goal_y))
			return false;
	if (nx - curr_x == 3 && ny - curr_y == -2)
		if ((curr_x + 1 == goal_x && curr_y == goal_y) || (curr_x + 2 == goal_x && curr_y - 1 == goal_y))
			return false;
	if (nx - curr_x == 2 && ny - curr_y == -3)
		if ((curr_x == goal_x && curr_y - 1 == goal_y) || (curr_x + 1 == goal_x && curr_y - 2 == goal_y))
			return false;
	if (nx - curr_x == -2 && ny - curr_y == -3)
		if ((curr_x == goal_x && curr_y - 1 == goal_y) || (curr_x - 1 == goal_x && curr_y - 2 == goal_y))
			return false;
	if (nx - curr_x == -3 && ny - curr_y == -2)
		if ((curr_x - 1 == goal_x && curr_y == goal_y) || (curr_x - 2 == goal_x && curr_y - 1 == goal_y))
			return false;

	return true;
}

int bfs(int start_x, int start_y, int goal_x, int goal_y) {
	queue<piii> bfs_q;
	visit[start_x][start_y] = true;
	bfs_q.push({ { start_x, start_y }, 0 });

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first.first;
		int curr_y = bfs_q.front().first.second;
		int curr_cost = bfs_q.front().second;
		bfs_q.pop();
		
		if (curr_x == goal_x && curr_y == goal_y)
			return curr_cost;

		for (int i = 0; i < 8; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < 10) && (ny >= 0 && ny < 9) && validate(nx, ny, curr_x, curr_y, goal_x, goal_y) && !visit[nx][ny]) {
				visit[nx][ny] = true;
				bfs_q.push({ { nx, ny }, curr_cost + 1 });
			}
		}
	}

	return -1;
}

int main() {
	OPTIMIZE;

	cin >> eleph_x >> eleph_y;
	cin >> king_x >> king_y;

	cout << bfs(eleph_x, eleph_y, king_x, king_y);
	return 0;
}
