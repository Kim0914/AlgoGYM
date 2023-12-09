#include <iostream>
#include <queue>
using namespace std;

int row = 0, col = 0, answer_cnt = 0, answer_area = 0;
int paper[500][500];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[500][500];
int bfs(int x, int y) {
    queue<pair<int, int>> bfs_q;

    int partial_area = 1;
    bfs_q.push({ x, y });
    visit[x][y] = true;

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first;
        int curr_y = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
                if (!visit[nx][ny] && paper[nx][ny] == 1) {
                    bfs_q.push({ nx, ny });
                    visit[nx][ny] = true;
                    partial_area++;
                }
            }
        }
    }

    return partial_area;
}
int main() {
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> paper[i][j];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!visit[i][j] && paper[i][j] == 1) {
                answer_area = max(answer_area, bfs(i, j));
                answer_cnt++;
            }
        }
    }

    cout << answer_cnt << '\n' << answer_area;
    return 0;
}
