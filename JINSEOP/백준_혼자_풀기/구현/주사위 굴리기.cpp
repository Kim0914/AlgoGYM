#include <iostream>
using namespace std;

int row = 0, col = 0, st_x = 0, st_y = 0, cmds = 0;
int virtual_dice[7], roads[20][20], cmd_list[1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void roll_east() {
    int d_top, d_north, d_east, d_west, d_south, d_bottom;
    d_top = virtual_dice[1], d_north = virtual_dice[2], d_east = virtual_dice[3];
    d_west = virtual_dice[4], d_south = virtual_dice[5], d_bottom = virtual_dice[6];

    virtual_dice[1] = d_west;
    virtual_dice[4] = d_bottom;
    virtual_dice[6] = d_east;
    virtual_dice[3] = d_top;
}

void roll_west() {
    int d_top, d_north, d_east, d_west, d_south, d_bottom;
    d_top = virtual_dice[1], d_north = virtual_dice[2], d_east = virtual_dice[3];
    d_west = virtual_dice[4], d_south = virtual_dice[5], d_bottom = virtual_dice[6];

    virtual_dice[4] = d_top;
    virtual_dice[6] = d_west;
    virtual_dice[3] = d_bottom;
    virtual_dice[1] = d_east;
}

void roll_south() {
    int d_top, d_north, d_east, d_west, d_south, d_bottom;
    d_top = virtual_dice[1], d_north = virtual_dice[2], d_east = virtual_dice[3];
    d_west = virtual_dice[4], d_south = virtual_dice[5], d_bottom = virtual_dice[6];

    virtual_dice[1] = d_south;
    virtual_dice[2] = d_top;
    virtual_dice[6] = d_north;
    virtual_dice[5] = d_bottom;
}

void roll_north() {
    int d_top, d_north, d_east, d_west, d_south, d_bottom;
    d_top = virtual_dice[1], d_north = virtual_dice[2], d_east = virtual_dice[3];
    d_west = virtual_dice[4], d_south = virtual_dice[5], d_bottom = virtual_dice[6];

    virtual_dice[5] = d_top;
    virtual_dice[1] = d_north;
    virtual_dice[2] = d_bottom;
    virtual_dice[6] = d_south;
}

void roll_dice(int direction) {
    switch (direction)
    {
    case 1:
        roll_east();
        break;
    case 2:
        roll_west();
        break;
    case 3:
        roll_north();
        break;
    case 4:
        roll_south();
        break;
    }
}

void simulate() {
    int curr_x = st_x;
    int curr_y = st_y;

    for (int i = 0; i < cmds; i++) {
        int nx = curr_x + dx[cmd_list[i] - 1];
        int ny = curr_y + dy[cmd_list[i] - 1];

        if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
            roll_dice(cmd_list[i]);
            // 주사위도 굴려야 함
            if (roads[nx][ny] == 0)
                // 0이면 주사위의 아랫면이 칸에 복사된다.
                roads[nx][ny] = virtual_dice[6];
            else {
                // 0이 아니면 칸의 수가 주사위의 밑면에 복사된다.
                virtual_dice[6] = roads[nx][ny];
                roads[nx][ny] = 0;
            }

            cout << virtual_dice[1] << '\n';
            // 윗면 출력

            curr_x = nx;
            curr_y = ny;
            // 현재 위치를 바꿔줘야 함
        }
    }

}

int main(){
    cin >> row >> col >> st_x >> st_y >> cmds;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> roads[i][j];

    for (int i = 0; i < cmds; i++)
        cin >> cmd_list[i];

    simulate();
    return 0;
}
