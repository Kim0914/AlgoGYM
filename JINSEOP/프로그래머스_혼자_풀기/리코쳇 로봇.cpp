#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 }; 
queue<pair<pair<int, int>, int>> bfs_q;
pair<int, int> start_point;
pair<int, int> goal_point;

void find_information(vector<string> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'R')
                start_point = { i, j };
            if (board[i][j] == 'G')
                goal_point = { i, j };
        }
    }

    bfs_q.push({ start_point, 0 });
}

int bfs(vector<string> board, vector<vector<bool>>& visit) {
    visit[start_point.first][start_point.second] = true;
    board[start_point.first][start_point.second] = '0';

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first.first;
        int curr_y = bfs_q.front().first.second;
        int walk = bfs_q.front().second;
        bfs_q.pop();

        if (curr_x == goal_point.first && curr_y == goal_point.second)
            return walk;

        for (int i = 0; i < 4; i++) {
            int nx = curr_x;
            int ny = curr_y;

            while (((nx >= 0 && nx < board.size()) && (ny >= 0 && ny < board[0].size())) && board[nx][ny] != 'D') {
                nx += dx[i];
                ny += dy[i];
            }

            nx -= dx[i];
            ny -= dy[i]; // D에서 한 칸 물러야 함

            if (visit[nx][ny] || (curr_x == nx && curr_y == ny))
                continue;

            visit[nx][ny] = true;
            bfs_q.push({ { nx, ny }, walk + 1});
        }
    }

    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

    find_information(board);
    answer = bfs(board, visit);


    return answer;
}
