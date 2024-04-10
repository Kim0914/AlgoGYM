#include <iostream>
#include <queue>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define piic pair<pair<int, int>, char>

bool left_line[100001], right_line[100001], left_visit[100001], right_visit[100001];
int num = 0, coef = 0;
void init_lines() {
	for (int i = 0; i <= 100000; i++) {
		left_line[i] = 1;
		right_line[i] = 1;
	}
}

bool bfs() {
	queue<piic> bfs_q;
	bfs_q.push({ { 1, 1}, 'L' }); // 왼쪽 줄 1번 칸
	left_visit[1] = true;

	int prev_time = 1;
	while (!bfs_q.empty()) {
		int curr_cell = bfs_q.front().first.first;
		int curr_time = bfs_q.front().first.second;
		char curr_line = bfs_q.front().second;
		bfs_q.pop();

		if (curr_time >= num)
			break;
		if (curr_time == prev_time + 1) {
			left_line[prev_time] = 0;
			right_line[prev_time] = 0;
			prev_time++;
		}

		if (curr_line == 'L') {
			if (left_line[curr_cell + 1] && (curr_cell + 1 <= 100000)) {
				if (curr_cell + 1 > num)
					return true;

				bfs_q.push({ {curr_cell + 1, curr_time + 1}, 'L' });
				left_visit[curr_cell + 1] = true;
			}
			if (left_line[curr_cell - 1] && curr_cell >= 2 && !left_visit[curr_cell - 1] && (curr_cell - 1 != prev_time)) {
				bfs_q.push({ { curr_cell - 1, curr_time + 1}, 'L' });
				left_visit[curr_cell - 1] = true;
			}
			if (right_line[curr_cell + coef] && (curr_cell + coef <= 100000)) {
				if (curr_cell + coef > num)
					return true;

				bfs_q.push({ { curr_cell + coef, curr_time + 1}, 'R' });
				right_visit[curr_cell + coef] = true;
			}
		}
		else {
			if (right_line[curr_cell + 1] && (curr_cell + 1 <= 100000)) {
				if (curr_cell + 1 > num)
					return true;

				bfs_q.push({ {curr_cell + 1, curr_time + 1}, 'R' });
				right_visit[curr_cell + 1] = true;
			}
			if (right_line[curr_cell - 1] && curr_cell >= 2 && !right_visit[curr_cell - 1] && (curr_cell - 1 != prev_time)) {
				bfs_q.push({ {curr_cell - 1, curr_time + 1}, 'R' });
				right_visit[curr_cell - 1] = true;
			}
			if (left_line[curr_cell + coef] && (curr_cell + coef <= 100000)) {
				if (curr_cell + coef > num)
					return true;

				bfs_q.push({ {curr_cell + coef, curr_time + 1}, 'L' });
				left_visit[curr_cell + coef] = true;
			}
		}
	}

	return false;
}

int main() {
	OPTIMIZE;
	cin >> num >> coef;

	init_lines();
	string temp_l = "", temp_r = "";
	cin >> temp_l >> temp_r;
	for (int i = 1; i <= num; i++) {
		left_line[i] = temp_l[i - 1] - '0';
		right_line[i] = temp_r[i - 1] - '0';
	}

	bool can_clear = bfs();
	if (can_clear)
		cout << 1;
	else
		cout << 0;

	return 0;
}
