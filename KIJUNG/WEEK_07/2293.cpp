#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n,k;
int dp[10001];
int coin[101];

int main(void){

    cin >> n >> k;

    FOR(i,1,n+1){
        cin >> coin[i];
    }

    dp[0] = 1;
    FOR(i,1,n+1){
        FOR(j,coin[i],k+1){
            dp[j] += dp[j-coin[i]];
        }
    }
    cout << dp[k];

    return 0;
}
//dp 정리
//점화식을 찾는 것이 관건
//1차원 점화식
//구간 점화식
//겹치는 연산을 찾는게 핵심!