#include <iostream>
using namespace std;

int num = 0, seq[100001], dp[100001], reduced_dp[100001];
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> seq[i];

	dp[0] = seq[0];
	reduced_dp[0] = seq[0];
	int answer = seq[0];
	for (int i = 1; i < num; i++) {
		dp[i] = max(dp[i - 1] + seq[i], seq[i]);
		reduced_dp[i] = max(dp[i - 1], reduced_dp[i - 1] + seq[i]);
		answer = max(answer, max(dp[i], reduced_dp[i]));
	}

	cout << answer;
	return 0;
}
