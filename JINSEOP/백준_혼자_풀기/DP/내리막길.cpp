#include <iostream>
using namespace std;

int row = 0, col = 0, downhill[500][500][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dfs(int curr_x, int curr_y) {
	// 시작지점은 1로 표기

	if (curr_x == row - 1 && curr_y == col - 1)
		return 1; // 도착했다면, 한 가지 방법이 늘어난 것
	if (downhill[curr_x][curr_y][1] != -1)
		return downhill[curr_x][curr_y][1];
	// 해당 위치의 값이 -1이 아니라는 것은 이미 탐색한 위치!
	// 이미 탐색한 위치에서 몇 가지의 경로가 존재하는지 반환한다.

	downhill[curr_x][curr_y][1] = 0;
	// 기본적으로 탐색할 때, 시작은 0가지.

	for (int i = 0; i < 4; i++) {
		int nx = curr_x + dx[i];
		int ny = curr_y + dy[i];

		if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col))
			if (downhill[nx][ny][0] < downhill[curr_x][curr_y][0])
				downhill[curr_x][curr_y][1] = downhill[curr_x][curr_y][1] + dfs(nx, ny);
		// 이 부분에서 Memoization이 동작하게 된다.
	}

	return downhill[curr_x][curr_y][1];
	// 탐색을 마쳤다면 해당 위치에서의 가짓수를 반환한다.
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> downhill[i][j][0];
			downhill[i][j][1] = -1;
			// dp 배열은 -1로 초기화 한다.
			// 왜? 갈 수 있는 경로의 가짓수는 최소가 0이기 때문이다.
		}
	}

	cout << dfs(0, 0);

	return 0;
}
