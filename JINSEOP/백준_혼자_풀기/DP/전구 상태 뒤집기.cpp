#include <iostream>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define ll long long

ll num = 0, sum = 0;
ll bulbs[200001], bulb_state[200001], dp[200001];
int main() {
	OPTIMIZE;

	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> bulbs[i];
	for (int i = 1; i <= num; i++) {
		cin >> bulb_state[i];
		if (bulb_state[i])
			sum += bulbs[i];
		// 초기 합을 저장해놓아야 뒤집었을 때 결과를 구할 수 있다.
	}

	for (int i = 1; i <= num; i++) {
	// 이 for문에서 매 순간 선택하는 것은 이전 전구에 이어서 뒤집을 것인가?
	// 아니면 현재 전구만 뒤집을 것인가?
		if (bulb_state[i])
			dp[i] = max(dp[i - 1] - bulbs[i], -bulbs[i]);
    	// 전구가 이미 켜진 경우, 현재부터 끄는 걸 시작할 것인가?
    	// 아니면 이전에 뒤집었던 전구에 이어서 뒤집을 것인가?
		else
			dp[i] = max(dp[i - 1] + bulbs[i], bulbs[i]);
	// 전구가 꺼져있는 경우, 현재부터 켜는 걸 시작할 것인가?
	// 아니면 이전에 뒤집었떤 전구에 이어서 뒤집을 것인가?
	}

	ll max_v = dp[1];
	for (int i = 1; i <= num; i++)
		max_v = max(max_v, dp[i]);
	// 모든 환경 중에서 가장 컸던 값을 선택해야 한다.
	// 이후 처음에 구했던 초기 합과 연산해준다.

	cout << max_v + sum;
	return 0;
}
