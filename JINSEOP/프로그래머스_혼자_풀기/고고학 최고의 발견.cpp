#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define pii pair<int, int> 

int dx[5] = { -1, 0, 1, 0, 0 };
int dy[5] = { 0, 1, 0, -1, 0 };
int sum = 0, min_rot_num = 999999999;
vector<int> rot_vec;
void turn_clockwise(int tar_x, int tar_y, vector<vector<int>> &tar_map, int row, int num) {
    for (int i = 0; i < 5; i++) {
        int nx = tar_x + dx[i];
        int ny = tar_y + dy[i];

        if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row))
            tar_map[nx][ny] = (tar_map[nx][ny] + num) % 4;
    }
}

bool check_unlock(int row, vector<vector<int>>& tar_map) {
    for (int i = 0; i < row; i++)
        if (tar_map[row - 1][i] != 0)
            return false;

    return true;
}

void dfs(vector<vector<int>> &tar_map, int depth) {
    if (depth == tar_map.size()) {
        int partial_sum = 0;
        // 이 부분에서 첫 줄 회전
        vector<vector<int>> copied_map = tar_map;
        for (int i = 0; i < rot_vec.size(); i++)
            turn_clockwise(0, i, copied_map, copied_map.size(), rot_vec[i]);

        // 여기부터 첫 줄 제외 다른 row들 돌려보기
        for (int i = 1; i < copied_map.size(); i++) {
            for (int j = 0; j < copied_map.size(); j++) {
                int prev_lock = copied_map[i - 1][j];
                if (!prev_lock)
                    continue;

                int rot_num = 4 - prev_lock;
                turn_clockwise(i, j, copied_map, copied_map.size(), rot_num);
                partial_sum += rot_num;
            }
        }

        if (check_unlock(copied_map.size(), copied_map))
            min_rot_num = min(min_rot_num, sum + partial_sum);

        return;
    }

    for (int i = 0; i < 4; i++) {
    // 우리는 0 1 2 3 중에서 값을 고르도록 한다.
        sum += i;
        rot_vec.push_back(i); // 회전 동작, 미리 돌리면 안됨
        dfs(tar_map, depth + 1);
        sum -= i;
        rot_vec.pop_back();
    }
}

int solution(vector<vector<int>> clockHands) {
    int answer = 0;
    int row = clockHands.size();
    int col = row;

    dfs(clockHands, 0);

    answer = min_rot_num;
    cout << answer;
    return answer;
}
