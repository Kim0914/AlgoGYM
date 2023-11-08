#include <iostream>
using namespace std;
#define ll long long
#define MOD 1000000009

int tc = 0, num = 0, digit = 0;
ll dp[100001][2];
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init_dp() {
	dp[0][0] = 0;
	dp[1][1] = 1; // (1)
	dp[2][0] = 1; dp[2][1] = 1; // (2, 1+1)
	dp[3][0] = 2; dp[3][1] = 2; // (3, 1 + 2, 2 + 1, 1 + 1 + 1)
	dp[4][0] = 3; dp[4][1] = 3; // 짝 : 3 + 1, 1 * 4, 1 + 3, 2 + 2 => 2 + 1 + 1
								// 홀 : 1 + 2 + 1, 2 + 1 + 1, 1 + 1 + 2 => 2 + 1
	// 0: 짝수, 1: 홀수를 따로 저장하자
	// 이후에 DP 계산 시, 짝수 -> 홀수 / 홀수 -> 짝수로 더해주면 됨

	for (int i = 4; i <= 100000; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % MOD;  // 홀수끼리
		dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % MOD; // 짝수끼리
	}
}

int main(){
	optimize();
	init_dp();

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num;
		cout << (dp[num][1]) % MOD << " " << (dp[num][0]) % MOD << '\n';
	}

	return 0;
}
