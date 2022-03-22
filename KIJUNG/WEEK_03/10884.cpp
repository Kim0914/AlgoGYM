#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int N;
long sum = 0;

int dp[101][11];

int main(void){
    cin>>N;

    fill(dp[1]+1, dp[1]+10, 1);

    FOR(i,2,N+1){
        FOR(j,0,10){
            if(j == 0) dp[i][j] = dp[i-1][1];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }

    FOR(i,0,10){
        sum+=dp[N][i];
    }

    cout << sum%1000000000;
    
    return 0;
}
//메모리를 많이 쓰자