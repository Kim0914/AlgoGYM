#include <iostream>
#include <queue>
using namespace std;

struct infos {
    int x;
    int y;
    int z;
    int timer;

    infos(int _x, int _y, int _z, int _timer) : x(_x), y(_y), z(_z), timer(_timer)
    {}
};

int row = 0, col = 0, height = 0, answer = 0;
int tomato_box[100][100][100];
int dx[6] = { -1, 0, 1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
vector<infos> tomato_pos;
bool visit[100][100][100];
bool check_ripe() {
    for (int h = 0; h < height; h++)
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (tomato_box[i][j][h] == 0)
                    return false;

    return true;
}

void bfs() {
    queue<infos> bfs_q;
    
    for (int i = 0; i < tomato_pos.size(); i++) {
        bfs_q.push(tomato_pos[i]);
        visit[tomato_pos[i].x][tomato_pos[i].y][tomato_pos[i].z] = true;
    }

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().x;
        int curr_y = bfs_q.front().y;
        int curr_z = bfs_q.front().z;
        int curr_time = bfs_q.front().timer;
        bfs_q.pop();
        answer = max(answer, curr_time);

        for (int i = 0; i < 6; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            int nz = curr_z + dz[i];

            if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col) && (nz >= 0 && nz < height)) {
                if (!visit[nx][ny][nz] && tomato_box[nx][ny][nz] == 0) {
                    bfs_q.push({ nx, ny, nz, curr_time+1 });
                    tomato_box[nx][ny][nz] = 1;
                    visit[nx][ny][nz] = true;
                }
            }
        }
    }
}

int main() {
    cin >> col >> row >> height;

    bool ripe_flag = true;
    for (int h = 0; h < height; h++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> tomato_box[i][j][h];

                if (tomato_box[i][j][h] == 1)
                    tomato_pos.push_back(infos(i, j, h, 0));
                if (tomato_box[i][j][h] == 0)
                    ripe_flag = false;
            }
        }
    }

    if (ripe_flag) {
        cout << 0;
        return 0;
    }

    bfs();

    if (!check_ripe())
        answer = -1;
    cout << answer;
    return 0;
}
