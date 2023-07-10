#include <iostream>
#include <vector>
using namespace std;

long long dp[101];
void init_dp() {
	for (int i = 0; i < 4; i++)
		dp[i] = i;
}

int main() {
	int num = 0, buffer = 0;
	cin >> num;

	init_dp();
	for (int i = 4; i <= num; i++) {
		if ((dp[i - 1] + 1) <= dp[i - 3] + dp[i - 3]) { // Ctrl-A Ctrl-C Ctrl-V를 한 것
			if ((dp[i - 1] + buffer) > (dp[i - 3] + dp[i - 3])) { 
				// dp[i-3]은 buffer가 될 예정
				// 그냥 Ctrl V 하는 경우.
				dp[i] = dp[i - 1] + buffer;
				continue;
			}

			buffer = dp[i - 3]; // 이게 제일 큰 경우 buffer를 2배로
			dp[i] = dp[i - 3] + buffer;
		}
		else {
			if ((dp[i - 1] + buffer) > (dp[i - 1] + 1)) {
				dp[i] = dp[i - 1] + buffer;
				continue;
			}

			dp[i] = dp[i - 1] + 1; // 그냥 A를 입력하는 경우
		}
	}

	cout << dp[num];
	return 0;
}
