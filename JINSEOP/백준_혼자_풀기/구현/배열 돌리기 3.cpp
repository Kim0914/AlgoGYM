#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row = 0, col = 0, oper_num = 0, oper;
int origin_matrix[100][100], copied_matrix[100][100];
void copy_to_origin() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            origin_matrix[i][j] = copied_matrix[i][j];
}

void flip_up() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            copied_matrix[(row - 1) - i][j] = origin_matrix[i][j];
}

void flip_right() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            copied_matrix[i][(col - 1) - j] = origin_matrix[i][j];
}

void rotate_clockwise() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            copied_matrix[j][(row - 1) - i] = origin_matrix[i][j];

    
    int temp = 0;
    temp = row;
    row = col;
    col = temp;
}

void rotate_counterclockwise() {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            copied_matrix[(col - 1) - j][i] = origin_matrix[i][j];


    int temp = 0;
    temp = row;
    row = col;
    col = temp;
}

void group_rotate_clockwise() {
    int group_one_x = 0;
    int group_one_y = 0;

    int group_two_x = 0;
    int group_two_y = col / 2;

    int group_three_x = row / 2;
    int group_three_y = col / 2;

    int group_four_x = row / 2;
    int group_four_y = 0;

    for (int i = group_one_x; i < group_four_x; i++)
        for (int j = group_one_y; j < group_two_y; j++)
            copied_matrix[i][j + group_two_y] = origin_matrix[i][j];
    // 1그룹 -> 2그룹
    for (int i = group_two_x; i < group_three_x; i++)
        for (int j = group_two_y; j < col; j++)
            copied_matrix[i + group_three_x][j] = origin_matrix[i][j];
    // 2그룹 -> 3그룹
    for (int i = group_three_x; i < row; i++)
        for (int j = group_three_y; j < col; j++)
            copied_matrix[i][j - group_three_y] = origin_matrix[i][j];
    // 3그룹 -> 4그룹
    for (int i = group_four_x; i < row; i++)
        for (int j = group_four_y; j < group_two_y; j++)
            copied_matrix[i - group_four_x][j] = origin_matrix[i][j];
    // 4그룹 -> 1그룹
}

void group_rotate_counterclockwise() {
    int group_one_x = 0;
    int group_one_y = 0;

    int group_two_x = 0;
    int group_two_y = col / 2;

    int group_three_x = row / 2;
    int group_three_y = col / 2;

    int group_four_x = row / 2;
    int group_four_y = 0;

    for (int i = group_one_x; i < group_four_x; i++)
        for (int j = group_one_y; j < group_two_y; j++)
            copied_matrix[i + group_four_x][j] = origin_matrix[i][j];
    // 1그룹 -> 4그룹
    for (int i = group_four_x; i < row; i++)
        for (int j = group_four_y; j < group_two_y; j++)
            copied_matrix[i][j + group_three_y] = origin_matrix[i][j];
    // 4그룹 -> 3그룹
    for (int i = group_three_x; i < row; i++)
        for (int j = group_three_y; j < col; j++)
            copied_matrix[i - group_three_x][j] = origin_matrix[i][j];
    // 3그룹 -> 2그룹
    for (int i = group_two_x; i < group_three_x; i++)
        for (int j = group_two_y; j < col; j++)
            copied_matrix[i][j - group_two_y] = origin_matrix[i][j];
    // 2그룹 -> 1그룹
}

// 오른쪽, 아래, 왼쪽, 위
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(){
    cin >> row >> col >> oper_num;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> origin_matrix[i][j];

    for (int i = 0; i < oper_num; i++) {
        cin >> oper;
        switch (oper)
        {
        case 1:
            flip_up();
            break;
        case 2:
            flip_right();
            break;
        case 3:
            rotate_clockwise();
            break;
        case 4:
            rotate_counterclockwise();
            break;
        case 5:
            group_rotate_clockwise();
            break;
        case 6:
            group_rotate_counterclockwise();
            break;
        }

        copy_to_origin();
        // 회전한 배열을 원래 배열로 옮겨야 함
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << origin_matrix[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
