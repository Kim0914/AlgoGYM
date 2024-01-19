#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 99999999

int tc = 1, row = 0;
ll tri_graph[100000][3], dp[100000][3];
void clear_dp() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = 0;
}

void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init_dp() {
	dp[0][0] = INF; // 여긴 어차피 갈 수 없는 구역
	dp[0][1] = tri_graph[0][1];
	dp[0][2] = tri_graph[0][1] + tri_graph[0][2];
	// 0, 2 구역은 무조건 이렇게만 갈 수 있음
}

int main() {
	optimize();

	while (true) {
		cin >> row;
		if (row == 0)
			return 0;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < 3; j++)
				cin >> tri_graph[i][j];

		init_dp();
		for (int i = 1; i < row; i++) {
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + tri_graph[i][0];
			dp[i][1] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] }) + tri_graph[i][1];
			dp[i][2] = min({dp[i-1][1], dp[i-1][2], dp[i][1]}) + tri_graph[i][2];
		}

		cout << tc++ << ". " << dp[row - 1][1] << '\n';
		clear_dp();
	}
}
