#include <vector>
using namespace std;
#define INF 1000000000

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;

    vector<int> graph[201];
    vector<vector<int>> dp(k, vector<int>(n + 1, INF));

    for (int i = 0; i < edge_list.size(); i++) { // 그래프 생성
        graph[edge_list[i][0]].push_back(edge_list[i][1]);
        graph[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    dp[0][gps_log[0]] = 0; // 초기값, 택시의 처음 위치에서는 0
    for (int i = 1; i < gps_log.size(); i++) {
        for (int j = 1; j <= n; j++) { 
            if (dp[i - 1][j] == INF)
                continue; // 이전 시간에 봤을 때, 경로가 없다? 패스

            for (int d = 0; d < graph[j].size(); d++) {
                int next_node = graph[j][d];
                int fix_cnt = 0;

                if (gps_log[i] != next_node)
                    fix_cnt++; // 로그에 기록된 정점과 다르면 수정해야 함

                dp[i][next_node] = min(dp[i][next_node], dp[i - 1][j] + fix_cnt);
                // 이전 시간 경로 + 수정 횟수로 갱신한다.
            }
        }
    }

    if (dp[k - 1][gps_log[k - 1]] != INF)
        answer = dp[k - 1][gps_log[k - 1]];
    else
        answer = -1;

    return answer;
}
