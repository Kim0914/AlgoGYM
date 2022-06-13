#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


bool check(int m, int n, int org_x, int org_y, vector<string> &board){

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    queue<tuple<int, int, bool> > q;
    q.push(make_tuple(org_x, org_y, false));
    
    char cmp = board[org_x][org_y];
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        bool flag = get<2>(q.front());
        q.pop();
    
    
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx == org_x && ny == org_y){
                continue;
            }
            
            if ((0<= nx && nx < m) && (0<= ny && ny < n)){
                if(board[nx][ny] == cmp){ // 같은 문자를 찾은 경우
                    board[nx][ny] = '.';
                    return true;
                }
                
                else{
                    if(board[nx][ny] == '.'){
                        if(nx == org_x || ny == org_y){ // 직선으로 이동할 수 있는 경우
                            q.push(make_tuple(nx, ny, flag));
                        }
                        
                        else{
                            if(flag == false){ // 방향전환을 한 번도 안한 경우, 전환
                                q.push(make_tuple(nx, ny, true)); 
                            }
                            
                            else{ // 방향전환을 한 경우인데, 직선으로 이동하는 경우이고, 한번 더 꺾지 않는 경우
                                if((nx == x || ny == y) && (nx != org_x && ny != org_y)){
                                    q.push(make_tuple(nx, ny, true)); 
                                }
                                else{
                                    continue;
                                }
                                
                            }
                        }
                    }
                    
                    else{ // *인 경우
                        continue;
                    }
                    
                }
            }
        }
    }
    return false;
}


string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<char> v;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if('A' <= board[i][j] && board[i][j] <= 'Z'){
                if(check(m, n, i, j, board)){
                    v.push_back(board[i][j]);
                    board[i][j] = '.';
                }
            }
        }
    }
    

    for(char c : v){
        cout << c << endl;
    }
    
    if(v.empty()){
        answer = "IMPOSSIBLE";
    }
    
    return answer;
}