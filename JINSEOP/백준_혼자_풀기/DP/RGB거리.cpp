#include <iostream>
#include <vector>
using namespace std;

int num = 0, r = 0, g = 0, b = 0;
vector<pair<int, pair<int, int>>> houses;
int dp[3][1001];
void init_dp() {
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[2][0] = 0;
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> r >> g >> b;
		houses.push_back({ r, {g, b} });
	}

	init_dp();
	for (int i = 1; i <= num; i++) {
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + houses[i-1].first;
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + houses[i-1].second.first;
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + houses[i-1].second.second;
	}

	cout << min(dp[0][num], min(dp[1][num], dp[2][num]));
	return 0;
}
