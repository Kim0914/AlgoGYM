#include <iostream>
#include <algorithm>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, tomato[1001][1001], visited[1001][1001];
queue<pair<int,int> > q;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void ans(){
    int maxi = 0;
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            if(tomato[i][j] == 0) {
                cout << -1;
                return;
            }
            maxi = max(tomato[i][j], maxi);
        }
    }
    cout << maxi-1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) q.push(make_pair(i,j));
        }
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(tomato[y][x] >= 1 && visited[y][x] == 0){
            visited[y][x] = 1;
            FOR(l,0,4){
                int nx = x+dx[l];
                int ny = y+dy[l];

                if(nx<1 || ny<1 || nx>M || ny>N) continue;
                if(tomato[ny][nx] == 0) {
                    tomato[ny][nx] = tomato[y][x]+1;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }

    ans();
    
    return 0;
}