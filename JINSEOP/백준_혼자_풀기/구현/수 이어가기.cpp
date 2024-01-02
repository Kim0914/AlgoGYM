#include <iostream>
using namespace std;

int num = 0, answer = 0, answer_digit = 0;
int dp[10000];
void clear_dp(int len) {
	for (int i = 1; i <= len; i++)
		dp[i] = 0;
}

int main() {
	cin >> num;
	dp[0] = num;

	for (int i = num; i > (num / 2); i--) {
		// num의 절반부터는 0보다 작아지므로, 검사 필요 X
		int iter = 2;
		dp[1] = i;

		while (true) {
			dp[iter] = dp[iter - 2] - dp[iter - 1];
			if (dp[iter] < 0)
				break;

			iter++;
		}
		
		if (answer < iter) {
			answer_digit = i;
			answer = iter;
		}

		clear_dp(iter);
	}

	cout << answer << '\n';
	dp[1] = answer_digit;

	cout << dp[0] << " " << dp[1] << " ";
	int iter = 2;
	while (true) {
		dp[iter] = dp[iter - 2] - dp[iter - 1];

		if (dp[iter] < 0)
			break;

		cout << dp[iter] << " ";
		iter++;
	}

	return 0;
}
