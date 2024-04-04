#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll row = 0, col = 0, work_num = 0, from_x = 0, from_y = 0, to_x = 0, to_y = 0;
ll road[101][101], dp[101][101];
int main(){
	cin >> row >> col;
	cin >> work_num;
	for (int i = 0; i < work_num; i++) {
		cin >> from_x >> from_y >> to_x >> to_y;

		if (from_x - to_x != 0) {
			if(from_x > to_x)
				road[from_x][from_y] += 1;
			else
				road[to_x][to_y] += 1;
		// 위에서 내려옴
		}
		if (from_y - to_y != 0) {
			if (from_x > to_x)
				road[from_x][from_y] += 2;
			else
				road[to_x][to_y] += 2;
		}
		// 옆에서 옴
	}
	
	dp[0][0] = 1;
	for (int i = 1; i <= col; i++) {
		if (road[0][i] != 0)
			break;
		dp[0][i] = dp[0][i-1];
	}

	for (int i = 1; i <= row; i++) {
		if (road[i][0] != 0)
			break;
		dp[i][0] = dp[i-1][0];
	} // 가로, 세로 첫 줄 먼저 계산

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (road[i][j] == 1)
				dp[i][j] = dp[i][j - 1];
			else if (road[i][j] == 2)
				dp[i][j] = dp[i - 1][j];
			else if (road[i][j] == 3)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	cout << dp[row][col];
	return 0;
}
