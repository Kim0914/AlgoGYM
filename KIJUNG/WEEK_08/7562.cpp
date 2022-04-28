#include <iostream>
#include <queue>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, I, iY, iX, aY, aX; 
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
queue<pair<int,int> > q;

int main(void){
    cin >> T;
    FOR(l,0,T){
        int visited[301][301] = {0,};
        
        cin >> I >> iY >> iX >> aY >> aX;
        q.push(make_pair(iY,iX));
        visited[iY][iX] = 1;
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            FOR(i,0,8){
                int ny = y+dy[i];
                int nx = x+dx[i];

                if(nx<0 || ny < 0 || nx>=I || ny>=I) continue;
                if(visited[ny][nx] == 0){
                    q.push(make_pair(ny,nx));
                    visited[ny][nx] = visited[y][x]+1;
                }
            }
        }
        cout << visited[aY][aX] -1 << "\n";
    }

    return 0;
}