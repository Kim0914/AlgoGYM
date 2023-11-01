#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];
string src = "", target = "", lcs = "";
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> src >> target;
	for (int i = 1; i <= target.size(); i++) {
		for (int j = 1; j <= src.size(); j++) {
			// 원 문자열을 기준으로 문자열을 하나씩 늘려가며 검사한다.
			// C와 A, C와 AC, C와 ACA, C와 ACAY...
			// 그래서, DP(Memoization)가 되는 것이다.
			if (src[j-1] == target[i-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int col = src.size();
	int row = target.size();
	while (dp[row][col] != 0) {
		if (dp[row][col] == dp[row - 1][col])
			row--;
		// 세로로 같은 값이면 세로로 한 칸 앞 이동
		else if (dp[row][col] == dp[row][col - 1])
			col--;
		// 가로로 같은 값이면 가로로 한 칸 앞 이동
		else {
			lcs = src[col - 1] + lcs;
			row--; col--;
		}
		
		// 이 부분의 핵심은, LCS의 길이가 갱신되는 부분은
		// 현재 위치에 대해서 가로로든 세로로든 값이 다르다는 점을 이용하는 것이다.
	}

	if (dp[target.size()][src.size()] == 0)
		cout << 0; // LCS가 없는 경우
	else
		cout << dp[target.size()][src.size()] << '\n' << lcs;
	return 0;
}
