#include <iostream>
#include <vector>
using namespace std;

int dp[101];
void init_dp() {
	for (int i = 0; i < 4; i++)
		dp[i] = i;
}

int main() {
	int num = 0, buffer = 3;
	cin >> num;

	init_dp();
	for (int i = 4; i < num; i++) {
		if (dp[i - 1] < dp[i - 3]) { // Ctrl-A Ctrl-C Ctrl-V를 한 것
			buffer = dp[i - 3];
			dp[i] = dp[i - 3] + buffer;
		}
	}

	cout << dp[num];
	return 0;
}
