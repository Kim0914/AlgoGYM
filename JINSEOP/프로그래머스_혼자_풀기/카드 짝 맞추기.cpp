#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> permutation, duplicated_permutation, card_vec;
vector<pair<int, int>> card_pos[7];
bool per_visit[7];
unordered_map<int, bool> duplication_preventer;
int do_mahjong(int st_x, int st_y, int finded, int curr_card, int curr_idx, vector<vector<int>> &target_board) {
    if (finded == 2)
        return 0;
    // 두 장의 카드를 모두 찾았으면 이동 X

    queue<pair<pair<int, int>, int>> bfs_q;
    bool board_visit[4][4] = { false, };
    // 지역 변수는 반드시 초기화해줄 것!!!
    board_visit[st_x][st_y] = true;
    bfs_q.push({ { st_x, st_y }, 0 });
    // 시작 위치, 현재 이동 거리

    int goal_x = 0, goal_y = 0;
    if (finded == 0) {
        goal_x = card_pos[curr_card][curr_idx].first;
        goal_y = card_pos[curr_card][curr_idx].second;
    }
    else {
        goal_x = card_pos[curr_card][!curr_idx].first;
        goal_y = card_pos[curr_card][!curr_idx].second;
    } // 시작 위치와 카드의 위치는 다르다.
    // 따라서 우리가 현재 목표로 하는 카드의 위치를 찾아야 한다.

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first.first;
        int curr_y = bfs_q.front().first.second;
        int curr_move = bfs_q.front().second;
        bfs_q.pop();

        if (curr_x == goal_x && curr_y == goal_y) {
            target_board[curr_x][curr_y] = 0;
            curr_move += do_mahjong(curr_x, curr_y, finded + 1, curr_card, curr_idx, target_board);
            // 재귀적 동작은 자신의 카드 쌍을 찾는 동작이다.
            return curr_move;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if ((nx >= 0 && nx < 4) && (ny >= 0 && ny < 4)) {
                cout << board_visit[nx][ny] << '\n';
                if (!board_visit[nx][ny]) {
                    board_visit[nx][ny] = true;
                    bfs_q.push({ {nx, ny}, curr_move + 1});
                }
            }
        } // 여기는 한 칸씩 움직일 때의 경우

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            while (true) {
                if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
                    nx -= dx[i];
                    ny -= dy[i];
                    break; // 중간에 카드가 없으면 마지막 칸으로
                }

                if (target_board[nx][ny])
                    break; // 중간에 카드가 있으면 중지

                nx += dx[i];
                ny += dy[i];
            }

            if (!board_visit[nx][ny]) {
                board_visit[nx][ny] = true;
                bfs_q.push({ {nx, ny}, curr_move + 1 });
            }
        } // 여기는 Ctrl을 이용해 움직이는 경우
    }
}

void make_duplicated_permutation(int depth, int r, int c, vector<vector<int>> board, int &answer) {
    if (depth == card_vec.size()) {
        int total_move = 0;
        int start_x = r;
        int start_y = c;

        vector<vector<int>> copied_board = board;
        for (int i = 0; i < card_vec.size(); i++) {
            int curr_card = permutation[i];
            int curr_idx = duplicated_permutation[i];
            // 해당 부분은 1번을 먼저 뒤집을 지? 2번을 먼저 뒤집을 지?
            total_move += do_mahjong(start_x, start_y, 0, curr_card, curr_idx, copied_board);

            start_x = card_pos[curr_card][!curr_idx].first;
            start_y = card_pos[curr_card][!curr_idx].second;
            // 마지막 찾은 카드 위치가 새로운 시작 위치가 되어야 한다.
            // !curr_idx가 되는 이유는 1번 카드에서 시작하면 다른 1번 카드에서 끝나기 때문!
        }

        answer = min(answer, total_move);
        return;
    }

    for (int i = 0; i < 2; i++) {
        duplicated_permutation.push_back(i);
        make_duplicated_permutation(depth + 1, r, c, board, answer);
        duplicated_permutation.pop_back();
    }
}

void make_permutation(int depth, int r, int c, vector<vector<int>> board, int &answer) {
    if (depth == card_vec.size()) {
        make_duplicated_permutation(0, r, c, board, answer);
        return;
    }

    for (int i = 0; i < card_vec.size(); i++) {
        if (!per_visit[i]) {
            permutation.push_back(card_vec[i]);
            per_visit[i] = true;
            make_permutation(depth + 1, r, c, board, answer);
            permutation.pop_back();
            per_visit[i] = false;
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 999999999;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] && !duplication_preventer[board[i][j]]) {
                card_vec.push_back(board[i][j]);
                duplication_preventer[board[i][j]] = true;
            }
        }
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j])
                card_pos[board[i][j]].push_back({i, j});
    // 카드 위치를 저장해야 이후 거리 계산 가능

    make_permutation(0, r, c, board, answer);
    // 카드를 제거할 순서를 정한다.
    
    // 마지막에 카드 수 * 2를 저장함은, Enter를 누르는 횟수이다.
    return answer + (card_vec.size() * 2);
}

int main() {
    solution({ {3,0,0,2}, {0,0,1,0}, {0,1,0,0}, {2,0,0,3} }, 0, 1);
    return 0;
}
