#include <iostream>
using namespace std;

int num = 0;
int board[100000][3];
int dp[3][2]; // 메모리 초과로 인해 줄인 배열
void init_dp() {
    dp[0][0] = board[0][0];
    dp[0][1] = board[0][0];
    dp[1][0] = board[0][1];
    dp[1][1] = board[0][1];
    dp[2][0] = board[0][2];
    dp[2][1] = board[0][2];
}

int main(){
    cin >> num;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];

    int max_temp1 = 0, max_temp2 = 0, max_temp3 = 0;
    int min_temp1 = 0, min_temp2 = 0, min_temp3 = 0;
    init_dp();
    for (int i = 1; i < num; i++) {
        max_temp1 = dp[0][0], min_temp1 = dp[0][1];
        max_temp2 = dp[1][0], min_temp2 = dp[1][1];
        max_temp3 = dp[2][0], min_temp3 = dp[2][1];

        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dp[j][0] = max(max_temp1 + board[i][j], max_temp2 + board[i][j]);
                dp[j][1] = min(min_temp1 + board[i][j], min_temp2 + board[i][j]);
            }
            
            if (j == 1) {
                dp[j][0] = max(max_temp1 + board[i][j],
                           max(max_temp2 + board[i][j],
                               max_temp3 + board[i][j]));
                dp[j][1] = min(min_temp1 + board[i][j],
                           min(min_temp2 + board[i][j],
                               min_temp3 + board[i][j]));
            }

            if (j == 2) {
                dp[j][0] = max(max_temp2 + board[i][j], max_temp3 + board[i][j]);
                dp[j][1] = min(min_temp2 + board[i][j], min_temp3 + board[i][j]);
            }
        }
    }

    int max_answer = 0, min_answer = 999999999;
    for (int i = 0; i < 3; i++) {
        if (max_answer < dp[i][0])
            max_answer = dp[i][0];
        if (min_answer > dp[i][1])
            min_answer = dp[i][1];
    }

    cout << max_answer << " " << min_answer;
    return 0;
}
