#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
vector<pair<int,int>> list(901);
vector<string> fix(int m, int n, vector<string> board){
    for(int i = 0; i < n; i++){
         for(int j = m - 1; j >= 0; j--){
             if(board[j][i] == ' '){
                 for(int k = j; k >= 0; k--){
                     if(board[k][i] != ' '){
                         board[j][i] = board[k][i];
                         board[k][i] = ' ';
                         break;
                     }
                 }
             }
         }
    }
    return board;
}
vector<string> erase(vector<string> board, int cnt){
    int x,y,nx,ny;
    int dx[4] = {0,0,1,1};
    int dy[4] = {0,1,0,1};
    for(int i = 0; i < cnt; i++){
        x = list[i].first;
        y = list[i].second;
        for(int j = 0; j < 4; j++){
            nx = x + dx[j]; ny = y + dy[j];
            if(board[nx][ny] != ' '){
                board[nx][ny] = ' ';
                answer++;
            }
        }
    }
    return board;
}
int search(int m, int n, vector<string> board){
    int cnt = 0;
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(board[i][j] == ' ') continue;
            if(board[i][j] == board[i+1][j] && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j+1]){
                list[cnt] = make_pair(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}
int solution(int m, int n, vector<string> board) {
    
    while(true){
        int cnt = search(m,n,board);
        if(cnt == 0) break;
        board = erase(board, cnt);
        board = fix(m,n,board);
        cout << cnt << endl;
        for(auto i : list){
            if(i.first != 0 || i.second != 0){
                cout << i.first << " " << i.second << endl;
            }
        }
    }
    return answer;
}
