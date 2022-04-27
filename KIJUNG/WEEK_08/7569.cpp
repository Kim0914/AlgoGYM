#include <iostream>
#include <algorithm>
#include <queue>
#include <array>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, H, tomato[101][101][101], visited[101][101][101];
queue<array<int,3> > q;
int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

void ans(){
    int maxi = 0;
    FOR(k,1,H+1){
        FOR(i,1,N+1){
            FOR(j,1,M+1){
                if(tomato[k][i][j] == 0) {
                    cout << -1;
                    return;
                }
                maxi = max(tomato[k][i][j], maxi);
            }
        }
    }
    
    cout << maxi-1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H;

    FOR(k,1,H+1){
        FOR(i,1,N+1){
            FOR(j,1,M+1){
                cin >> tomato[k][i][j];
                if(tomato[k][i][j] == 1){
                    array<int,3> arr = {k,i,j};
                    q.push(arr);
                } 
            }
        }
    }
    

    while(!q.empty()){
        int z = q.front().at(0);
        int y = q.front().at(1);
        int x = q.front().at(2);
        q.pop();

        if(tomato[z][y][x] >= 1 && visited[z][y][x] == 0){
            visited[z][y][x] = 1;
            FOR(l,0,6){
                int nz = z+dz[l];
                int nx = x+dx[l];
                int ny = y+dy[l];

                if(nx<1 || ny<1 || nz<1 || nx>M || ny>N || nz>H) continue;
                if(tomato[nz][ny][nx] == 0) {
                    tomato[nz][ny][nx] = tomato[z][y][x]+1;
                    array<int,3> arr = {nz,ny,nx};
                    q.push(arr);
                }
            }
        }
    }

    ans();
    
    return 0;
}