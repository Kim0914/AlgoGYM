#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int checking[30][30];

void check(int row, int col, vector<deque<char>> board2){
    if(col+1>board2[row].size() || col+1>board2[row+1].size()) return;
    if(board2[row][col] == board2[row+1][col] &&
        board2[row][col] == board2[row][col+1] &&
        board2[row][col] == board2[row+1][col+1]){
            checking[row][col] = 1;
            checking[row+1][col] = 1;
            checking[row][col+1] = 1;
            checking[row+1][col+1] = 1;
        }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<deque<char>> board2;

    for(int i=0;i<n;i++){
        deque<char> tmp;
        for(int j=m-1;j>=0;j--){
            tmp.push_back(board[j][i]);
        }
        board2.push_back(tmp);
    }

    while(1){
        fill(&checking[0][0], &checking[29][30], 0);
        
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                check(i,j,board2);
            }
        }
        
        if(count(&checking[0][0], &checking[29][30], 1) == 0) break;
        answer += count(&checking[0][0], &checking[29][30], 1);
        
        for(int i=0;i<n;i++){
            int tmpSize = board2[i].size();
            for(int j=0;j<tmpSize;j++){
                if(checking[i][j] == 0) board2[i].push_back(board2[i].front());
                board2[i].pop_front();
            }
        }
    }

    return answer;
}