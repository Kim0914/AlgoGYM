#include <string>
#include <vector>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> lines[31];
    vector<int> s;
    int answer = 0;

    for(int i=board.size()-1;i>=0;i--){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]!=0) lines[j+1].push_back(board[i][j]);
        }
    }

    for(int move: moves){
        if(lines[move].empty()) continue;
        if(!s.empty()){
            if(s.back() == lines[move].back()) {
                answer+=2;
                s.pop_back();
            }
            else s.push_back(lines[move].back());
        }
        else s.push_back(lines[move].back());
        lines[move].pop_back();
        
    }
    return answer;
}