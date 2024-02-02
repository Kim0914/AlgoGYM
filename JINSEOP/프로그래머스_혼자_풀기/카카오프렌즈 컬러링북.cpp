#include <vector>
#include <queue>
using namespace std;
#define pii pair<int, int>

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[100][100];
int bfs(int st_x, int st_y, int target, vector<vector<int>> &picture) {
    int area = 0;
    queue<pii> bfs_q;
    visit[st_x][st_y] = true;
    bfs_q.push({ st_x, st_y });

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first;
        int curr_y = bfs_q.front().second;
        bfs_q.pop();
        area++;

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if ((nx >= 0 && nx < picture.size()) && (ny >= 0 && ny < picture[0].size())) {
                if (!visit[nx][ny] && picture[nx][ny] == target) {
                    bfs_q.push({ nx, ny });
                    visit[nx][ny] = true;
                }
            }
        }
    }

    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            visit[i][j] = 0;

    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[0].size(); j++) {
            if (!visit[i][j] && picture[i][j] != 0) {
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, picture[i][j], picture));
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
