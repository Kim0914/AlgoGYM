#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bucket;
    
    int SIZE = board[0].size();
    
    for(int index : moves){
        
        int pick_num = 0;
        for(int i=0; i<SIZE; i++){
            if(board[i][index-1] > 0){
                pick_num = board[i][index-1];
                board[i][index-1] = 0;
                break;
            }
        }
        
        if (pick_num != 0){
            if(bucket.empty()){
                bucket.push(pick_num);
            }
               
            else{
                if(pick_num == bucket.top()){
                    bucket.pop();
                    answer += 2;
                }
                
                else{
                    bucket.push(pick_num);
                }
            }
            
        }
    }
    return answer;
}