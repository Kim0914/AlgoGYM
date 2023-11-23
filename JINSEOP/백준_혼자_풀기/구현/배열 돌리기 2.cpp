#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row = 0, col = 0, rot_num = 0;
int target_arr[300][300];

// 오른쪽, 아래, 왼쪽, 위
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void rotate_array(int start, int cells){
    int rotation_count = rot_num % cells;
    // 전체 전진 횟수는 칸 수 마다 반복된다.

    for (int i = 0; i < rotation_count; i++) {
        // 시작 위치가 i가 아닌 start로 바뀐다.
        // 왜? 처음엔 깊이가 for문의 기준이었지만,
        // 지금은 각 깊이별로 몇 회 전진할 것인지가 기준이기 때문.
        int start_pos = target_arr[start][start]; 
        // 각 깊이 별 시작위치
        int x = start, y = start;
        int side = 0; // 변이 4개
        while (side < 4) {
            int nx = x + dx[side];
            int ny = y + dy[side];

            if (nx == start && ny == start)
                break;

            if ((start <= nx && nx < row - start) && (start <= ny && ny < col - start)) {
                // 차례대로 반시계 방향으로 돌림
                target_arr[x][y] = target_arr[nx][ny];
                x = nx;
                y = ny;
            }
            else
                side++;
        }

        target_arr[start + 1][start] = start_pos;
        // 제일 처음에 빼놓았던 시작위치를 다시 넣음
    }
}

int main(){
    cin >> row >> col >> rot_num;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> target_arr[i][j];

    int depth = min(row, col) / 2;
    int inner_row = row, inner_col = col;
    // 굳이 R회 전진을 직접 시킬 필요가 없다.
    // R의 최대값이 10^9이라, 시간초과가 발생한다.
    // 박스별로 전진해야 하는 칸 수를 각각 구해서 전진 시키자.

    for (int i = 0; i < depth; i++) {
        // 2*가로 + 2*세로 - 4인 이유는 겹치는 4개의 모서리를 빼기 때문
        rotate_array(i, 2*inner_row + 2*inner_col - 4);
        inner_row -= 2; inner_col -= 2;
        // 양 모서리가 두 칸씩 줄어든다.
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << target_arr[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
