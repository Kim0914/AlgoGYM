#include <iostream>
#include <unordered_map>
using namespace std;

int row = 0, col = 0, answer = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char board[20][20];
bool board_visit[20][20];
unordered_map<char, int> alphabet_validator;
void backtrack(int curr_x, int curr_y, int cnt) {
    answer = max(answer, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = curr_x + dx[i];
        int ny = curr_y + dy[i];

        if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
            if (!board_visit[nx][ny] && !alphabet_validator[board[nx][ny]]) {
                board_visit[nx][ny] = true;
                alphabet_validator[board[nx][ny]] = 1;
                backtrack(nx, ny, cnt + 1);
                board_visit[nx][ny] = false;
                alphabet_validator[board[nx][ny]] = 0;
            }
        }
    }
}

int main() {
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> board[i][j];

    alphabet_validator[board[0][0]] = 1;
    // 시작점은 무조건 지남
    // count도 1부터 시작해야한다.
    backtrack(0, 0, 1);
    cout << answer;
    return 0;
}
