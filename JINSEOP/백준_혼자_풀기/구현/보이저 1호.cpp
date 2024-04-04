#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define pii pair<int, int>

int row = 0, col = 0, max_dist = 0, max_dir = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {0, 1, 0, -1};
char galaxy[501][501];
bool check_cycle[501][501][4];
unordered_map<int, char> direction_map;
pii probe;
void init_map() {
	direction_map[0] = 'U';
	direction_map[1] = 'R';
	direction_map[2] = 'D';
	direction_map[3] = 'L';
}

void clear_check() {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			for(int k = 0; k < 4; k++)
				check_cycle[i][j][k] = false;
}

int change_direction(int curr_dir, int curr_x, int curr_y) {
	char curr_state = galaxy[curr_x][curr_y];
	if (galaxy[curr_x][curr_y] == '.')
		return curr_dir;

	if (galaxy[curr_x][curr_y] == '/') {
		if (curr_dir == 0)
			return 1;
		if (curr_dir == 1)
			return 0;
		if (curr_dir == 2)
			return 3;
		if (curr_dir == 3)
			return 2;
	}
	if (galaxy[curr_x][curr_y] == '\\') {
		if (curr_dir == 0)
			return 3;
		if (curr_dir == 1)
			return 2;
		if (curr_dir == 2)
			return 1;
		if (curr_dir == 3)
			return 0;
	}
}

void dfs(int start_dir, int curr_dir, int curr_x, int curr_y, int dist) {
	if (check_cycle[curr_x][curr_y][curr_dir]) {
		cout << direction_map[start_dir] << '\n';
		cout << "Voyager";
		exit(0);
	}
	
	// cout << curr_dir << " " << curr_x << " " << curr_y << " " << galaxy[curr_x][curr_y] << '\n';
	check_cycle[curr_x][curr_y][curr_dir] = true;
	int n_dir = change_direction(curr_dir, curr_x, curr_y);
	int nx = curr_x + dx[n_dir];
	int ny = curr_y + dy[n_dir];

	if (nx <= 0 || nx > row || ny <= 0 || ny > col) {
		if (max_dist < dist) {
			max_dist = dist;
			max_dir = start_dir;
		}

		return;
	}
	if (galaxy[nx][ny] == 'C') {
		if (max_dist < dist) {
			max_dist = dist;
			max_dir = start_dir;
		}

		return;
	}

	dfs(start_dir, n_dir, nx, ny, dist + 1);
}

int main(){
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			cin >> galaxy[i][j];

	cin >> probe.first >> probe.second;
	// 탐사선 위치

	init_map();
	for (int i = 0; i < 4; i++) {
		dfs(i, i, probe.first, probe.second, 0);
		clear_check();
	}

	cout << direction_map[max_dir] << '\n' << max_dist + 1;
	return 0;
}
