#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M;
int m[101];
int cost[101];
int dp[101][10002];


int main(void){
    cin >> N >> M;
    FOR(i,1,N+1){
        cin >> m[i];
    }

    FOR(i,1,N+1){
        cin >> cost[i];
    }

    FOR(i,1,N+1){
        FOR(j,0,10001){
            if(j>=cost[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + m[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    int ans = 10001;
    FOR(i,1,10001){
        if(dp[N][i]>=M) ans = min(ans, i);
    }
    cout << ans ;

    return 0;
}

//냅색 문제