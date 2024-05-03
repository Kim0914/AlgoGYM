#include <iostream>
#include <queue>
using namespace std;

int row = 0, col = 0;
int maze[1000][1000], dp[1000][1000];
void init_dp() {
	dp[0][0] = maze[0][0];

	for (int i = 1; i < row; i++)
		dp[i][0] += dp[i - 1][0] + maze[i][0];
	for (int i = 1; i < col; i++)
		dp[0][i] += dp[0][i - 1] + maze[0][i];
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> maze[i][j];

	init_dp();
	for (int i = 1; i < row; i++)
		for (int j = 1; j < col; j++)
			dp[i][j] = max(dp[i][j - 1] + maze[i][j], dp[i - 1][j] + maze[i][j]);

	cout << dp[row - 1][col - 1];
	return 0;
}
