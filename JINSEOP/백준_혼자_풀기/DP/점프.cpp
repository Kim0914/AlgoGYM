#include <iostream>
using namespace std;
#define ll long long

int num = 0;
int board[100][100];
ll dp[100][100];
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check_right(int curr_x, int curr_y) {
    int nx_right = curr_x;
    int ny_right = curr_y + board[curr_x][curr_y];

    if (ny_right >= num)
        return false;
    return true;
}

bool check_down(int curr_x, int curr_y) {
    int nx_down = curr_x + board[curr_x][curr_y];
    int ny_down = curr_y;

    if (nx_down >= num)
        return false;
    return true;
}

int main() {
    optimize();
    cin >> num;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            cin >> board[i][j];

    dp[0][0] = 1; // 출발지는 무조건 1이어야 탐색 가능
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if(dp[i][j] == 0 || (i == num - 1 && j == num - 1))
                continue; // 출발할 수 없는 지점이거나, 종착지면 탐색 필요 X

            if (check_right(i, j))
                dp[i][j + board[i][j]] = dp[i][j + board[i][j]] + dp[i][j]; // 오른쪽 진행
            if (check_down(i, j))
                dp[i + board[i][j]][j] = dp[i][j] + dp[i + board[i][j]][j]; // 아래 진행
        }
    }
    // 이렇게 다 돌려서 최종점에 쌓인 횟수 출력

    cout << dp[num - 1][num - 1];
    return 0;
}
