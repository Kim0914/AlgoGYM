#include <iostream>
#include <vector>
using namespace std;

int days = 0, rice_cake = 0;
int dp[31];
void top_down_dp() {
	for (int i = rice_cake - 1; i > rice_cake / 2; i--) {
		dp[days - 1] = i;

		//cout << '\n';
		//cout << dp[days - 1] << " ";
		for (int j = days - 2; j >= 1; j--) {
			dp[j] = dp[j + 2] - dp[j + 1];

			//cout << dp[j] << " ";
			if (dp[j] <= 0 || dp[j + 1] <= dp[j])
				break;

			if (j == 1)
				return;
		}
	}
}

int main() {
	cin >> days >> rice_cake;
	// 피보나치 수와 유사하다.

	dp[days] = rice_cake;
	// 하지만? Top-down식 DP가 필요할 듯
	// 두 수를 더했을 때, target이 나오도록
	// 처음 두 수가 정해지면? 뒤에는 모두 정해짐
	top_down_dp();
	cout << dp[1] << '\n' << dp[2];
	return 0;
}
