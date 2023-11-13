#include <iostream>
#include <cmath>
using namespace std;

int num = 0, row = 0, col = 0, sequence = 0;
void count_z_sequence(int x, int y, int limit) {
	// 그냥 쿼드트리를 풀 듯이 모든 배열을 체크하게 되면, 시간초과가 발생한다.
	// 32768 * 32768은 10억이 넘기 때문이다.
	if (x == row && y == col) {
		cout << sequence;
		return;
	}

	// 따라서 아래와 같이 해결하도록 하자.
	// 목표 좌표인 row와 col이 범위 내에 존재할 때만 다음 깊이로 탐색을 진행하자.
	if ((row >= x && row < x + limit) && (col >= y && col < y + limit)) {
		count_z_sequence(x, y, limit / 2);
		count_z_sequence(x, y + limit / 2, limit / 2);
		count_z_sequence(x + limit / 2, y, limit / 2);
		count_z_sequence(x + limit / 2, y + limit / 2, limit / 2);
	}
	// 목표 좌표인 row와 col이 범위 밖이라면, 현재 size만큼의 정사각형 넓이를
	// 더한 뒤, 다음 순서의 정사각형을 탐색하면 된다.
	else
		sequence += (limit * limit);
}

int main() {
	cin >> num >> row >> col;
	count_z_sequence(0, 0, pow(2, num));
	// 2^n승의 칸을 가진다.
	return 0;
}
