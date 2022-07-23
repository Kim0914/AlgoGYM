#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[25][25];
int stored[25][25];
int dcol[5] = {0,0,1,0,-1};
int drow[5] = {0,1,0,-1,0};
int answer = 2000000000;

void dfs(int row, int col, int direction, int cost, vector<vector<int>> &board){
    if(row == board.size()-1 && col == board[0].size()-1){
        answer = min(cost,answer);
        return;
    }
    for(int i=1;i<5;i++){
        int nCost = 100;
        if(row+drow[i]<0 || row+drow[i]>board.size()-1 || col+dcol[i]<0 || col+dcol[i]>board[0].size()-1) continue;
        if(visited[row+drow[i]][col+dcol[i]] == 1) continue;
        if(board[row+drow[i]][col+dcol[i]] == 1) continue;
        if((direction == 1 && i%2 == 0) || (direction == 0 && i%2 == 1)) nCost += 500;
        if(stored[row+drow[i]][col+dcol[i]] + 300 < cost+nCost) continue;
        stored[row+drow[i]][col+dcol[i]] = cost+nCost;
        visited[row+drow[i]][col+dcol[i]] = 1;
        dfs(row+drow[i],col+dcol[i],i%2,cost+nCost,board);
        visited[row+drow[i]][col+dcol[i]] = 0;
    }
}

int solution(vector<vector<int>> board) {
    fill(&visited[0][0], &visited[24][25], 0);
    fill(&stored[0][0], &stored[24][25], 2000000000);
    stored[0][0]=0;
    visited[0][0]=1;
    dfs(0,0,2,0,board);
    return answer;
}