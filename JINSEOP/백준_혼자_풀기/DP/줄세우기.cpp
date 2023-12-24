#include <iostream>
using namespace std;

int num = 0;
int kids_line[201], dp[201];
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> kids_line[i];

	int lis = 0;
	for (int i = 0; i < num; i++){
		dp[i] = 1;

		for (int j = 0; j <= i; j++)
			if (kids_line[i] > kids_line[j])
				dp[i] = max(dp[i], dp[j] + 1);

		lis = max(lis, dp[i]);
	}

	cout << num - lis;
	return 0;
}
