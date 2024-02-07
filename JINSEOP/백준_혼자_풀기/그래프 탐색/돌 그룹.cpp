#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define piii pair<int, pair<int, int>>

int dx[6] = { -1, -1, 1, 1, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 1, -1 };
int dz[6] = {1, 0, -1, 0, -1, 1 };
bool visit[3][500];
bool validate(int target, int curr_x, int curr_y, int curr_z) {
    if (dx[target] == 0)
        if (curr_y == curr_z)
            return false;

    if (dy[target] == 0)
        if(curr_x == curr_z)
            return false;

    if (dz[target] == 0)
        if(curr_x == curr_y)
            return false;

    return true;
}

int bfs(piii start_state) {
    queue<piii> bfs_q;
    bfs_q.push(start_state);
    visit[0][start_state.first] = true;
    visit[1][start_state.second.first] = true;
    visit[2][start_state.second.second] = true;

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first;
        int curr_y = bfs_q.front().second.first;
        int curr_z = bfs_q.front().second.second;
        visit[0][curr_x] = true;
        visit[1][curr_y] = true;
        visit[2][curr_z] = true;
        bfs_q.pop();

        for (int i = 0; i < 6; i++) {
            if (!validate(i, curr_x, curr_y, curr_z))
                continue;

            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            int nz = curr_z + dz[i];
            
            if ((nx == ny) && (ny == nz))
                return 1;

            if ((nx >= 1 && nx <= 500) && (ny >= 1 && ny <= 500) && (nz >= 1 && nz <= 500)) {
                if (visit[0][nx] && visit[1][ny] && visit[2][nz])
                    continue;
                // 이미 거쳤던 상태(캐시)
                bfs_q.push({ nx, {ny, nz} });
                visit[0][nx] = true;
                visit[1][ny] = true;
                visit[2][nz] = true;
            }
        }
    }

    return 0;
}

int main() {
    piii stones;
    cin >> stones.first;
    cin >> stones.second.first;
    cin >> stones.second.second;

    cout << bfs(stones);
    return 0;
}
