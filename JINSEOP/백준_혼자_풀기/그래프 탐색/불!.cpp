#include <iostream>
#include <queue>
using namespace std;

int row = 0, col = 0;
char dungeon[1000][1000];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
pair<int, int> start_pos;
vector<pair<int, int>> fire_pos;
bool visit[1000][1000], fire_visit[1000][1000];
void move_jihoon() {
    queue<pair<pair<int, int>, int>> bfs_q;

    for (int i = 0; i < fire_pos.size(); i++) {
        bfs_q.push({ { fire_pos[i].first, fire_pos[i].second }, -9});
        visit[fire_pos[i].first][fire_pos[i].second] = true;
    } // 불의 출발점은 여러 곳일 수 있음

    bfs_q.push({ {start_pos.first, start_pos.second}, 0 });
    visit[start_pos.first][start_pos.second] = true;
    // 불을 먼저 움직여보자.

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first.first;
        int curr_y = bfs_q.front().first.second;
        int curr_state = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if ((nx < 0 || nx >= row || ny < 0 || ny >= col) && curr_state != -9) {
                cout << curr_state + 1;
                return;
            }

            if (curr_state == -9) {
                if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
                    // 이건 불이라는 뜻임
                    if (!fire_visit[nx][ny] && dungeon[nx][ny] == '.') {
                        dungeon[nx][ny] = 'F'; // 불은 사방으로 퍼진다
                        bfs_q.push({ {nx, ny}, curr_state });
                        fire_visit[nx][ny] = true;
                    }
                }
            }
            else {
                if (!visit[nx][ny] && dungeon[nx][ny] == '.' && dungeon[nx][ny] != 'F') {
                    bfs_q.push({ { nx, ny }, curr_state + 1});
                    visit[nx][ny] = true;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            cin >> dungeon[i][j];

            if (dungeon[i][j] == 'J')
                start_pos = { i, j };
            if (dungeon[i][j] == 'F')
                fire_pos.push_back({ i, j });
        }

    move_jihoon();
    return 0;
}
