#include <iostream>
#include <vector>
using namespace std;

int MOD = 20170805, cnt = 0;
int dx[4] = { 0, 1 };
int dy[4] = { 1, 0 };
void backtrack(int x, int y, int past, vector<vector<int>> city_map, vector<vector<bool>>& visit) {
    if ((x == city_map.size() - 1) && (y == city_map[0].size() - 1)) {
        cnt++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (city_map[x][y] == 2)
            if (i + 1 != past && past != 9) continue;
    }

        int nx = x + dx[i];
        int ny = y + dy[i];
        if ((nx >= 0 && nx < city_map.size()) && (ny >= 0 && ny < city_map[0].size())) {
            if (!visit[nx][ny] && city_map[nx][ny] != 1) {
                visit[nx][ny] = true;
                backtrack(nx, ny, i + 1, city_map, visit);
                visit[nx][ny] = false;
            }
        }
    }
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    vector<vector<bool>> visit(m, (vector<bool>(n, 0)));
    backtrack(0, 0, 9, city_map, visit);

    answer = cnt % 20170805;
    return answer;
}
