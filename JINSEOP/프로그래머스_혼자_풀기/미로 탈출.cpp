#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<pair<int, int>, int>> bfs_q;
pair<int, int> start_point;
pair<int, int> lever_point;

void clear_visit(vector<vector<bool>>& visit) {
    for (int i = 0; i < visit.size(); i++)
        for (int j = 0; j < visit[0].size(); j++)
            visit[i][j] = false;
}

void clear_queue() {
    while (!bfs_q.empty())
        bfs_q.pop();
}

void find_start_and_lever(vector<string> maps) {
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S')
                start_point = { i, j };
            if (maps[i][j] == 'L')
                lever_point = { i, j };
        }
    }
}

int bfs(int x, int y, char dest_char, vector<string> maps, vector<vector<bool>>& visit) {
    bfs_q.push({ {x, y}, 0 });
    visit[x][y] = true;

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first.first;
        int curr_y = bfs_q.front().first.second;
        int curr_walk = bfs_q.front().second;
        bfs_q.pop();

        if (maps[curr_x][curr_y] == dest_char)
            return curr_walk;

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if ((nx >= 0 && nx < maps.size()) && (ny >= 0 && ny < maps[0].size())) {
                if (!visit[nx][ny] && maps[nx][ny] != 'X') {
                    visit[nx][ny] = true;
                    bfs_q.push({ { nx, ny }, curr_walk + 1});
                }
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));

    find_start_and_lever(maps);
    int first_step = bfs(start_point.first, start_point.second, 'L', maps, visit);

    if (first_step == -1) return -1;
    answer += first_step;

    clear_visit(visit);
    clear_queue();

    int second_step = bfs(lever_point.first, lever_point.second, 'E', maps, visit);

    if (second_step == -1) return -1;
    answer += second_step;

    return answer;
}

// Queue를 비울 것을 왜 생각을 못했니
