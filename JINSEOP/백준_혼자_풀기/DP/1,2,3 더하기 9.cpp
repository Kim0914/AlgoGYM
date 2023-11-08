#include <iostream>
using namespace std;
#define ll long long
#define MOD 1000000009

int tc = 0, num = 0, digit = 0;
ll dp[1001][1001], dp_answer[1001][1001];
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init_dp() {
	dp[0][0] = 0;
	dp[1][1] = 1; // (1)
	dp[2][1] = 1; dp[2][2] = 1; // (2, 1+1)
	dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1; // (3, 1 + 2, 2 + 1, 1 + 1 + 1)

	for (int i = 4; i <= 1000; i++) {
		for (int j = 2; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % MOD;
			// dp[1][1] + dp[2][1] + dp[3][1], dp[1][2] + dp[2][2] + dp[3][2].. 이런식으로 감
			dp_answer[i][j] = (dp[i][j] + dp_answer[i][j - 1]) % MOD;
		}

		dp[i][i] = 1; // 1 + 1 + 1... + 1은 하나밖에 없음
		dp_answer[i][i] = (dp_answer[i][i - 1] + 1) % MOD;
	}
}

int main() {
	optimize();
	init_dp();

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num >> digit;
		cout << dp_answer[num][digit] % MOD << '\n';
	}

	return 0;
}
