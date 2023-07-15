#include <iostream>
#include <vector>
using namespace std;
#define ll long long

 ll dp[101][21];
int main() {
	int num = 0;
	cin >> num;
	vector<int> digits(num + 1, 0);

	for (int i = 1; i <= num; i++) {
		cin >> digits[i];
	}

	dp[1][digits[1]] = 1; // 가장 처음 숫자
	for (int i = 2; i <= num; i++) { // 몇 번째 수 ?
		for (int j = 0; j < 21; j++) { // 합이 몇 ?
			if (dp[i - 1][j]) {
				if(j + digits[i] <= 20) // 합이 20 이하면 경우의 수 추가
					dp[i][j + digits[i]] += dp[i-1][j];
				if(j - digits[i] >= 0) // 합이 0 이상이면 경우의 수 추가
					dp[i][j - digits[i]] += dp[i-1][j];
			}
		}
	}

	cout << dp[num - 1][digits[num]];
	// n-1번째 수가 합이 n이 될 확률

	return 0;
}
