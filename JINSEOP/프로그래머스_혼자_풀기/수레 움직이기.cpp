#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define pii pair<int, int>
#define piii pair<pair<int, int>, int>
#define MAX 9999999

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool visit_red[4][4], visit_blue[4][4], red_fin = false, blue_fin = false;
pii red_start, blue_start, red_end, blue_end;
int backtrack_wagen(int red_x, int red_y, int blue_x, int blue_y, int stride, vector<vector<int>>& maze) {
    if (red_fin && blue_fin)
        return stride;
    int answer = MAX;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int red_nx = red_x + dx[i];
            int red_ny = red_y + dy[i];
            int blue_nx = blue_x + dx[j];
            int blue_ny = blue_y + dy[j];

            if (red_fin) {
                red_nx = red_end.first;
                red_ny = red_end.second;
            }
            if (blue_fin) {
                blue_nx = blue_end.first;
                blue_ny = blue_end.second;
            }

            if ((red_nx < 0 || red_nx >= maze.size()) || (red_ny < 0 || red_ny >= maze[0].size()))
                continue;
            if ((blue_nx < 0 || blue_nx >= maze.size()) || (blue_ny < 0 || blue_ny >= maze[0].size()))
                continue; // 미로 밖으로 나가버리는 경우 불가능
            if (maze[red_nx][red_ny] == 5 || maze[blue_nx][blue_ny] == 5)
                continue; // 둘 중 하나라도 장애물 만나는 경우 불가능
            if ((red_nx == blue_x && red_ny == blue_y) && (blue_nx == red_x && blue_ny == red_y))
                continue; // 둘의 자리가 바뀌는 경우
            if ((!red_fin && visit_red[red_nx][red_ny]) || (!blue_fin && visit_blue[blue_nx][blue_ny]))
                continue; // 도착 지점은 예외, 방문 이미 한 곳은 이동 불가
            if (red_nx == blue_nx && red_ny == blue_ny)
                continue; // 둘 동시에 동일한 칸으로 이동 불가능

            visit_red[red_nx][red_ny] = true;
            visit_blue[blue_nx][blue_ny] = true;
            if (red_nx == red_end.first && red_ny == red_end.second)
                 red_fin = true;
            if (blue_nx == blue_end.first && blue_ny == blue_end.second)
                 blue_fin = true;

            answer = min(answer, backtrack_wagen(red_nx, red_ny, blue_nx, blue_ny, stride + 1, maze));

            red_fin = false;
            blue_fin = false;
            visit_red[red_nx][red_ny] = false;
            visit_blue[blue_nx][blue_ny] = false;
        }
    }

    return answer;
}

int solution(vector<vector<int>> maze) {
    int answer = 0;

    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[0].size(); j++) {
            if (maze[i][j] == 1)
                red_start = { i, j };
            if (maze[i][j] == 2)
                blue_start = { i, j };
            if (maze[i][j] == 3)
                red_end = { i, j };
            if (maze[i][j] == 4)
                blue_end = { i, j };
        }
    }

    visit_red[red_start.first][red_start.second] = true;
    visit_blue[blue_start.first][blue_start.second] = true;
    answer = backtrack_wagen(red_start.first, red_start.second, blue_start.first, blue_start.second, 0, maze);

    return (answer == MAX) ? 0 : answer;
}
