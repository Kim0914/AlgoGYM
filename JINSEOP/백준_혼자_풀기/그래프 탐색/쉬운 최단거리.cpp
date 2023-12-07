#include <iostream>
#include <queue>
using namespace std;

int row = 0, col = 0;
int board[1001][1001], answer[1001][1001];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[1001][1001];
pair<int, int> start_pos;
void bfs() {
    queue<pair<int, int>> bfs_q;
    bfs_q.push(start_pos);
    visit[start_pos.first][start_pos.second] = true;
    
    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first;
        int curr_y = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
                if (!visit[nx][ny] && board[nx][ny] != 0) {
                    answer[nx][ny] = answer[curr_x][curr_y] + 1;
                    visit[nx][ny] = true;
                    bfs_q.push({ nx, ny });
                }
            }
        }
    }
}

void check_leftover() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (answer[i][j] == 0 && board[i][j] == 1)
                answer[i][j] = -1;
}

int main() {
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2)
                start_pos = { i, j };
        }
    }

    bfs();
    check_leftover();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << answer[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
