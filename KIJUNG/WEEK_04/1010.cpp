#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, N, M;

int dp[31][31];

int main(void){
    cin >> T;

    FOR(i,1,31){
        FOR(j,0,i+1){
            if(j == 0 || i==j) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
        }
    }

    FOR(i,0,T){
        cin >> N >> M;
        cout << dp[M][N] << "\n";
    }

    return 0;
}