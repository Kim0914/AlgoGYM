#include <iostream>
#include <vector>
using namespace std;

long long dp[10001];
void clear_dp(int num) {
	for (int i = 1; i <= num; i++)
		dp[i] = 0;
}

int main() {
	int test_case = 0, prev_case = 0, num = 0;
	cin >> test_case;

	dp[0] = 1;
	for (int i = 0; i < test_case; i++) {
		cin >> num;
		
		for (int i = 1; i <= 3; i++) {
			for (int j = i; j <= num; j++) {
				dp[j] += dp[j - i];
			}
		}

		cout << dp[num] << '\n';
		clear_dp(num);
	}

	return 0;
}
