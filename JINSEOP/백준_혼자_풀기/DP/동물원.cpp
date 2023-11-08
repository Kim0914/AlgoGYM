#include <iostream>
using namespace std;

int num = 0, box = 0, dp[100001];
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();
	cin >> num;

	dp[0] = 1; dp[1] = 3;
	for (int i = 2; i <= num; i++)
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;

	cout << dp[num];
	return 0;
}
