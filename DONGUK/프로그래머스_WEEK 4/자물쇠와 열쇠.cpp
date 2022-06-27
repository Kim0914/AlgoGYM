#include <string>
#include <vector>

using namespace std;

int keysize, locksize, boardsize;

void rotate(vector<vector<int>> &key){
    vector<vector<int>> tmp(keysize, vector<int>(keysize));
    
    for(int j=keysize-1; j>=0; j--){
        for(int i=0; i<keysize; i++){
            tmp[i][j] = key[keysize-j-1][i];
        }
    }
    
    key = tmp;
}

bool isKey(int x, int y, vector<vector<int>> key, vector<vector<int>> board){
    for(int i=x; i<x+keysize; i++){
        for(int j=y; j<y+keysize; j++){
            board[i][j] += key[i-x][j-y];
        }
    }
    
    for(int i=keysize-1; i<=boardsize-keysize; i++){
        for(int j=keysize-1; j<=boardsize-keysize; j++){
            if(board[i][j] == 1) continue;
            
            else return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    keysize = key.size();
    locksize = lock.size();
    
    boardsize = locksize + (keysize - 1)*2;
    vector<vector<int>> board(boardsize, vector<int>(boardsize, 0));
    
    for(int i=keysize-1; i<=boardsize - keysize; i++){
        for(int j=keysize-1; j<=boardsize - keysize; j++){
            board[i][j] = lock[i-keysize+1][j-keysize+1];
        }
    }
    
    for(int r=0; r<4; r++){
        for(int i=0; i<=boardsize-keysize; i++){
            for(int j=0; j<=boardsize-keysize; j++){
                if(isKey(i, j, key, board)){
                    answer = true;
                    return answer;
                }
            }
        }
        rotate(key);
        
    }
    
    return answer;
}