#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int max_day = 0;
queue<pair<int, int>> bfs_q;
void bfs(int x, int y, vector<string> maps, vector<vector<bool>>& visit) {
    bfs_q.push({x, y});
    visit[x][y] = true;

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first;
        int curr_y = bfs_q.front().second;
        max_day += maps[curr_x][curr_y] - '0';

        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            if ((nx >= 0 && nx < maps.size()) && (ny >= 0 && ny < maps[0].size())) {
                if (!visit[nx][ny] && maps[nx][ny] != 'X') {
                    visit[nx][ny] = true;
                    bfs_q.push({ nx, ny });
                }
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (!visit[i][j] && maps[i][j] != 'X') {
                max_day = 0;
                bfs(i, j, maps, visit);
                answer.push_back(max_day);
            }
        }
    }

    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());

    return answer;
}

// 간단하고 기본적인 BFS 돌리기
