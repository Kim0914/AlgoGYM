#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; // 8방향
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int row = 0, col = 0, result = 0;
vector<pair<int, int>> blank_pair;
void clear_visit(vector<vector<bool>>& visit) {
	for (int i = 0; i < visit.size(); i++) {
		for (int j = 0; j < visit[0].size(); j++) {
			visit[i][j] = false;
		}
	}

}

int bfs(int st_x, int st_y, vector<vector<bool>>& visit, vector<vector<int>> space_map) { // 8방향 bfs
	queue<pair<int, pair<int, int>>> bfs_q; // Queue를 매 회 비워주어야 함
	bfs_q.push({ 0, { st_x, st_y } });
	visit[st_x][st_y] = true;

	while (!bfs_q.empty()) {
		int curr_dist = bfs_q.front().first;
		int curr_x = bfs_q.front().second.first;
		int curr_y = bfs_q.front().second.second;
		bfs_q.pop();

		if (space_map[curr_x][curr_y] == 1) // 상어를 만나면
			return curr_dist;

		for (int i = 0; i < 8; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (!visit[nx][ny]) {
					bfs_q.push({ curr_dist + 1, { nx, ny } });
					visit[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> row >> col;
	vector<vector<int>> space_map(row, vector<int>(col, 0));
	vector<vector<bool>> visit(row, vector<bool>(col, false));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> space_map[i][j];
			if (space_map[i][j] == 0)
				blank_pair.push_back({ i, j }); // 빈 칸을 저장해서 BFS를 돌리자
		}
	}

	for (int i = 0; i < blank_pair.size(); i++) {
		int dist = bfs(blank_pair[i].first, blank_pair[i].second, visit, space_map);
		result = max(result, dist);

		clear_visit(visit); 
		// 매번 visit 배열을 비워 주어야 매 칸 거리 계산이 가능하다.
	}

	cout << result;
	// 상어를 기준으로 탐색해보려 했지만 실패
	return 0;
}
