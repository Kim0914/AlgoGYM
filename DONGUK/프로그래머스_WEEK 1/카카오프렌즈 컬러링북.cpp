#include <vector>
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
int visited[101][101] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int bfs(int i, int j, int m, int n, vector<vector<int>> picture){
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        int val = picture[x][y];
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if ((0 <= nx && nx < m) && (0 <= ny && ny < n)){
                if (visited[nx][ny] == 0 && picture[nx][ny] == val){
                    cnt += 1;
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
    }
    return cnt;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    fill(visited[0], visited[101], 0);
    
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (picture[i][j] != 0 && visited[i][j] == 0){
                // cout << i << " " <<  j << endl;
                number_of_area += 1;
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, m, n, picture));
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}