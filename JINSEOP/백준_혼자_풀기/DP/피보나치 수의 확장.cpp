#include <iostream>
using namespace std;
#define MOD 1000000000

int dp[1000001], m_dp[1000001], num = 0;
void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init_dp() {
	dp[0] = 0;
	dp[1] = 1;
	m_dp[0] = 0;
	m_dp[1] = 1; // 얘가 -1
}

int main() {
	optimize();
	cin >> num;

	init_dp();
	if (num == 0) {
		cout << 0 << '\n';
		cout << dp[0];
	}
	else if (num > 0) {
		for (int i = 2; i <= num; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

		cout << 1 << '\n';
		cout << dp[num] % MOD;
	}
	else {
		num = abs(num);
		for (int i = 2; i <= num; i++)
			m_dp[i] = (m_dp[i - 2] - m_dp[i - 1]) % MOD;

		if (m_dp[num] > 0) {
			cout << 1 << '\n';
			cout << m_dp[num] % MOD;
		}
		else if (m_dp[num] == 0) {
			cout << 0 << '\n';
			cout << m_dp[num] % MOD;
		}
		else if (m_dp[num] < 0) {
			cout << -1 << '\n';
			cout << abs(m_dp[num]) % MOD;
		}
	}

	return 0;
}
