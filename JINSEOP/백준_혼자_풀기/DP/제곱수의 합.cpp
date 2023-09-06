#include <iostream>
#include <vector>
using namespace std;

int num = 0, answer = 0, dp[100001];
void init_dp() {
	for (int i = 0; i <= num; i++)
		dp[i] = i;
}

void calc_square() {
	for (int i = 1; i <= num; i++)
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
}

int main() {
	cin >> num;

	init_dp();
	calc_square();

	cout << dp[num];
	return 0;
}
