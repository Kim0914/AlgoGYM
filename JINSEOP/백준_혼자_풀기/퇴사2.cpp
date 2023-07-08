#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> counsel_list;
int main() {
	int retire = 0, time = 0, pay = 0;

	cin >> retire;
	vector<int> dp(retire + 1, 0);
	for (int i = 0; i < retire; i++) {
		cin >> time >> pay;
		counsel_list.push_back({ pay, time });
	}

	for (int i = retire - 1; i >= 0; i--) {
		int curr_pay = counsel_list[i].first;
		int curr_time = counsel_list[i].second;

		if (i + curr_time > retire)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i + 1], curr_pay + dp[i + curr_time]);
	}

	cout << dp[0];
	return 0;
}
