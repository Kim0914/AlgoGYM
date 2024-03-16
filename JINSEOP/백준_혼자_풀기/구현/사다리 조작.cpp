#include <iostream>
using namespace std;
#define MAX 99999999

int vert = 0, hori = 0, put_point = 0, x = 0, y = 0, answer = MAX;
bool ladder_map[31][11];
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool check_ladder() {
	for (int i = 1; i <= vert; i++) {
	// i는 현재 내려보내는 번호
		int curr_vert = i;
		for (int j = 1; j <= hori; j++) {
			if (ladder_map[j][curr_vert])
				curr_vert++; // 내려가다 가로선을 만나는 경우
			else if (ladder_map[j][curr_vert - 1])
				curr_vert--; // 내려가다 가로선을 만나는 경우
			// 반대로 가는 선은 현재 (세로선 - 1)의 값을 가진다.
		}

		if (curr_vert != i)
			return false;
	}

	return true;
}

void backtrack(int idx, int depth) {
	if (depth == 4)
		return;

	if (check_ladder()) {
		answer = min(answer, depth);
		return;
	}

	for (int i = idx; i < vert; i++) {
		// 어차피 마지막 세로선은 사다리를 설치할 수 없다.
		// ㅣ->ㅣ 방향으로 밖에 설치 못함
		for (int j = 1; j <= hori; j++) {
			if (ladder_map[j][i])
				continue; // 이미 선이 놓인 곳
			if (ladder_map[j][i - 1] || ladder_map[j][i - 1])
				continue; // 선은 연속할 수 없다.

			ladder_map[j][i] = true;
			backtrack(i, depth + 1);
			ladder_map[j][i] = false;
		}
	}
}

int main() {
	optimize();
	cin >> vert >> put_point >> hori;
	for (int i = 0; i < put_point; i++) {
		cin >> x >> y;
		ladder_map[x][y] = true;
		// x번 가로선에서 y와 y + 1을 연결했다는 의미이다.
	}

	if (put_point == 0)
		cout << 0;
	else {
	// 로직 구현
		backtrack(0, 0);
		if (answer == MAX)
			cout << -1;
		else
			cout << answer;
	}

	return 0;
}
