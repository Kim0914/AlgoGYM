#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int nums[100001];
int dp[100001];
int M =-1001;


int main(void){
    cin >> N;

    FOR(i,1,N+1){
        cin >> nums[i];
    }

    FOR(i,1,N+1){
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        M = max(M, dp[i]);
    }

    cout << M;

    return 0;
}