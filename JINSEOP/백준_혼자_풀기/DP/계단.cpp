#include <iostream>
using namespace std;
#define ll long long

int num = 0;
ll histogram[100000], dp[100000];
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();

	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> histogram[i];
	
	ll max_stair = 1;
	dp[0] = 1; // 계단 높이 1부터 시작
	for (int i = 1; i < num; i++) {
		if ((dp[i - 1] + 1) > histogram[i])
			dp[i] = histogram[i];
		else
			dp[i] = dp[i - 1] + 1;

		max_stair = max(dp[i], max_stair);
	}

	cout << max_stair;
	return 0;
}
