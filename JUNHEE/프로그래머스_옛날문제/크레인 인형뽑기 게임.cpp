#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> boards;
    for(int i = 0; i < board.size(); i++){
        stack<int> temp;
        for(int j = board.size() - 1; j >= 0; j--){
            if(board[j][i] == 0) continue;
            else temp.push(board[j][i]);
        }
        boards.push_back(temp);
    }
    stack<int> box;
    for(int i = 0; i < moves.size(); i++){
        if(!box.empty() && !boards[moves[i]-1].empty() &&
           box.top() == boards[moves[i]-1].top()){
            box.pop(); boards[moves[i]-1].pop();
            answer += 2;
        }
        else if(!boards[moves[i]-1].empty()){
            box.push(boards[moves[i]-1].top());
            boards[moves[i]-1].pop();
        }
    }
    return answer;
}
