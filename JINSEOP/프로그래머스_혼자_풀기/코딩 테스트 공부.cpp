#include <iostream>
#include <vector>
using namespace std;
#define MAX 999999999

int max_alp = 0, max_cop = 0;
int dp[151][151];
void init_dp() {
	for (int i = 0; i < 151; i++)
		for (int j = 0; j < 151; j++)
			dp[i][j] = MAX;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;

	init_dp(); // 배열을 큰 값으로 초기화 해야 함.
	for (int i = 0; i < problems.size(); i++) {
		max_alp = max(max_alp, problems[i][0]);
		max_cop = max(max_cop, problems[i][1]);
		// 요구되는 알고력, 코딩력 중 최대치를 먼저 구한다.
		// 여기에 도달하면 알고리즘이 종료됨을 의미한다.
	}
	
	alp = min(alp, max_alp);
	cop = min(cop, max_cop);
	// 이미 주어진 알고 / 코딩력으로 모두 해결가능할 때
	// 최대치로 바꿔주어야 한다.

	int alp_idx = 0, cop_idx = 0;
	dp[alp][cop] = 0; // 시작점
	// row를 알고력, col을 코딩력으로 잡고 dp를 진행한다.
	for (int i = alp; i <= max_alp; i++) {
		for (int j = cop; j <= max_cop; j++) {
			// 알고력 1, 코딩력 1 증가.
			// 문제를 푸는 것이 아닌 그냥 공부하는 경우를 의미한다.
			alp_idx = min(i + 1, max_alp);
			cop_idx = min(j + 1, max_cop);
			// 해당 예외처리는, 현재 알고력과 코딩력이 최대치를 넘었을 때
			// 최대치로 현재 알고력 코딩력을 고정시키는 처리이다.

			dp[alp_idx][j] = min(dp[alp_idx][j], dp[i][j] + 1);
			dp[i][cop_idx] = min(dp[i][cop_idx], dp[i][j] + 1);
			
			for (int k = 0; k < problems.size(); k++) {
				// 이 부분은 문제를 학습하는 경우
				int alp_req = problems[k][0];
				int cop_req = problems[k][1];
				int alp_rwd = problems[k][2];
				int cop_rwd = problems[k][3];
				int cost = problems[k][4];

				if (i < alp_req || j < cop_req)
					continue; // 현재 알고/코딩력이 요구치보다 낮으면 못풀고 넘어간다.
				alp_idx = min(i + alp_rwd, max_alp);
				cop_idx = min(j + cop_rwd, max_cop);
				// 위의 예외처리와 동일하게 진행한다.

				dp[alp_idx][cop_idx] = min(dp[alp_idx][cop_idx], dp[i][j] + cost);
				// 문제를 풀었을 때 증가한 알고 / 코딩력에 대해 비용을 저장한다
			}
		}
	}

	answer = dp[max_alp][max_cop];
	return answer;
}
