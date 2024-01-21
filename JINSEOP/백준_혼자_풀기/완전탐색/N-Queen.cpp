#include <iostream>
#include <vector>
using namespace std;

int row = 0, answer = 0;
int queen_visit[16];
vector<int> test;
bool validate(int curr_depth, int curr_pos) {
	// 현재 행에서 퀸을 놓을 수 있는 공간은 어디인가?
	// 1. 자신의 위에 퀸이 없는 경우
	if (queen_visit[curr_pos] != 0)
		return false;

	// 2. 자신의 대각선 방향에 퀸이 없는 경우
	for (int i = 1; i <= row; i++)
		if(queen_visit[i] != 0)
			if (abs(queen_visit[i] - curr_depth) == abs(curr_pos - i))
	// 체크 배열에 0이 아닌 값이 등장했다!
	// 해당 위치와 현재 위치를 비교하고, 해당 깊이와 현재 깊이를 비교
	// 두 값이 동일하면 대각선 상에 위치하므로 놓을 수 없다.
				return false;

	// 3. 같은 행에는 어차피 절대 못놓음
	// 이 부분은 다음 depth로 바로 넘기면 해결
	return true;
}

void backtrack(int depth) {
	if (depth == row + 1) {
		answer++;
		return;
	}

	for (int i = 1; i <= row; i++) {
		// 여기서 퀸을 어떻게 놓을 지 검사하는게 중요하다.
		if (validate(depth, i)) {
			test.push_back(i);
			queen_visit[i] = depth;
			backtrack(depth + 1);
			queen_visit[i] = 0;
			test.pop_back();
		}
	}
}

int main() {
	cin >> row;

	backtrack(1);
	cout << answer;
	return 0;
}
