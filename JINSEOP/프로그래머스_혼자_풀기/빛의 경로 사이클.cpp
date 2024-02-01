#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[501][501][16];
int refract(int dir, char angle) {
    if (angle == 'L') {
        if (dir == 0) return 3;
        if (dir == 1) return 0;
        if (dir == 2) return 1;
        if (dir == 3) return 2;
    }
    else {
        if (dir == 0) return 1;
        if (dir == 1) return 2;
        if (dir == 2) return 3;
        if (dir == 3) return 0;
    }
}

int dfs(int curr_x, int curr_y, int dir, int depth, vector<string> &grid) {
    if (visit[curr_x][curr_y][dir])
        return depth;
    visit[curr_x][curr_y][dir] = true;

    int n_dir = dir;
    if (grid[curr_x][curr_y] != 'S')
        n_dir = refract(dir, grid[curr_x][curr_y]);
    int nx = (curr_x + dx[n_dir]) % grid.size();
    int ny = (curr_y + dy[n_dir]) % grid[0].size();
    
    return dfs(nx, ny, n_dir, depth + 1, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            for (int dir = 0; dir < 4; dir++) {
                int cycle = dfs(i, j, dir, 0, grid);
                if (cycle)
                    answer.push_back(cycle);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}
