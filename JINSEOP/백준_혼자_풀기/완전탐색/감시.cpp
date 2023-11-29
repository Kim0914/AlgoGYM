#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row = 0, col = 0, answer = 999999999;
int office[8][8], copied_office[8][8];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> cctv_list;
vector<int> direction_list;
void copy_office() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            copied_office[i][j] = office[i][j];
}

void draw(int x, int y, int direction){
    if ((x >= 0 && x < row) && (y >= 0 && y < col)) {
        if (office[x][y] != 6) {
            if (office[x][y] == 0)
                copied_office[x][y] = -9; // 가시 범위
            draw(x + dx[direction], y + dy[direction], direction);
        }
    }
}

void draw_range(pair<int, int>& start_pos, int direction) {
    int kind_of_cctv = office[start_pos.first][start_pos.second];
    // 현재 어떤 종류의 CCTV를 보고있는지?

    if (kind_of_cctv == 1) {
        draw(start_pos.first + dx[direction], start_pos.second + dy[direction], direction);
    }
    if (kind_of_cctv == 2) {
        draw(start_pos.first + dx[direction], start_pos.second + dy[direction], direction);
        draw(start_pos.first + dx[(direction + 2) % 4], start_pos.second + dy[(direction + 2) % 4], ((direction + 2) % 4));
    }
    if (kind_of_cctv == 3) {
        for(int i = 0; i < 2; i++)
            draw(start_pos.first + dx[(direction + i) % 4], start_pos.second + dy[(direction + i) % 4], (direction + i) % 4);
    }
    if (kind_of_cctv == 4) {
        for (int i = 0; i < 3; i++)
            draw(start_pos.first + dx[(direction + i) % 4], start_pos.second + dy[(direction + i) % 4], (direction + i) % 4);
    }
    if (kind_of_cctv == 5) {
        for (int i = 0; i < 4; i++)
            draw(start_pos.first + dx[(direction + i) % 4], start_pos.second + dy[(direction + i) % 4], (direction + i) % 4);
    }
}

int calculate_blind_spot() {
    int cnt = 0;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (copied_office[i][j] == 0)
                cnt++;

    return cnt;
}

void backtrack(int depth, int direction) {
    if (depth >= cctv_list.size()) {
        copy_office();
        for (int i = 0; i < cctv_list.size(); i++)
            draw_range(cctv_list[i], direction_list[i]);

        answer = min(answer, calculate_blind_spot());
        return;
    }

    for (int i = 0; i < 4; i++) {
        // 각 깊이 별로 선택되는 방향을 의미한다.
        direction_list.push_back(i);
        backtrack(depth + 1, i);
        direction_list.pop_back();
    }
}

int main(){
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> office[i][j];
            if (office[i][j] != 0 && office[i][j] != 6)
                cctv_list.push_back({ i, j });
            // CCTV 위치 저장
        }
    }

    for (int i = 0; i < 4; i++) {
        direction_list.push_back(i);
        backtrack(1, i);
        direction_list.pop_back();
    }
    
    cout << answer;
    return 0;
}
