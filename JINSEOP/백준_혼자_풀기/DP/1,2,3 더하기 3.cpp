#include <iostream>
using namespace std;
#define ll long long

int tc = 0, num = 0;
ll dp[1000010];
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init_dp() {
	dp[1] = 1; // 1은 1 한 가지
	dp[2] = 2; // 1+1, 2 두 가지
	dp[3] = 4; // 1+1+1, 1+2, 2+1, 3 네 가지
	// 여기부터 dp를 이용한다.
}

int main(){
	optimize();
	init_dp();

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num;

		for (int j = 4; j <= num; j++) {
			dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009;
		}

		cout << dp[num] % 1000000009 << '\n';
	}
	return 0;
}
