#include <iostream>
using namespace std;

int board[1025][1025], dp[1025][1025];
int num = 0, sum_num = 0, src_x = 0, src_y = 0, dest_x = 0, dest_y = 0;
void optimize() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void init_dp() {
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            dp[i][j] += (dp[i][j - 1] + board[i][j]);
}

int main() {
    optimize();

    cin >> num >> sum_num;
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            cin >> board[i][j];

    init_dp();
    while (sum_num--) {
        int answer = 0;

        cin >> src_x >> src_y >> dest_x >> dest_y;
        for (int i = src_x; i <= dest_x; i++)
            answer += (dp[i][dest_y] - dp[i][src_y - 1]);
        
        cout << answer << '\n';
    }

    return 0;
}
