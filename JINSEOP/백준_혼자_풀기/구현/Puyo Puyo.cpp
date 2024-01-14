#include <iostream>
#include <queue>
using namespace std;

char puyo_board[12][6];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[12][6];
vector<pair<int, int>> destroyed_pos, temp_pos;
void clear_visit() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visit[i][j] = false;
}

int puyo_bfs(int st_x, int st_y) {
	int cnt = 1;
	queue<pair<int, int>> bfs_q;
	bfs_q.push({st_x, st_y});
	temp_pos.push_back({ st_x, st_y });
	// 지워야 할 뿌요의 좌표를 저장하도록 한다.
	visit[st_x][st_y] = true;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < 12) && (ny >= 0 && ny < 6)) {
				if (!visit[nx][ny] && puyo_board[nx][ny] == puyo_board[curr_x][curr_y]) {
					bfs_q.push({ nx, ny });
					visit[nx][ny] = true;
					cnt++;
					temp_pos.push_back({ nx, ny });
				}
			}
		}
	}

	return cnt;
}

void start_game() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> puyo_board[i][j];
}

void pull_down_puyo() {
	// 공중에 떠있는 뿌요를 아래로 내리는 작업
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (puyo_board[i][j] != '.') {
				int curr_idx = i;
				// i, j에서 뿌요를 찾았는데 공중에 떠있다면?

				while (true) {
					if (curr_idx == 11 || puyo_board[curr_idx + 1][j] != '.')
						break;

					puyo_board[curr_idx + 1][j] = puyo_board[curr_idx][j];
					puyo_board[curr_idx][j] = '.';
					curr_idx++;
					// 제일 아래까지 내려야함
				}
			}
		}
	}
}

int main() {
	int answer = 0;

	start_game();
	// 우선 첫 상태를 입력 받자.
	while (true) {
		bool is_destroyed = false;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (puyo_board[i][j] != '.' && !visit[i][j]) {
					if (puyo_bfs(i, j) >= 4) {
						is_destroyed = true;
						for (int i = 0; i < temp_pos.size(); i++)
							destroyed_pos.push_back(temp_pos[i]);
						// 4개 이상이면, 진짜 지울 좌표에 등록
					}
				}

				temp_pos.clear();
			}
		}

		for (int i = 0; i < destroyed_pos.size(); i++)
			puyo_board[destroyed_pos[i].first][destroyed_pos[i].second] = '.';
		// 4개 이상이 모인 좌표는 확실하게 맵에서 제거
		destroyed_pos.clear();

		pull_down_puyo();
		// 여기는 제거된 좌표에 대해 뿌요를 아래로 내려주는 작업

		if (is_destroyed) {
		// 한 번이라도 제거되었으면 반복
			clear_visit();
			answer++;
		}
		else
			break;
		// 모든 연쇄가 터질 때 까지 게임 진행
	}

	cout << answer;
	return 0;
}
