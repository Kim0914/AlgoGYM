#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int dp[1000001];
int N;

int main(void){
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;

    FOR(i,3,N+1){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }

    cout << dp[N];

    return 0;
}