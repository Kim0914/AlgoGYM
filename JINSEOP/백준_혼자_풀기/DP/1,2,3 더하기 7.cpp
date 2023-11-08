#include <iostream>
using namespace std;
#define ll long long
#define MOD 1000000009

int tc = 0, num = 0, digit = 0;
ll dp[1001][1001];
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

	for (int j = 4; j <= 1000; j++) {
		for (int k = 2; k < j; k++)
			dp[j][k] = (dp[j - 1][k - 1] + dp[j - 2][k - 1] + dp[j - 3][k - 1]) % MOD;
		// dp[1][1] + dp[2][1] + dp[3][1], dp[1][2] + dp[2][2] + dp[3][2].. 이런식으로 감

		dp[j][j] = 1; // 1 + 1 + 1... + 1은 하나밖에 없음
	}
}

int main(){
	optimize();
	init_dp();

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num >> digit;
		cout << (dp[num][digit]) % MOD << '\n';
	}

	return 0;
}
