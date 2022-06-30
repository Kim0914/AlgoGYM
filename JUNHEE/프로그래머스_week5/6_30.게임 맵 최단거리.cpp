#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > maps)
{
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    int start_x = 0, start_y = 0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int x, y;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];int ny = y + dy[i];
            if((nx >= 0 && nx < maps.size()) && (ny >= 0 && ny < maps[0].size())){
                if(maps[nx][ny] == 1){
                    q.push(make_pair(nx,ny));
                    maps[nx][ny] = maps[x][y] + 1;
                }
            }
        }
    }
    
    
    if(maps[maps.size()-1][maps[0].size()-1] == 1) return -1;
    else return maps[maps.size()-1][maps[0].size()-1];
}
