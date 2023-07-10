#include <iostream>
#include <vector>
using namespace std;

long long dp[101];
void init_dp() {
	for (int i = 0; i <= 5; i++)
		dp[i] = i;
}

int main() {
	int num = 0, buffer = 0;
	cin >> num;

	init_dp();
	for (int i = 6; i <= num; i++) {
		dp[i] = dp[i - 1] + 1; // A를 그냥 누르는 경우
		for (int j = 1; j < 4; j++)
			dp[i] = max(dp[i], dp[i - 2 - j] * (j + 1));
		// A를 그냥 누르는 경우와의 비교 대상은 다음과 같다.
		// 1. j = 1인 경우
		// dp[i - 3] * 2, 즉 Ctrl A Ctrl C Ctrl V를 하는 경우
		// 2. j = 2인 경우
		// dp[i - 4] * 3, 즉 Ctrl A Ctrl C Ctrl V Ctrl V를 하는 경우
		// 3. j = 3인 경우
		// dp[i - 5] * 4, 즉 Ctrl A Ctrl C Ctrl V Ctrl V Ctrl V를 하는 경우

		// 위의 경우 이상의 경우는 다시 복붙하는게 무조건 더 크다!
	}

	cout << dp[num];
	return 0;
}
