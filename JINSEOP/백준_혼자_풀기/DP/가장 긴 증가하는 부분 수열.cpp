#include <iostream>
#include <vector>
using namespace std;

int num = 0, answer = 0;
int seq[1000], dp[1000];
int main(){
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> seq[i];

	for (int i = 0; i < num; i++) {
		dp[i] = seq[i];

		for (int j = 0; j <= i; j++) {
			if (dp[i] > dp[j])
				dp[i] = max(dp[j] + seq[i], dp[i]);
		}

		answer = max(answer, dp[i]);
	}

	cout << answer;

	return 0;
}
