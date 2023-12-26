#include <iostream>
using namespace std;
#define ll long long

ll target = 0;
ll dp[1000001];
int main() {
	cin >> target;

	dp[1] = 1;
	for (int i = 2; i <= target; i++) {
		if (i % 2 == 0)
			dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000;
		// 짝수의 경우는, 이전거에 + 1만 하는 경우와
		// 2로 나눈 값에 2를 더하는 경우로 모두 구할 수 있다.
		// 왜? 2의 멱수만이 더해지기 때문.
		else
			dp[i] = dp[i - 1] % 1000000000;
		// 홀수의 경우는 무조건 짝수랑 같음
	}
	
	cout << dp[target] % 1000000000;
	return 0;
}
