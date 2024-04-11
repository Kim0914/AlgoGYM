#include <iostream>
#include <queue>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define piic pair<pair<int, int>, char>

// 점프하려면 20만까지는 갈 수 있어야 함
bool lines[2][200001], line_visit[2][200001];
int num = 0, coef = 0;
void init_lines(){
	for (int i = 0; i < 2; i++)
		for (int j = 0; j <= 200000; j++)
			lines[i][j] = 1;
}

bool bfs() {
	queue<piic> bfs_q;
	bfs_q.push({ { 1, 1 }, 0 }); // 0 : 왼쪽 줄, 1 : 오른쪽 줄
	line_visit[1][1] = true;

	while (!bfs_q.empty()) {
		int curr_cell = bfs_q.front().first.first;
		int curr_time = bfs_q.front().first.second;
		int curr_line = bfs_q.front().second;
		bfs_q.pop();

		if (curr_cell >= num)
			return true;

		if (lines[curr_line][curr_cell + 1] && !line_visit[curr_line][curr_cell + 1]) {
			bfs_q.push({ {curr_cell + 1, curr_time + 1}, curr_line });
			line_visit[curr_line][curr_cell + 1] = true;
		}
		if (lines[curr_line][curr_cell - 1] && !line_visit[curr_line][curr_cell - 1] && (curr_cell - 1) > curr_time) {
			// 시간에 대한 제한이 들어가는 것은, 발판이 사라지기 때문 
			bfs_q.push({ { curr_cell - 1, curr_time + 1}, curr_line });
			line_visit[curr_line][curr_cell - 1] = true;
		}
		if (curr_line == 0) { // 왼쪽
			if (lines[1][curr_cell + coef] && !line_visit[1][curr_cell + coef]) {
				bfs_q.push({ { curr_cell + coef, curr_time + 1}, 1 });
				line_visit[1][curr_cell + coef] = true;
			}
		}
		if (curr_line == 1) { // 오른쪽
			if (lines[0][curr_cell + coef] && !line_visit[0][curr_cell + coef]) {
				bfs_q.push({ { curr_cell + coef, curr_time + 1}, 0 });
				line_visit[0][curr_cell + coef] = true;
			}
		}
	}

	return false;
}

int main() {
	OPTIMIZE;
	init_lines();
	cin >> num >> coef;

	string temp_l = "", temp_r = "";
	cin >> temp_l >> temp_r;
	for (int i = 1; i <= num; i++) {
		lines[0][i] = temp_l[i - 1] - '0';
		lines[1][i] = temp_r[i - 1] - '0';
	}

	bool can_clear = bfs();
	if (can_clear)
		cout << 1;
	else
		cout << 0;

	return 0;
}
