#include <iostream>
#include <queue>
using namespace std;

int row = 0, col = 0, joo_pos_x = 0, joo_pos_y = 0, choco_pos_x = 0, choco_pos_y = 0, answer = 0;
int dx[4] = {-1, 0, 1, 0}; // 상 우 하 좌
int dy[4] = {0, 1, 0, -1};
vector<string> classroom;
bool visit[301][301], student_status[301][301];

void clear_visit() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visit[i][j] = false;
			if (student_status[i][j] == true)
				classroom[i][j] = '0';
		}
	}
}

bool boolean_bfs() { // 조금 특이한 형태의 bfs를 만들어야 할 것 같다.
	queue<pair<int, int>> bfs_q;
	bfs_q.push({ joo_pos_x, joo_pos_y });
	visit[joo_pos_x][joo_pos_y] = true;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if (nx == choco_pos_x && ny == choco_pos_y) {
				classroom[nx][ny] = 'X';
				return false; // 초코바를 찾았으면 전체 중지
			}

			if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
				if (!visit[nx][ny]) {
					if (classroom[nx][ny] == '1') // 친구가 서있으면?
						student_status[nx][ny] = true; // 친구를 제거하고 해당 방향 진행 X
					// 여기서 먼저 0으로 바꿔버리면, 다른 방향에서 올 때 진행되어 버림
					else { // 친구가 없는 자리면?
						bfs_q.push({ nx, ny }); // 해당 방향으로 계속 진행
						visit[nx][ny] = true;
					}
				}
			}
		}
	}

	return true;
}

int main() {
	cin >> row >> col; // 교실의 크기
	cin >> joo_pos_x >> joo_pos_y >> choco_pos_x >> choco_pos_y;
	// 주난이의 위치, 범인의 위치
	joo_pos_x -= 1; joo_pos_y -= 1; choco_pos_x -= 1; choco_pos_y -= 1;
	// 문제는 (1,1) 시작이기 때문에 1 씩 빼주어야 한다.
	for (int i = 0; i < row; i++) {
		string temp;
		cin >> temp;
		classroom.push_back(temp); // 교실의 형태
	}

	while (true) {
		bool stop_flag = boolean_bfs();
		answer++; // 몇 번 점프하는지?
		clear_visit(); // 초기화해야 한다

		if (!stop_flag)
			break;
	}

	cout << answer;

	return 0;
}
