#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 100000000

using namespace std;

int n, m, dis[101][101];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    FOR(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
    }

    FOR(k,1,n+1){
        FOR(i,1,n+1){
            FOR(j,1,n+1){
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }

    FOR(i,1,n+1){
        FOR(j,1,n+1){
            if(dis[i][j] == INF) cout << 0 << " ";
            else cout << dis[i][j]  << " ";
        }
        cout << "\n";
    }

    return 0;
}

//플로이드 워셜 알고리즘