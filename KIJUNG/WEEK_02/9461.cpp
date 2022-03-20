#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T,tmp;
long dp[101];

int main (void){
    dp[1] = 1;dp[2] =1; dp[3] =1; dp[4] =2; dp[5] =2; dp[6] =3; dp[7] =4; dp[8] =5; dp[9] =7; dp[10] = 9;

    FOR(i, 11, 101) {
        dp[i] = dp[i-1] + dp[i-5];
        // cout << "i: "<<i<<" val: "<<dp[i] << "\n";
    }

    cin >> T;
    FOR(i,0,T){
        cin >> tmp;
        cout<< dp[tmp] << "\n";
    }

    return 0;
}