#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321
#define MINF -987654321

int row = 0;
int dp[5][5], min_dp[5][5];
char map[5][5];
void init_dp() {
	dp[0][0] = (map[0][0] - '0');
	min_dp[0][0] = (map[0][0] - '0');
}

int calculate(int src, int dest, char oper) {
	if (oper == '+')
		return src + dest;
	if (oper == '-')
		return src - dest;
	if (oper == '*')
		return src * dest;
}

int main() {
	cin >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> map[i][j];

	init_dp();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (i == 0 && j == 0)
				continue; // 첫 칸은 패스

			// 어차피 내 칸으로 올 수 있는 곳은 왼쪽 or 위
			if (map[i][j] >= '0' && map[i][j] <= '9') {
			// 해당 칸이 숫자인 경우
				if (i == 0) {
					dp[i][j] = calculate(dp[i][j - 1], map[i][j] - '0', map[i][j - 1]);
					min_dp[i][j] = calculate(min_dp[i][j - 1], map[i][j] - '0', map[i][j - 1]);
				}
				else if (j == 0) {
					dp[i][j] = calculate(dp[i - 1][j], map[i][j] - '0', map[i - 1][j]);
					min_dp[i][j] = calculate(min_dp[i - 1][j], map[i][j] - '0', map[i - 1][j]);
				}
				else {
					dp[i][j] = max(calculate(dp[i][j - 1], map[i][j] - '0', map[i][j - 1]),
								   calculate(dp[i - 1][j], map[i][j] - '0', map[i - 1][j]));
					min_dp[i][j] = min(calculate(min_dp[i][j - 1], map[i][j] - '0', map[i][j - 1]),
									   calculate(min_dp[i - 1][j], map[i][j] - '0', map[i - 1][j]));
				}
			}
			else {
			// 해당 칸이 연산자인 경우, 이전 숫자 중 큰 수를 가져옴
				if (i == 0) {
					dp[i][j] = dp[i][j - 1];
					min_dp[i][j] = min_dp[i][j - 1];
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j];
					min_dp[i][j] = min_dp[i - 1][j];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
					min_dp[i][j] = min(min_dp[i - 1][j], min_dp[i][j - 1]);
				}
			}
		}
	}

	cout << dp[row - 1][row - 1] << " " << min_dp[row - 1][row - 1];
	return 0;
}
