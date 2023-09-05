#include <iostream>
#include <vector>
using namespace std;

int num = 0, seq[100001], dp[100001];
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> seq[i];

	dp[0] = seq[0]; // DP배열 초기화
	int answer = dp[0];
	for (int i = 1; i < num; i++) {
		dp[i] = max(dp[i - 1] + seq[i], seq[i]);
		// 선택을 이전 값을 선택하는 게 큰가 안하는게 큰가?
		answer = max(answer, dp[i]); // 정답은 해당 연속합에 따라
	}

	cout << answer;

	return 0;
}
