#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[5][5];
int backtrack(int curr_x, int curr_y, int con_x, int con_y, vector<vector<int>> &board) {
    if (visit[curr_x][curr_y])
        return 0;
    // 현재 진행하는 플레이어가 밟은 발판이 사라졌으면 중단
    int result = 0;

    for (int i = 0; i < 4; i++) {
        int nx = curr_x + dx[i];
        int ny = curr_y + dy[i];
        // 다음 방향 검사

        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
            continue;
        if (visit[nx][ny] || !board[nx][ny])
            continue; // 이미 없어진 발판으로는 갈 수 없음

        visit[curr_x][curr_y] = true;
        // 플레이어가 지나간 곳! 발판 없애기
        int curr_turn = backtrack(con_x, con_y, nx, ny, board) + 1;
        // 상대편의 위치를 다음 매개변수로 넘긴다.
        // 이는 상대편의 턴으로 넘어갔음을 의미, 완료시 (턴 + 1)을 반환한다
        visit[curr_x][curr_y] = false;

        // 이 아랫부분이 이번 풀이의 핵심이다.
        // Case 1. 저장된 턴은 패배, 새로 계산된 턴은 승리인 경우
        if (result % 2 == 0 && curr_turn % 2 == 1)
            result = curr_turn; // 새로 계산된 턴으로 갱신해야 함
        // Case 2. 저장된 턴도 패배, 새로 계산된 턴도 패배인 경우
        else if (result % 2 == 0 && curr_turn % 2 == 0)
            result = max(result, curr_turn); // 최대한 늦게 져야 함
        // Case 3. 저장된 턴도 승리, 새로 계산된 턴도 승리인 경우
        else if (result % 2 == 1 && curr_turn % 2 == 1)
            result = min(result, curr_turn); // 최대한 빨리 이겨야 함
    }

    return result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    return backtrack(aloc[0], aloc[1], bloc[0], bloc[1], board);
}
