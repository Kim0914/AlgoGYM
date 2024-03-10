#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[1001][1001];
void input_coefficient(int x1, int x2, int y1, int y2, int coef) {
    dp[x1][y1] += coef;
    dp[x2 + 1][y1] -= coef;
    dp[x1][y2 + 1] -= coef;
    dp[x2 + 1][y2 + 1] += coef;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    for (auto info : skill) {
        int x1 = info[1];
        int y1 = info[2];
        int x2 = info[3];
        int y2 = info[4];

        if (info[0] == 1)
            input_coefficient(x1, x2, y1, y2, info[5] * -1);
        else
            input_coefficient(x1, x2, y1, y2, info[5]);
    } // 여기서 dp 배열에 누적합 계수를 모두 저장한다.

    for (int i = 0; i <= board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            dp[i][j + 1] += dp[i][j];

    for (int j = 0; j <= board[0].size(); j++)
        for (int i = 0; i < board.size(); i++)
            dp[i + 1][j] += dp[i][j];
    // 위의 두 for문이 누적합 계수를 만드는 과정

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (board[i][j] + dp[i][j] > 0)
                answer++;
    // 최종적으로 남은 계수들을 더했을 때 살아있는 지형 카운트

    return answer;
}
