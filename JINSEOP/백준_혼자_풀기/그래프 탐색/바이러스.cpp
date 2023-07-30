#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
void dfs(int idx, vector<vector<int>> computer_map, vector<bool> &visit) {
	visit[idx] = true;
	cnt++;

	for (int i = 1; i < computer_map[1].size(); i++) {
		if (!visit[i] && computer_map[idx][i]) {
			dfs(i, computer_map, visit);
		}
	}
}

int main() {
	int vertex = 0, edge = 0, pc_x = 0, pc_y = 0;
	cin >> vertex >> edge;

	vector<vector<int>> computer_map(vertex + 1, vector<int>(vertex + 1, 0));
	vector<bool> visit(vertex + 1, false);

	for (int i = 0; i < edge; i++) {
		cin >> pc_x >> pc_y;
		computer_map[pc_x][pc_y] = 1;
		computer_map[pc_y][pc_x] = 1;
		// 인접 행렬로 구현
	}


	dfs(1, computer_map, visit);
	cout << cnt - 1;

	return 0;
}
