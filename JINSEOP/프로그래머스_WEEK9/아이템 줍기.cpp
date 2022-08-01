#include <string>
#include <vector>
#include <queue>
using namespace std;

int maps[110][110];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> bfs_q;
void draw_map(vector<vector<int>> rectangle) {
    for (int i = 0; i < rectangle.size(); i++)
        for (int j = 0; j < rectangle[0].size(); j++)
            rectangle[i][j] *= 2; // 도대체 이런 생각은 어떻게 하나 
        
    for (int outer = 0; outer < rectangle.size(); outer++) {
        for (int i = rectangle[outer][0]; i <= rectangle[outer][2]; i++) {
            maps[rectangle[outer][1]][i] = 1;
        }
        for (int i = rectangle[outer][1]; i <= rectangle[outer][3]; i++) {
            maps[i][rectangle[outer][0]] = 1;
        }
        for (int i = rectangle[outer][2]; i >= rectangle[outer][0]; i--) {
            maps[rectangle[outer][3]][i] = 1;
        }
        for (int i = rectangle[outer][3]; i >= rectangle[outer][1]; i--) {
            maps[i][rectangle[outer][2]] = 1;
        }
    }

    for (int outer = 0; outer < rectangle.size(); outer++) {
        for (int i = rectangle[outer][1] + 1; i < rectangle[outer][3]; i++)
            for (int j = rectangle[outer][0] + 1; j < rectangle[outer][2]; j++)
                maps[i][j] = 0;
    }
}

void bfs(int st_x, int st_y, int itemX, int itemY) {
    bfs_q.push({ st_y, st_x });

    while (!bfs_q.empty()) {
        int y = bfs_q.front().first;
        int x = bfs_q.front().second;
        bfs_q.pop();

        if (x == itemX && y == itemY) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (maps[ny][nx] == 1) {
                bfs_q.push({ ny, nx });
                maps[ny][nx] = maps[y][x] + 1;
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2; // 이 생각을 어떻게 할까?

    draw_map(rectangle);
    bfs(characterX, characterY, itemX, itemY);

    answer = maps[itemY][itemX] / 2;
    return answer;
}

// 컴퓨터 고치면 블로그에 풀이 작성하기.
