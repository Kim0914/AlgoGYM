#include <string>
#include <vector>
#include <iostream>
using namespace std;

pair<int, int> count_map(vector<string> board) {
    int o_cnt = 0, x_cnt = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O')
                o_cnt++;
            if (board[i][j] == 'X')
                x_cnt++;
        }
    }

    return { o_cnt, x_cnt };
}

bool check_cross(vector<string> board, char ox) {
    for (int i = 0; i < 3; i++) {
        if (board[1][i] == ox)
            if (board[0][i] == ox && board[2][i] == ox)
                return true;
        if (board[i][1] == ox)
            if (board[i][0] == ox && board[i][2] == ox)
                return true;
    }
    
    return false;
}

bool check_diagonal(vector<string> board, char ox) {
    if (board[1][1] == ox) {
        if (board[0][0] == ox && board[2][2] == ox)
            return true;
        if (board[0][2] == ox && board[2][0] == ox)
            return true;
    }

    return false;
}

bool read_o_map(vector<string> board) {
    if (check_cross(board, 'O')) return true;
    if (check_diagonal(board, 'O')) return true;

    return false;
}

bool read_x_map(vector<string> board) {
    if (check_cross(board, 'X')) return true;
    if (check_diagonal(board, 'X')) return true;

    return false;
}

int solution(vector<string> board) {
    pair<int, int> ox_cnt = count_map(board);

    if (ox_cnt.first - ox_cnt.second < 0 || ox_cnt.first - ox_cnt.second > 1)
        return 0;

    pair<bool, bool> winner = {read_o_map(board), read_x_map(board)};
    
    if (winner.first && winner.second)
        return 0;
    if (winner.first == 1) {
        if (ox_cnt.first <= ox_cnt.second)
            return 0;
    }
    if (winner.second == 1) {
        if (ox_cnt.first != ox_cnt.second)
            return 0;
    }

    return 1;
}
