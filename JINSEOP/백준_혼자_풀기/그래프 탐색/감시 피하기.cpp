#include <iostream>
#include <vector>
using namespace std;

int row = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char hallway[6][6];
vector<pair<int, int>> teachers;
bool visit[6][6];
bool stare_student(int curr_x, int curr_y) {
	// 선생님 현재 자리에서 4방향으로 쭉 진행
	for (int i = 1; i < (row - curr_y); i++) {
		if (hallway[curr_x][curr_y + i] == 'S')
			return false;
		if (hallway[curr_x][curr_y + i] == 'O')
			break;
	} // 오른쪽
	for (int i = 1; i <= curr_y; i++) {
		if (hallway[curr_x][curr_y - i] == 'S')
			return false;
		if (hallway[curr_x][curr_y - i] == 'O')
			break;
	} // 왼쪽
	for (int i = 1; i <= curr_x; i++) {
		if (hallway[curr_x - i][curr_y] == 'S')
			return false;
		if (hallway[curr_x - i][curr_y] == 'O')
			break;
	} // 위쪽
	for (int i = 1; i < (row - curr_x); i++) {
		if (hallway[curr_x + i][curr_y] == 'S')
			return false;
		if (hallway[curr_x + i][curr_y] == 'O')
			break;
	} // 아래쪽

	return true;
}

void install_object(int depth) {
	if (depth == 3) {
	// 장애물 3개를 설치했으면, 학생들이 모두 가려지는 지 확인
		int true_cnt = 0;
		for (int i = 0; i < teachers.size(); i++) {
			if (!stare_student(teachers[i].first, teachers[i].second))
				break;
			else
				true_cnt++;
		}

		if (true_cnt == teachers.size()) {
			cout << "YES";
			exit(0);
		}

		return;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (hallway[i][j] == 'X') {
				hallway[i][j] = 'O';
				install_object(depth + 1);
				hallway[i][j] = 'X';
			}
		}
	}
}

int main() {
	cin >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			cin >> hallway[i][j];
			if(hallway[i][j] == 'T')
				teachers.push_back({ i, j });
		}
	}

	install_object(0);
	cout << "NO";
	return 0;
}
