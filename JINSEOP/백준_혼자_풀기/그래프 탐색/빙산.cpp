#include <iostream>
#include <queue>
using namespace std;

int row = 0, col = 0, answer = 0;
int sea[300][300], copied_sea[300][300];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[300][300];
void copy_sea() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            copied_sea[i][j] = sea[i][j];
}

void sea_copy() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            sea[i][j] = copied_sea[i][j];
}

void clear_visit() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            visit[i][j] = false;
}

void bfs(int st_x, int st_y) {
    queue<pair<int, int>> bfs_q;
    bfs_q.push({ st_x, st_y });
    visit[st_x][st_y] = true;

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first;
        int curr_y = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (sea[nx][ny] == 0)
                copied_sea[curr_x][curr_y] = max(copied_sea[curr_x][curr_y] - 1, 0);

            if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
                if (!visit[nx][ny] && sea[nx][ny] != 0) {
                    bfs_q.push({ nx, ny });
                    visit[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> sea[i][j];

    while (true) {
        bool flag = false;
        copy_sea();

        int burgs = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visit[i][j] && sea[i][j] != 0) {
                    flag = true;
                    bfs(i, j);
                    burgs++;
                }

                if (burgs >= 2) {
                    cout << answer;
                    return 0;
                }
            }
        }

        sea_copy();
        clear_visit();

        if (!flag) {
            cout << 0;
            return 0;
        }

        answer++;
    }
}
