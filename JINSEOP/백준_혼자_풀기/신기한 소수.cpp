#include <iostream>
#include <vector>
using namespace std;

bool validate_prime(int target) {

	for (int i = 2; i * i <= target; i++) {
		if (target % i == 0)
			return false; // 기본적인 소수 판별 알고리즘
	} // 에라토스테네스의 체 보다 여기서는 이게 더 빠름

	return true;
}

void dfs(int num, int length, int limit) {
	if (length == limit) {
		cout << num << "\n";
		return;
	} // 원하는 길이의 수만 출력

	for (int i = 0; i <= 9; i++) {
		int next_num = (num * 10) + i;

		if (validate_prime(next_num))
			dfs(next_num, length + 1, limit);
		// DFS를 통해서 수를 확인하며 넘어갈 수 있다.
		// 좀 더 연습해야될듯
	}
}

int main() {
	int length = 0;
	cin >> length;

	dfs(2, 1, length);
	dfs(3, 1, length);
	dfs(5, 1, length);
	dfs(7, 1, length);

	return 0;
}
