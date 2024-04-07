#include <iostream>
#include <vector>
using namespace std;

int num = 0, whole_time = 0;
int dp[10001];
int main(){
	cin >> num >> whole_time;

	int each_time = 0, each_score = 0;
	for (int i = 0; i < num; i++) {
		cin >> each_time >> each_score;

		for (int j = whole_time; j >= each_time; j--)
			dp[j] = max(dp[j], dp[j - each_time] + each_score);
	}

	cout << dp[whole_time];
	return 0;
}
