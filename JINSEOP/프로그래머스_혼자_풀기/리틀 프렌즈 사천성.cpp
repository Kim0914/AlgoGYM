#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define pii pair<int, int>
#define pii2 pair<pair<int, int>, pair<int, int>>

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int pair_count = 0;
bool validate_pair(int st_x, int st_y, int goal_x, int goal_y, vector<string> board) {
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    queue<pii2> bfs_q;
    bfs_q.push({ {st_x, st_y}, {-1, 0} });
    // 좌표 x, y, 온 방향, 꺾은 횟수

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first.first;
        int curr_y = bfs_q.front().first.second;
        int curr_dir = bfs_q.front().second.first;
        int curr_turn = bfs_q.front().second.second;
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            if (curr_dir != -1 && abs(curr_dir - i) == 2)
                continue; // 시작 위치가 아닌데 역방향으로는 갈 수 없음
            // 이는 visit 배열이 없기 때문!!

            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            int nx_turn = 0;
            
            if (curr_dir != -1 && curr_dir != i)
                nx_turn = curr_turn + 1;
            else
                nx_turn = curr_turn;
            
            if ((nx >= 0 && nx < board.size()) && (ny >= 0 && ny < board[0].size())) {
                if (nx_turn > 1)
                    continue; // 2번 이상 꺾으면 안됨

                if(board[nx][ny] == '.')
                    bfs_q.push({ {nx, ny}, {i, nx_turn} });
                else
                    if (nx == goal_x && ny == goal_y)
                        return true;
                    // 제거할 수 있는 패를 찾았으면 종료
            }
        }
    }

    return false;
    // 패를 찾지 못함
}

void read_board(vector<string> board, vector<vector<pii>> &char_list) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
                char_list[board[i][j] - 'A'].push_back({ i, j });
                // 각 짝의 위치 저장
                pair_count++;
            }
        }
    }
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    
    vector<vector<pii>> char_list(26, vector<pii>());
    pair_count = 0;
    read_board(board, char_list);
    
    bool finded = true;
    while (finded) {
        finded = false;
        // 제거할 짝이 더 이상 없으면, 동작을 멈춰야 함

        for (int i = 0; i < 26; i++) {
            if (!char_list[i].empty()) {
                bool can_remove = validate_pair(char_list[i][0].first, char_list[i][0].second, char_list[i][1].first, char_list[i][1].second, board);
                if (can_remove) {
                    board[char_list[i][0].first][char_list[i][0].second] = '.';
                    board[char_list[i][1].first][char_list[i][1].second] = '.';
                    // 두 짝의 위치를 보드에서 빈 칸으로 표시해준다.
                    char_list[i].clear();
                    // 해당 짝 지워주기
                    pair_count -= 2;
                    answer += (i + 'A');
                    finded = true;
                    break;
                    // 해당 알파벳은 더 이상 탐색할 필요가 없으므로 탈출
                }
            }
        }
    }

    if (pair_count == 0)
        return answer;
    else
        return "IMPOSSIBLE";
}

int main() {
    solution(3, 3, { "DBA", "C*A", "CDB" });
    return 0;
}
