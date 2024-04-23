#include <iostream>
#include <string>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int weeks = 0;
double num = 0, interest = 0;
double balances[1001], dp[1001];
int main() {
	OPTIMIZE;
	cin >> num;

	double whole_balance = 0;
	for (int i = 0; i < num; i++) {
		cin >> balances[i];
		whole_balance += balances[i];
	}
	cin >> interest >> weeks;

	dp[0] = balances[0]; // 강호의 잔고 (확률)
	for (int i = 1; i <= weeks; i++)
		dp[i] = dp[i - 1] + ((balances[0] / whole_balance) * interest);
	// 강호의 처음 잔고 + (((잔고 / 총 잔액) * 이자) * 걸린 시간)
	// 

	cout.precision(10);
	cout << dp[weeks];
	return 0;
}
