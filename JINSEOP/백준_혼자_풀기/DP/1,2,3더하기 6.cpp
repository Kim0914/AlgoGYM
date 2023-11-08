#include <iostream>
using namespace std;
#define ll long long

int tc = 0, num = 0;
ll dp[100001];
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init_dp() {
	dp[0] = 0; dp[1] = 1; dp[2] = 2; // (2, 1+1)
	dp[3] = 2;// (3, 1+1+1)
	dp[4] = 3;// (1..1, 1+2+1, 2+2)
	dp[5] = 3;
	dp[6] = 6;
}

int main(){
	optimize();
	init_dp();

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num;

		for (int j = 7; j <= num; j++)
			// 대칭이라 함은, 양 옆에 1 1 2 2 3 3만 붙이면 된다.
			dp[j] = (dp[j - 2] + dp[j - 4] + dp[j - 6]) % 1000000009;

		cout << dp[num] % 1000000009 << '\n';
	}

	return 0;
}
