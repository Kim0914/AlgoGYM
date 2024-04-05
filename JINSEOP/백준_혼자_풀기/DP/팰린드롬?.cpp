#include <iostream>
#include <vector>
using namespace std;

int num = 0, query_num = 0;
int num_arr[2001], dp[2001][2001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> num_arr[i];

	for (int i = 1; i <= num; i++) {
		dp[i][i] = 1; // 1자리 수는 반드시 팰린드롬
	}

	for (int i = 1; i <= num - 1; i++) {
		if (num_arr[i + 1] == num_arr[i])
			dp[i][i+1] = 1; // 2자리 수는 앞뒤로 같아야 함
	}

	for (int i = num - 2; i >= 1; i--) {
		for (int j = i + 2; j <= num; j++) {
			if (num_arr[i] == num_arr[j] && dp[i + 1][j - 1] == 1)
				dp[i][j] = 1;
		}
	}

	cin >> query_num;
	int from = 0, to = 0;
	for (int i = 0; i < query_num; i++) {
		cin >> from >> to;
		cout << dp[from][to] << '\n';
	}

	return 0;
}
