#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 100000000

using namespace std;

int V, E, a, b, c, ans, dis[401][401];

int main(void){
    cin >> V >> E;

    FOR(i,1,V+1){
        FOR(j,1,V+1){
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }

    FOR(i,0,E){
        cin >> a >> b >> c;
        dis[a][b] = c;
    }

    FOR(k,1,V+1){
        FOR(i,1,V+1){
            FOR(j,1,V+1){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    ans = INF;
    FOR(i,1,V+1){   
        FOR(j,1,V+1){
            if(i!=j) ans = min(dis[i][j] + dis[j][i], ans);
        }
    }
    if(ans>=INF) ans = -1;
    cout << ans;

    return 0;
}

// 플로이드 워셜 알고리즘! 
// 중간값을 거치는 기준으로 범위에서의 최솟값을 갱신한다. 
// dp에서 큰 범위의 값을 구하기 위해 부분합을 이용하는 데 이것도 마찬가지이다.