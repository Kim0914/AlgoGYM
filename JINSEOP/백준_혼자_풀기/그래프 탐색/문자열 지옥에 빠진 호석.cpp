#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> hash_counter;
int row = 0, col = 0, num = 0, max_size = 0;
char game_board[10][10];
vector<string> gods_saying;
string target_str = "";
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void dfs(int depth, int curr_x, int curr_y, string curr_str) {
	// 8방향 dfs를 돌려보자
	if (depth == max_size) {
		hash_counter[curr_str]++;
		return;
	}

	for (int i = 0; i < 8; i++) {
		int nx = (curr_x + dx[i]) % row;
		int ny = (curr_y + dy[i]) % col;

		if (nx < 0)
			nx += row;
		if (ny < 0)
			ny += col;

		string nx_str = curr_str + game_board[nx][ny];
		dfs(depth + 1, nx, ny, nx_str);
	}
}

int main() {
	optimize();
	cin >> row >> col >> num;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> game_board[i][j];

	for (int i = 0; i < num; i++) {
		cin >> target_str;
		int size = target_str.size();
		max_size = max(size, max_size);

		hash_counter[target_str] = 0;
		gods_saying.push_back(target_str);
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			string init_str = "";
			init_str += game_board[i][j];

			dfs(1, i, j, init_str);
		}
	}

	for (int i = 0; i < gods_saying.size(); i++)
		cout << hash_counter[gods_saying[i]] << '\n';

	return 0;
}
