#include <iostream>
#include <vector>
using namespace std;

int sec = 0, limit = 0, info[1000];
int plum_dp[31][2][1001]; // 이동 횟수, 현재 위치, 지난 시간
int main(){
	cin >> sec >> limit;
	for (int i = 1; i <= sec; i++) {
		cin >> info[i];
	}

	for (int pos = 0; pos <= limit; pos++) {
		for (int timer = 1; timer <= sec; timer++) {
			if (pos == 0)
				plum_dp[pos][0][timer] = plum_dp[pos][0][timer - 1] + (info[timer] == 1);
			// 위치 변경을 하지 않는 경우에는, 1번 위치에서 더 이상 움직이지 않아도 된다.
			// (info[timer] == 1) 의 의미는 1번 위치에 자두가 내려오는 경우에만 받는다.
			// 이런 식으로도 값을 사용할 수 있구나
			else {
				plum_dp[pos][0][timer] = max(plum_dp[pos][0][timer - 1] + (info[timer] == 1),
					plum_dp[pos - 1][1][timer - 1] + (info[timer] == 1));
				// pos를 사용하는 경우는, 위치 변경을 하지 않는 경우
				// pos - 1을 뒤에서 가져오는 경우는, 위치 변경을 하는 경우
				plum_dp[pos][1][timer] = max(plum_dp[pos][1][timer - 1] + (info[timer] == 2),
					plum_dp[pos - 1][0][timer - 1] + (info[timer] == 2));
				// 0과 1을 따로 두는 이유는 위치 변경을 해서 자두를 얻을 수 있느냐 없느냐의 차이
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j <= limit; j++) 
			answer = max(answer, plum_dp[j][i][sec]);
	// 마지막 시간이 되었을 때, 최종적으로 위치변경을 몇 번했고
	// 어느 나무에 서있는 것이 최대가 되는가?

	cout << answer;
	return 0;
}
