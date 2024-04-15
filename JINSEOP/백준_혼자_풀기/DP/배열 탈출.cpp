#include <queue>
#include <iostream>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 999999999

int row = 0, arr_map[2223][2223], dp[2223][2223];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
void init_dp_with_INF() {
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= row; j++)
            dp[i][j] = INF;

    dp[1][1] = 0; // 시작점은 반드시 비용이 0
}

void do_dp(){
    for(int i = 1; i <= row; i++){
        for (int j = 1; j <= row; j++) {

            for (int k = 0; k < 2; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if ((nx >= 1 && nx <= row) && (ny >= 1 && ny <= row)) {
                    if (arr_map[nx][ny] >= arr_map[i][j]) {
                        // 버튼을 눌러야 하는 경우임
                        int diff = arr_map[nx][ny] - arr_map[i][j] + 1;
                        dp[nx][ny] = min(dp[nx][ny], dp[i][j] + diff);
                        // min()으로 계속 갱신하면서 나아간다
                    }
                    else
                        dp[nx][ny] = min(dp[nx][ny], dp[i][j]);
                    // 안눌러도 되는 경우엔 비용이 0원이 듬
                }
            }
        }
    }
}

int main() {
    OPTIMIZE;
    cin >> row;

    init_dp_with_INF();
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= row; j++)
            cin >> arr_map[i][j];

    do_dp();
    cout << dp[row][row];
    return 0;
}
