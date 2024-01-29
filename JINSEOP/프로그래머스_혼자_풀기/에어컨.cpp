#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define INF 1000000

int dp[51][1000];
void init_dp(int temperature, vector<int>& onboard) {
	for(int i = 0; i <= 50; i++)
		for(int j = 0; j <= onboard.size(); j++)
			dp[i][j] = INF;
	dp[temperature][0] = 0;
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
	int answer = INF;

	// temperature : 실외 온도 (실내 시작 온도)
	// t1 ~ t2 : 승객 탑승 시 t1 ~ t2 사이에서 유지가 되어야 함
	// a : 실내 희망 다를 때 소비 전력
	// b : 같을 때 소비 전력
	// onboard : 승객 탑승 시간
	temperature += 10; t1 += 10; t2 += 10;
	init_dp(temperature, onboard);

	int min_time = min(t1, temperature);
	int max_time = max(t2, temperature);

	for (int i = 1; i < onboard.size(); i++) {
		int lower_time_bound = min_time;
		int upper_time_bound = max_time;
		// 어차피 t1, t2 혹은 실외온도를 벗어나는 것은 비효율적이다.

		if (onboard[i]) {
			lower_time_bound = t1;
			upper_time_bound = t2;
		}

		for (int j = lower_time_bound; j <= upper_time_bound; j++) {
			// 에어컨이 켜지는 경우들
			if (j + 1 <= max_time)
				dp[j][i] = min(dp[j][i], dp[j + 1][i - 1] + a);
			if (j - 1 >= min_time)
				dp[j][i] = min(dp[j][i], dp[j - 1][i - 1] + a);
			dp[j][i] = min(dp[j][i], dp[j][i - 1] + b);

			// 에어컨이 꺼지는 경우들
			if ((j + 1 > temperature) && (j + 1 <= max_time))
				dp[j][i] = min(dp[j][i], dp[j + 1][i - 1]);
			if ((j - 1 < temperature) && (j - 1 >= min_time))
				dp[j][i] = min(dp[j][i], dp[j - 1][i - 1]);
			if ((j == temperature) && (j <= max_time) && (j >= min_time))
				dp[j][i] = min(dp[j][i], dp[j][i - 1]);
		}
	}

	for (int i = 0; i <= 50; i++)
		answer = min(dp[i][onboard.size() - 1], answer);

	return answer;
}
