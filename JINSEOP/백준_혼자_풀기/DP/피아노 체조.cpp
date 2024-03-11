#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 99999999

int num = 0, q_num = 0, from = 0, to = 0;
int composes[100002], dp[100002];
int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> composes[i];
	composes[num + 1] = MAX;

	for (int i = 1; i <= num; i++) {
		if (composes[i] < composes[i - 1])
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = dp[i - 1];
	}

	cin >> q_num;
	for (int i = 0; i < q_num; i++) {
		cin >> from >> to;
		cout << dp[to] - dp[from] << '\n';
	}

	return 0;
}
