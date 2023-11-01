#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];
string src = "", target = "";
int main(){
	cin >> src >> target;

	for (int i = 1; i <= src.size(); i++) {
		for (int j = 1; j <= target.size(); j++) {
			// 원 문자열을 기준으로 문자열을 하나씩 늘려가며 검사한다.
			// C와 A, C와 AC, C와 ACA, C와 ACAY...
			// 그래서, DP(Memoization)가 되는 것이다.
			if (src[i-1] == target[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << dp[src.size()][target.size()];

	return 0;
}
