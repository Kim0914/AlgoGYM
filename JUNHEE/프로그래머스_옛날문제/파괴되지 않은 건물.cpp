#include <string>
#include <vector>
#include <iostream>

using namespace std;

int acc_sum[1001][1001] = {0,};

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for(auto s : skill){
        int x1 = s[1];
        int y1 = s[2];
        int x2 = s[3];
        int y2 = s[4];
        int degree = s[5];
        if(s[0] == 1) degree *= -1;
        
        acc_sum[x1][y1] += degree;
        acc_sum[x2+1][y2+1] += degree;
        acc_sum[x1][y2+1] -= degree;
        acc_sum[x2+1][y1] -= degree;
    }
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            acc_sum[i][j + 1] += acc_sum[i][j];
        }
    }
    for(int i = 0; i < board[0].size(); i++){
        for(int j = 0; j < board.size(); j++){
            acc_sum[i + 1][j] += acc_sum[i][j];
        }
    }
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] + acc_sum[i][j] > 0) answer++;
        }
    }
    
    
    return answer;
}
