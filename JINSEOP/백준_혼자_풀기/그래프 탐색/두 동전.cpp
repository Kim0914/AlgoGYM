#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row = 0, col = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };
char board[20][20];
bool visit[20][20][20][20];
vector<pair<int, int>> coin_pos;
queue<vector<int>> bfs_q;
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void init_queue() {
    vector<int> temp_vec;
    for (int i = 0; i < coin_pos.size(); i++) {
        temp_vec.push_back(coin_pos[i].first);
        temp_vec.push_back(coin_pos[i].second);
    }
    temp_vec.push_back(0);

    visit[temp_vec[0]][temp_vec[1]][temp_vec[2]][temp_vec[3]] = true;
    bfs_q.push(temp_vec);
}

bool check_range(int x, int y) {
    if (x < 0 || y < 0 || x >= row || y >= col)
        return false;

    return true;
}

int bfs() {
    init_queue();

    while (!bfs_q.empty()) {
        int curr_x_1 = bfs_q.front()[0];
        int curr_y_1 = bfs_q.front()[1];
        int curr_x_2 = bfs_q.front()[2];
        int curr_y_2 = bfs_q.front()[3];
        int curr_time = bfs_q.front()[4];
        bfs_q.pop();

        if (curr_time > 10)
            return -1;

        for (int i = 0; i < 4; i++) {
            int nx_1 = curr_x_1 + dx[i];
            int ny_1 = curr_y_1 + dy[i];
            int nx_2 = curr_x_2 + dx[i];
            int ny_2 = curr_y_2 + dy[i];

            if (!check_range(nx_1, ny_1) && check_range(nx_2, ny_2)) {
                if (curr_time + 1 > 10)
                    return -1;

                return curr_time + 1;
                // 둘 중 하나만 떨어지면 바로 종료
            }
            if (check_range(nx_1, ny_1) && !check_range(nx_2, ny_2)) {
                if (curr_time + 1 > 10)
                    return -1;

                return curr_time + 1;
                // 여기도 하나만 떨어지면 바로 종료
            }

            if (!check_range(nx_1, ny_1) && !check_range(nx_2, ny_2))
                continue;
            // 둘 다 맵 밖으로 나가면 안됨
            if (visit[nx_1][ny_1][nx_2][ny_2])
                continue;
            // 두 동전 모두 방문한 곳은 
            if (board[nx_1][ny_1] == '#' && board[nx_2][ny_2] == '#')
                continue;

            if (board[nx_1][ny_1] == '#') {
                 nx_1 = curr_x_1;
                 ny_1 = curr_y_1;
            // 벽을 만나면 움직이면 안됨
            }
            if (board[nx_2][ny_2] == '#') {
                 nx_2 = curr_x_2;
                 ny_2 = curr_y_2;
            // 벽을 만나면 움직이면 안됨
            }

            vector<int> temp_vec;
            temp_vec.push_back(nx_1);
            temp_vec.push_back(ny_1);
            temp_vec.push_back(nx_2);
            temp_vec.push_back(ny_2);
            temp_vec.push_back(curr_time + 1);
            bfs_q.push(temp_vec);

            visit[nx_1][ny_1][nx_2][ny_2] = true;
        }
    }

    return -1;
}

int main(){
    optimize();
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o')
                coin_pos.push_back({ i, j });
        }
    }

    cout << bfs();
    return 0;
}
