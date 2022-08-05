#include <vector>
#include <algorithm>
using namespace std;

void DP_square(vector<vector<int>>& board, int& answer) {
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            if (board[i][j] == 1) {
                board[i][j] = min(board[i - 1][j], min(board[i - 1][j - 1], board[i][j - 1])) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0;

    if (board.size() == 1) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board.size(); j++)
                if (board[i][j] == 1) answer = 1;
    }
    else DP_square(board, answer);
    answer *= answer;
    return answer;
}
