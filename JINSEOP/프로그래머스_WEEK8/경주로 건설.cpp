#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define BIGNUM 10000000
#define STRAIGHT 100
#define CORNER 600

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int min_cost = BIGNUM , cost = 0;

void backtrack(int direction, int st_x, int st_y, int cost, vector<vector<int>> board, vector<vector<bool>>& visit) {
    if ((st_x == board.size() - 1) && (st_y == board.size() - 1)) {
        if (min_cost > cost) min_cost = cost;
        return;
    }

    if (min_cost < cost) return;

    for (int i = 0; i < 4; i++) {
        int nx = st_x + dx[i];
        int ny = st_y + dy[i];
        if ((nx >= 0 && nx < board.size()) && (ny >= 0 && ny < board.size())) {
            if (!visit[nx][ny] && board[nx][ny] == 0) {
                visit[nx][ny] = true;
                if (direction != i + 1 && direction != 9) {
                    backtrack(i + 1, nx, ny, cost + CORNER, board, visit);
                    visit[nx][ny] = false;
                }
                else {
                    backtrack(i + 1, nx, ny, cost + STRAIGHT, board, visit);
                    visit[nx][ny] = false;
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<bool>> visit(board.size(), vector<bool>(board.size(), 0));

    visit[0][0] = true;
    backtrack(9, 0, 0, 0, board, visit);

    answer = min_cost;
    return answer;
}
