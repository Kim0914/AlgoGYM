#include <iostream>
#include <string>
using namespace std;

int row = 0, answer = INT32_MAX, whole_cost = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int garden[11][11];
bool flower_map[11][11];
// 11칸을 만드는 이유는?
// Out of bound를 따로 생각하지 않기 위해
bool check_overlap(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (flower_map[nx][ny])
			return false;
		// 5평 내에 이미 꽃이 심어져있으면 못 심는다.
	}

	return true;
}

void plant(int x, int y) {
	flower_map[x][y] = true;
	whole_cost += garden[x][y]; // 구입할 때 더해줌
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		whole_cost += garden[nx][ny];
		flower_map[nx][ny] = true;
		// 5평을 구매하도록 하자
	}
}

void pluck(int x, int y) {
	flower_map[x][y] = false;
	whole_cost -= garden[x][y];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		whole_cost -= garden[nx][ny];
		flower_map[nx][ny] = false;
		// 5평을 모두 제거한다
	}
}

void test_flower(int depth) {
	if (depth == 3) {
		answer = min(answer, whole_cost);
		return;
	}

	for (int i = 2; i < row; i++) {
		for (int j = 2; j < row; j++) {
			if (!flower_map[i][j] && check_overlap(i, j)) {
				plant(i, j); // 꽃을 심는다
				test_flower(depth + 1);
				pluck(i, j); // 계산이 끝났으면 꽃을 뽑아야 함
				// 일종의 백트래킹!
			}
		}
	}
}

int main(){
	cin >> row;

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= row; j++)
			cin >> garden[i][j];

	test_flower(0);
	cout << answer;
	return 0;
}
