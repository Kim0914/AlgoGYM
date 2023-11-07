#include <iostream>
#include <queue>
using namespace std;

int row = 0, answer = 0;
int house[17][17];
queue<pair<int, pair<int, int>>> bfs_q;
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool check_wall(int direction, int x, int y) {
	switch (direction)
	{
	// 가로로 가는 경우
	case 0:
		return (y + 1 < row) && (house[x][y + 1] != 1);
	// 대각선으로 가는 경우
	case 1:
		return (x + 1 < row) && (y + 1 < row)
			&& (house[x][y + 1] != 1 && house[x + 1][y] != 1 && house[x + 1][y + 1] != 1);
	// 세로로 가는 경우
	case 2:
		return (x + 1 < row) && (house[x + 1][y] != 1);
	default:
		break;
	}
}

void bfs(int head_x, int head_y) {
	bfs_q.push({0, {head_x, head_y} });
	// 0이 가로 1이 45도 2가 세로

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().second.first;
		int curr_y = bfs_q.front().second.second;
		int curr_dir = bfs_q.front().first;
		bfs_q.pop();

		if (curr_x == row - 1 && curr_y == row - 1) {
			answer++;
			continue;
		} // 도착했으면 답에 추가

		if (curr_dir == 0) { // 가로
			if (check_wall(0, curr_x, curr_y))
				bfs_q.push({ 0, {curr_x, curr_y + 1} });
			if (check_wall(1, curr_x, curr_y))
				bfs_q.push({ 1, {curr_x + 1, curr_y + 1} });
		}
		if (curr_dir == 1) { // 대각선
			if (check_wall(0, curr_x, curr_y))
				bfs_q.push({ 0, {curr_x, curr_y + 1} });
			if (check_wall(1, curr_x, curr_y))
				bfs_q.push({ 1, {curr_x + 1, curr_y + 1} });
			if (check_wall(2, curr_x, curr_y))
				bfs_q.push({ 2, {curr_x + 1, curr_y} });
		}
		if (curr_dir == 2) { // 세로
			if (check_wall(2, curr_x, curr_y))
				bfs_q.push({ 2, {curr_x + 1, curr_y} });
			if (check_wall(1, curr_x, curr_y))
				bfs_q.push({ 1, {curr_x + 1, curr_y + 1} });
		}
	}
}

int main(){
	optimize();
	cin >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> house[i][j];

	bfs(0, 1);
	cout << answer;

	return 0;
}
