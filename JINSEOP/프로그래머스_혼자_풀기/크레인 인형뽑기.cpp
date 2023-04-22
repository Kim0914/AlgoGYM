#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

stack<int> basket;
void fill_machine(vector<vector<int>> board, vector<queue<int>> &real_machine) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][i] != 0)
                real_machine[i].push(board[j][i]);
        }
    }
}

int play_game(vector<int> moves, vector<queue<int>>& real_machine) {
    int answer = 0;

    for (int i : moves) {
        if (!real_machine[i - 1].empty()) {
            if (!basket.empty() && (basket.top() == real_machine[i - 1].front())) {
                real_machine[i - 1].pop();
                basket.pop();
                answer++;
            }
            else {
                basket.push(real_machine[i - 1].front());
                real_machine[i - 1].pop();
            }
        }
    }

    return answer * 2;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<queue<int>> real_machine(board.size(), queue<int>());

    fill_machine(board, real_machine);
    return play_game(moves, real_machine);
}
