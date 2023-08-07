#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, cards[10001], dp[10001];
int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> cards[i];

	for (int i = 1; i <= num; i++) { // 1번 카드는 1장, 2번 카드는 2장..
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + cards[j]);
			// i번째 카드팩을 그대로 가져가거나, 
			// 마지막으로 j번째 카드팩을 고르는 경우
		}
	}

	cout << dp[num];
	return 0;
}
