#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int tc = 0, num = 0, target = 0;
int coins[21], dp[10001];
void clear_dp() {
	for (int i = 0; i <= target; i++)
			dp[i] = 0;
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> num;

		for (int i = 1; i <= num; i++)
			cin >> coins[i];
		cin >> target;
		// DP 배열을 채우는 방법?

		dp[0] = 1;
		for (int i = 1; i <= num; i++) {
			for (int j = coins[i]; j <= target; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}

		cout << dp[target] << '\n';
		clear_dp();
	}
}
