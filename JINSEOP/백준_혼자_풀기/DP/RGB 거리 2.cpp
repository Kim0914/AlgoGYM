#include <iostream>
using namespace std;
#define MAX 99999999

int num = 0, dp[3][1000], house_info[3][1000];
void clear_dp(){
	for (int i = 0; i < num; i++)
		for (int j = 0; j < 3; j++)
			dp[j][i] = 0;
}

int main() {
	int answer = MAX;

	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < 3; j++)
			cin >> house_info[j][i];

	for (int fix = 0; fix < 3; fix++) {
		for (int i = 0; i < 3; i++) {
			if (i == fix)
				dp[fix][0] = house_info[fix][0];
			else
				dp[i][0] = MAX;
			// 가장 첫 집을 R G B (fix) 값으로 고정시킨다.
      // 해당 집만 고르도록 하기 위해, 나머지 집은 큰 값으로 배정
		}

		for (int i = 1; i < num; i++) {
			dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + house_info[0][i];
			dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + house_info[1][i];
			dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + house_info[2][i];
		} // RGB 거리 1과 마찬가지로 Memoization 진행

		for (int i = 0; i < 3; i++) {
			if (i == fix)
				continue;
			answer = min(answer, dp[i][num - 1]);
			// 마지막 집은 위에서 고정시킨 fix 값을 제외한 색을 선택한다.
			// 그 때, 가장 최소가 되는 값이 답이 된다.
		}

		clear_dp();
    // fix 값 마다 dp 배열을 초기화 해주고 새로 계산한다.
	}

	cout << answer;
	return 0;
}
