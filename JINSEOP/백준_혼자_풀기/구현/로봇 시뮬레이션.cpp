#include <iostream>
#include <vector>
using namespace std;
#define piii pair<pair<int, int>, int>

int row = 0, col = 0, robot_num = 0, cmd_num = 0, x = 0, y = 0, reps = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char dir = 'X', cmd = 'X';
piii robot[101];
int p_map[101][101];
int char_to_dir(char target) {
	if (target == 'N')
		return 0;
	if (target == 'E')
		return 1;
	if (target == 'S')
		return 2;
	if (target == 'W')
		return 3;
}

int main() {
	cin >> row >> col;
	cin >> robot_num >> cmd_num;

	for (int i = 1; i <= robot_num; i++) {
		cin >> x >> y >> dir;
		robot[i] = { {y, x}, char_to_dir(dir) };
		p_map[y][x] = i;
	}

	while (cmd_num--) {
		cin >> robot_num >> cmd >> reps;
		
		while (reps--) {
			if (cmd == 'L')
				robot[robot_num].second = (robot[robot_num].second + 3) % 4;
			if (cmd == 'R')
				robot[robot_num].second = (robot[robot_num].second + 1) % 4;
			if (cmd == 'F') {
				int curr_x = robot[robot_num].first.first;
				int curr_y = robot[robot_num].first.second;
				int nx = curr_x + dx[robot[robot_num].second];
				int ny = curr_y + dy[robot[robot_num].second];

				if (nx <= 0 || ny <= 0 || nx > col || ny > row) {
					cout << "Robot " << robot_num << " crashes into the wall";
					return 0;
				}

				if (p_map[nx][ny]) {
					cout << "Robot " << robot_num << " crashes into robot " << p_map[nx][ny];
					return 0;
				}

				p_map[curr_x][curr_y] = 0;
				p_map[nx][ny] = robot_num;
				robot[robot_num].first.first = nx;
				robot[robot_num].first.second = ny;
			}
		}
	}

	cout << "OK" << '\n';
	return 0;
}
