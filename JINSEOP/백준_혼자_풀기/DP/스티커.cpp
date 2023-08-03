#include <iostream>
using namespace std;

int tc = 0, num = 0;
int scores[2][100001], dp[2][100001];
int main() {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> scores[0][j];
		}
		for (int j = 0; j < num; j++) {
			cin >> scores[1][j];
		}

		dp[0][0] = scores[0][0]; dp[1][0] = scores[1][0];
		dp[0][1] = scores[0][1] + dp[1][0]; 
		dp[1][1] = scores[1][1] + dp[0][0]; // 미리 설정

		for (int j = 2; j < num; j++) {
			dp[0][j] = max(scores[0][j] + dp[1][j - 1], scores[0][j] + dp[1][j - 2]);
			dp[1][j] = max(scores[1][j] + dp[0][j - 1], scores[1][j] + dp[0][j - 2]);
		}

		cout << max(dp[0][num - 1], dp[1][num - 1]) << '\n';
	}

	return 0;
}
