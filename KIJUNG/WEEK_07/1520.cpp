#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int M,N;
int map[501][501];
int dp[501][501];
bool visit[501][501];
int basis[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

int dfs(int y, int x){
    if(x<1 || y<1 || x>N || y>M) return 0;
    if(dp[y][x] > 0 || visit[y][x]) return dp[y][x];

    visit[y][x] = true; //방문했는지 안 했는지 확인을 안 해주면 경로가 없는 것도 재탐색하기 때문에 시간이 오래 걸린다.

    FOR(i,0,4){
        if(map[y+basis[i][1]][x+basis[i][0]] > map[y][x]) {
            dp[y][x] += dfs(y+basis[i][1],x+basis[i][0]);
        }
    }
    return dp[y][x];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;

    FOR(i,1,M+1){
        FOR(j,1,N+1){
            cin >> map[i][j];
        }
    }

    dp[1][1] = 1;
    cout << dfs(M, N);
    
    return 0;
}