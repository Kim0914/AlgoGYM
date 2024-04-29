#include <iostream>
#include <vector>
using namespace std;

int tc = 0, dp[21][10001];
vector<int> coins;
void clear_dp(int goal) {
	for (int i = 0; i < coins.size(); i++)
		for (int j = 0; j <= goal; j++)
			dp[i][j] = 0;
}

int main() {
	cin >> tc;

	while (tc--) {
		int kinds = 0;
		cin >> kinds;

		int each_coin = 0;
		coins.push_back(0);
		for (int i = 0; i < kinds; i++) {
			cin >> each_coin;
			coins.push_back(each_coin);
			dp[i + 1][each_coin]++; // 여기서 미리 1로 표시를 하는게 핵심!!!
		}
		
		int goal = 0;
		cin >> goal; // 입력 끝

		for (int i = 1; i < coins.size(); i++) {
			for (int j = 1; j <= goal; j++) {
				if (j - coins[i] < 0) {
					dp[i][j] = dp[i-1][j];
					continue;
				} // 이 과정이 왜 반드시 필요한 지?
        // 이 과정이 있어야 예를 들어, 5 + 1이나 5 + 3같은 경우를 만들 수 있음
        // coins[i] 부터 시작하면, 5 + 1에서 1이 0일 것이고 5 + 3에서 3도 0일 것임
				dp[i][j] += (dp[i-1][j] + dp[i][j - coins[i]]);
			}
		}

		cout << dp[kinds][goal] << '\n';
		clear_dp(goal);
		coins.clear();
	}

	return 0;
}
