#include <iostream>
#include <vector>
using namespace std;

int row = 0, col = 0, init_x = 0, init_y = 0, init_dir = 0, answer = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
// 0이 위, 1이 오른쪽, 2가 아래, 3이 왼쪽
int map_to_clean[50][50];
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void check_wall(int state) {
    if (state == 1) {
        cout << answer << '\n';
        exit(0);
        // 이 부분을 몰랐다.
        // exit를 통해서 아예 프로그램을 종료시킬 수 있다.
    }
}

void dfs(int curr_x, int curr_y, int curr_dir) {
    for (int i = 0; i < 4; i++) {
        // 바라보고 있는 방향부터 반시계로 도는게 중요하다.
        int nd = (curr_dir + 3 - i) % 4;
        int nx = curr_x + dx[nd];
        int ny = curr_y + dy[nd];
        // 이렇게 하면, 현재 1을 보고있었다면,

        if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
            if (map_to_clean[nx][ny] == 0) {
                map_to_clean[nx][ny] = 9;
                answer++;
                dfs(nx, ny, nd);
            }
        }
    }

    // 여기부턴 4방향 모두 청소가 이미 되었거나 벽인 경우
    switch (curr_dir)
    {
    case 0:
        check_wall(map_to_clean[curr_x + 1][curr_y]);
        dfs(curr_x + 1, curr_y, curr_dir);
        break;
    case 1:
        check_wall(map_to_clean[curr_x][curr_y - 1]);
        dfs(curr_x, curr_y - 1, curr_dir);
        break;
    case 2:
        check_wall(map_to_clean[curr_x - 1][curr_y]);
        dfs(curr_x - 1, curr_y, curr_dir);
        break;
    case 3:
        check_wall(map_to_clean[curr_x][curr_y + 1]);
        dfs(curr_x, curr_y + 1, curr_dir);
        break;
    default:
        break;
    }
}

int main() {
    optimize();

    cin >> row >> col;
    cin >> init_x >> init_y >> init_dir;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> map_to_clean[i][j];

    map_to_clean[init_x][init_y] = 9;
    answer++;
    dfs(init_x, init_y, init_dir);

    return 0;
}
