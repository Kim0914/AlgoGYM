#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 100000000

using namespace std;

int n, m, dis[101][101], before[101][101];

int lenTracking(int start, int end){
    int mid = before[start][end];
    if(mid == 0) return 0;
    else return 1 + lenTracking(start, mid) + lenTracking(mid, end);
}

void tracking(int start, int end){
    int mid = before[start][end];
    if(mid == 0) return;
    else {
        tracking(start, mid);
        cout << mid << " ";
        tracking(mid, end);
    }
}

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
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    before[i][j] = k;
                }
            }
        }
    }

    FOR(i,1,n+1){
        FOR(j,1,n+1){
            if(dis[i][j] == INF) dis[i][j] = 0;
            cout << dis[i][j]  << " ";
        }
        cout << "\n";
    }

    FOR(i,1,n+1){
        FOR(j,1,n+1){
            if(dis[i][j] == 0) cout << 0 << "\n";
            else{
                cout << lenTracking(i,j) + 2 << " ";
                cout << i << " ";
                tracking(i,j);
                cout << j << "\n";
            }
        }
    }

    return 0;
}