#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321
#define MINF -987654321

int row = 0, max_v = MINF, min_v = INF;
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };
char map[5][5];
bool visit[5][5];
void backtrack(int curr_x, int curr_y, int sum, char oper){
	if (curr_x == row - 1 && curr_y == row - 1) {
		max_v = max(max_v, sum);
		min_v = min(min_v, sum);
		return;
	}

	for (int i = 0; i < 2; i++) {
		int nx = curr_x + dx[i];
		int ny = curr_y + dy[i];

		if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row)) {
			if (!visit[nx][ny]) {
				visit[nx][ny] = true;

				if (map[nx][ny] >= '0' && map[nx][ny] <= '9') {
					if (oper == '+')
						backtrack(nx, ny, sum + (map[nx][ny] - '0'), 'X');
					if (oper == '-')
						backtrack(nx, ny, sum - (map[nx][ny] - '0'), 'X');
					if (oper == '*')
						backtrack(nx, ny, sum * (map[nx][ny] - '0'), 'X');
				}
				else
					backtrack(nx, ny, sum, map[nx][ny]);

				visit[nx][ny] = false;
			}
		}
	}
}

int main() {
	cin >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> map[i][j];

	visit[0][0] = true;
	backtrack(0, 0, map[0][0] - '0', 'X');
	cout << max_v << " " << min_v;

	return 0;
}
