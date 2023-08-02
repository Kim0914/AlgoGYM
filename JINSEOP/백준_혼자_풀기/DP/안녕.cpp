#include <iostream>
using namespace std;

int vitals[21], delights[21], dp[101]; 
// 체력을 배열로
int main() {
	int num = 0;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> vitals[i];
	}
	for (int i = 0; i < num; i++) {
		cin >> delights[i];
	}

	for (int i = 0; i <= num; i++) {
		for (int j = 100; j >= vitals[i]; j--) {
			dp[j] = max(dp[j], dp[j - vitals[i]] + delights[i]);
			// 현재 값을 그대로 가져가는지, 혹은 이전 체력 + 기쁨을 해서 누적할 것인지
		}
	}

	cout << dp[99];
	return 0;
}
