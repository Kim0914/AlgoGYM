#include <iostream>
#include <vector>
using namespace std;

int num = 0, answer = 0, dp[100001];
void init_dp() {
	for (int i = 0; i <= num; i++)
		dp[i] = i;
}

void calc_square() {
	for (int i = 1; i <= num; i++) // 숫자를 채워간다.
		for (int j = 1; j * j <= i; j++)
			// 제곱수가 i를 넘지 않는 선에서
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	// 현재 목표 수 - 제곱수를 한 것이 더 작을 경우 치환
	// +1을 하는 이유는? 해당 제곱수를 써야하기 때문
}

int main() {
	cin >> num;

	init_dp();
	calc_square();

	cout << dp[num];
	return 0;
}
