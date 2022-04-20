#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, K;
int dp[501][501];
int num[501];
int sum[501];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    FOR(i,0,T){
        cin >> K;

        FOR(j,1,K+1){
            cin >> num[j];
            sum[j] = sum[j-1] + num[j];
        }
        
        FOR(j,1,K+1){
            FOR(l,1,K-j+1){
                dp[l][l+j] = 1000000000; 
                FOR(m,l,l+j){
                    dp[l][l+j] = min(dp[l][l+j], dp[l][m] + dp[m+1][j+l] + sum[l+j] - sum[l-1]);
                }
            }
        }

        cout << dp[1][K] << '\n';
    }

    return 0;
}