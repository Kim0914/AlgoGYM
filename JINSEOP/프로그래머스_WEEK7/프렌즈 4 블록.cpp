#include <string>
#include <vector>
using namespace std;

bool no_pop = true;
void init_map(vector<string>& copy_board, vector<string> board) {
    copy_board = board;
}

void can_pop(int st_x, int st_y, vector<string> copy_board, vector<string>& board) {
    char stand = copy_board[st_x][st_y];
    if (stand == '#') return;

    for (int i = st_x; i < st_x + 2; i++) {
        for (int j = st_y; j < st_y + 2; j++) {
            if (stand != copy_board[i][j] || copy_board[i][j] == '#') return;
        }
    }

    no_pop = false;
    for (int i = st_x; i < st_x + 2; i++)
        for (int j = st_y; j < st_y + 2; j++)
            board[i][j] = '#';
}

void pull_down(vector<string>& board) {
    int iter = 0;

    while (true) {
        if (iter >= board.size()) break;

        bool no_sharp = true;
        for (int i = 0; i < board.size()-1; i++) {
            if (board[i + 1][iter] == '#') {
                no_sharp = false;
                swap(board[i][iter], board[i + 1][iter]);
            }
        }

        if (board[0][iter] == '#' || no_sharp) iter++;
    }
}

int count_blank(vector<string> board) {
    int cnt = 0;

    for (auto i : board) {
        for (auto k : i) 
            if (k == '#') cnt++;
    }

    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<string> copy_board;

    init_map(copy_board, board);

    while (true) {
        no_pop = true;

        for (int i = 0; i < m - 1; i++)
            for (int j = 0; j < n - 1; j++)
                can_pop(i, j, copy_board, board);

        pull_down(board);
        copy_board = board;

        if (no_pop) break;
    }

    answer = count_blank(board);
    return answer;
}
