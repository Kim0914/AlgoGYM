#include<vector>
#include<queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visit[100][100];
queue<pair<int, int>> bfs_q;

void bfs(int st_x, int st_y, vector<vector<int>>& maps, int x_size, int y_size) {
    visit[st_x][st_y] = true;
    bfs_q.push(make_pair(st_x, st_y));

    while (!bfs_q.empty()) {
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ((nx >= 0 && nx < x_size) && (ny >= 0 && ny < y_size)) {
                if (!visit[nx][ny] && maps[nx][ny]) {
                    bfs_q.push(make_pair(nx, ny));
                    visit[nx][ny] = true;
                    maps[nx][ny] = maps[x][y] + 1;
                    if (nx == x_size-1 && ny == y_size-1) return;
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int x_size = maps.size();
    int y_size = maps[0].size();
    
    bfs(0, 0, maps, x_size, y_size);
    if(maps[x_size-1][y_size-1] == 1) answer = -1;
    else answer = maps[x_size-1][y_size-1];
    
    return answer;
}
