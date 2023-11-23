#include <iostream>
#include <vector>
using namespace std;
#define MAX 99999999
vector<pair<pair<int, int>, int>> oper_list;
vector<int> oper_sequence;
int row = 0, col = 0, oper_num = 0, x = 0, y = 0, len = 0, answer = MAX;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int origin_matrix[51][51], copied_matrix[51][51];
bool visit[6];
void calculate_matrix() {
    for (int i = 1; i <= row; i++) {
        int rowsum = 0;
        for (int j = 1; j <= col; j++)
            rowsum += copied_matrix[i][j];

        answer = min(answer, rowsum);
    }
}

void copy_matrix() {
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            copied_matrix[i][j] = origin_matrix[i][j];
}

void rotate_matrix(int oper_idx) {
    int std_x = oper_list[oper_idx].first.first;
    int std_y = oper_list[oper_idx].first.second;
    int std_length = oper_list[oper_idx].second;

    for (int i = 0; i < std_length; i++) {
        // 깊이 만큼 반복해야 한다.
        int inner_x = std_x - std_length + i ,inner_y = std_y - std_length + i;
        int start_pos = copied_matrix[inner_x][inner_y];

        int side = 0; // 변이 4개 아,왼,위,오(시계)
        while (side < 4) {
            int nx = inner_x + dx[side];
            int ny = inner_y + dy[side];

            if (nx == (std_x - std_length + i) && (ny == (std_y - std_length + i)))
                break;

            if ((nx >= (std_x - std_length + i) && nx <= (std_x + std_length - i)) && (ny >= (std_y - std_length + i) && ny <= (std_y + std_length - i))) {
                copied_matrix[inner_x][inner_y] = copied_matrix[nx][ny];
                // 시계방향으로 행렬을 돌림

                inner_x = nx;
                inner_y = ny;
            }
            else
                side++;
        }

        copied_matrix[std_x - std_length + i][(std_y - std_length + i) + 1] = start_pos;
        // 저장해둔 배열을 마지막 조각에 넣기
    }
}

void rotate_simulation() {
    for (int i = 0; i < oper_sequence.size(); i++)
        rotate_matrix(oper_sequence[i]);
}

void make_permutation(int depth) {
    if (depth == oper_num) {
        copy_matrix();
        rotate_simulation();
        calculate_matrix();

        return;
    }

    for (int i = 0; i < oper_num; i++) {
        if (!visit[i]) {
            visit[i] = true;
            oper_sequence.push_back(i);
            make_permutation(depth + 1);
            visit[i] = false;
            oper_sequence.pop_back();
        }
    }
}

int main(){
    cin >> row >> col >> oper_num;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> origin_matrix[i][j];

    for (int i = 0; i < oper_num; i++) {
        cin >> x >> y >> len;
        oper_list.push_back({ {x, y}, len });
    }

    for (int i = 0; i < oper_num; i++) {
        visit[i] = true;
        oper_sequence.push_back(i);
        make_permutation(1);
        visit[i] = false;
        oper_sequence.pop_back();
    }
    
    cout << answer;
    return 0;
}
