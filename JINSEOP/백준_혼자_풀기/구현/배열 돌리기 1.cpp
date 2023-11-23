#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row = 0, col = 0, rot_num = 0;
int target_arr[300][300];

// 오른쪽, 아래, 왼쪽, 위
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void rotate_array(){
    int depth = min(row, col) / 2;

    for (int i = 0; i < depth; i++) {
        int start_pos = target_arr[i][i]; // 각 깊이 별 시작위치
        // 시작 위치가 마지막에 무조건 겹치게되니, 미리 저장해놨다가 넣어주기
      
        int x = i, y = i;
        int side = 0; // 변이 4개
        while (side < 4) {
            int nx = x + dx[side];
            int ny = y + dy[side];

            if (nx == i && ny == i)
                break;
            // 시작위치로 돌아오면 멈춰야함

            if ((i <= nx && nx < row - i) && (i <= ny && ny < col - i)) {
                // 차례대로 반시계 방향으로 돌림
                // 오른쪽으로 진행하며, 자신의 앞 칸에서 수를 당겨오는 것임
                // 왜? 반시계 방향으로 돌아야하니까!
                target_arr[x][y] = target_arr[nx][ny];
                x = nx;
                y = ny;
            }
            else
                side++;
        }

        target_arr[i + 1][i] = start_pos;
        // 제일 처음에 빼놓았던 시작위치를 다시 넣음
    }
}

int main(){
    cin >> row >> col >> rot_num;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> target_arr[i][j];

    while (rot_num--)
        rotate_array();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << target_arr[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
