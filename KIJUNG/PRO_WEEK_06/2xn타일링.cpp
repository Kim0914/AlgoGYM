#define div 1000000007
using namespace std;

int dp[60001];

int solution(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<n+1;i++){
        dp[i] = (dp[i-2] + dp[i-1])%div;
    }
    return dp[n];
}