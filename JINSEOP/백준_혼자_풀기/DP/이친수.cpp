#include <iostream>
using namespace std;

int num = 0;
long long dp[91];
void init_dp(){
	dp[1] = 1; 
	dp[2] = 1;
}
void find_prinary() {
	for (int i = 3; i <= num; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
}

int main() {
	cin >> num;

	init_dp();
	find_prinary();

	cout << dp[num];

	return 0;
}
