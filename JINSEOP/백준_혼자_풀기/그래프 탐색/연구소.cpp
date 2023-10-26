#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row = 0, col = 0, answer = 0, safe_area = 0;
int safe_map[8][8], copied_map[8][8];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> virus_pos;
void copy_map() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			copied_map[i][j] = safe_map[i][j];
}

void spread_virus(int x, int y) {
	queue<pair<int, int>> bfs_q;
	bfs_q.push({ x, y });

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (copied_map[nx][ny] == 0) {
					copied_map[nx][ny] = 2;
					bfs_q.push({ nx, ny });
				}
			}
		}
	}
}

int calculate_area() {
	int partial_area = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (copied_map[i][j] == 0)
				partial_area++;

	return partial_area;
}

void set_barricade(int barri_count) {
	if (barri_count == 3) {
		copy_map(); // 맵을 복사해서 가상의 맵에서 바이러스를 퍼트리자
		for (int i = 0; i < virus_pos.size(); i++)
			spread_virus(virus_pos[i].first, virus_pos[i].second);
		// 바이러스 퍼트림
		safe_area = calculate_area(); // 안전 영역 계산
		answer = max(answer, safe_area);
		return;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (safe_map[i][j] == 0) {
				safe_map[i][j] = 1; // 벽 설치
				set_barricade(barri_count + 1);
				safe_map[i][j] = 0; // 설치했던 벽 제거
			}
		}
	}

}

int main(){
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> safe_map[i][j];
			if (safe_map[i][j] == 2)
				virus_pos.push_back({ i, j });
		}
	}

	set_barricade(0);
	cout << answer;

	return 0;
}
