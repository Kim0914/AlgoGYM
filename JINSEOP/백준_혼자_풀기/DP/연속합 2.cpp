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
		// 기본적인 연속합 점화식
		// 반드시 "연속해야 한다"는 점을 이용한다.
		// 계속 더해가는 값이 큰 지, 아니면 새로 시작하는 것이 더 큰 지 갱신

		reduced_dp[i] = max(dp[i - 1], reduced_dp[i - 1] + seq[i]);
		// 숫자 하나가 빠지게 되는 연속합
		// dp[i - 1]에 seq[i]를 더하지 않는 것을 확인할 수 있다.

		// 만약 dp[i - 1]을 최대값으로 선택하게 된다면?
		// reduced_dp[i]는 i번째 seq가 빠진채로 합이 갱신된 것이다.
		// 이 때 다음 갱신에서 reduced_dp[i - 1] + seq[i]를 선택하게 될 경우
		// 위에서 제거한 하나의 값을 제거한 채로 연속 합을 진행하는 것이 된다.

		// 새로 시작하는 게 더 클때는?
		// dp[i - 1]이 seq[i]로 선택되어, 어차피 영향을 받게 된다.

		answer = max(answer, max(dp[i], reduced_dp[i]));
		// 셋 중 가장 큰 값을 유지하는 방식으로
	}

	cout << answer;
	return 0;
}
