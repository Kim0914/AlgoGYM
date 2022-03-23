#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

int N;
int g[10001];
int dp[10001];
int M;

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        cin >> g[i];
    }

    dp[1] = g[1];
    dp[2] = g[1] + g[2];
    dp[3] = max(g[1] + g[3],max( g[2]+g[3], dp[2]));
    

    FOR(i,4,N+1){
        dp[i] = max(g[i-1]+ g[i] + dp[i-3],max( dp[i-2] + g[i], dp[i-1]) ) ;
    }

    FOR(i,1,N+1){
        M = max(M,dp[i]);
    }

    // FOR(i,1,N+1){
    //     cout<< i<< " " << dp[i] <<"\n";
    // }
    cout << M;

    return 0;
}