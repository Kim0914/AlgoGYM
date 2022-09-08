#include <string>
#include <vector>
using namespace std;

int res_cnt = 0;
bool validate(vector<vector<int>> chess_board, vector<int> check, int row, int col) {
    int curr_depth = row + 1;

    if (check[col] == 0) {
        for (int i = 0; i < check.size(); i++) {
            if (i == col) continue;
            if (check[i] != 0) {
                if ((curr_depth - check[i]) == abs(col - i))
                    return false;
            }
        }

        return true;
    }
    else return false;
}

void backtrack(int n, int depth, vector<vector<int>>& chess_board, vector<bool>& visit, vector<int>& check) {
    if (depth == n) {
        res_cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visit[depth] && validate(chess_board, check, depth, i)) {
            visit[depth] = true;
            check[i] = depth + 1;
            chess_board[depth][i] = 5;
            backtrack(n, depth + 1, chess_board, visit, check);
            visit[depth] = false;
            check[i] = 0;
            chess_board[depth][i] = 0;
        }
    }
}

int solution(int n) {
    int answer = 0;

    vector<vector<int>> chess_board(n, vector<int>(n, 0));
    vector<bool> visit(n, 0);
    vector<int> check(n, 0);
    backtrack(n, 0, chess_board, visit, check);
    answer = res_cnt;

    return answer;
}
