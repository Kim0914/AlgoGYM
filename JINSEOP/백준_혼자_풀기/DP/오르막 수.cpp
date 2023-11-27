#include <iostream>
using namespace std;
#define ll long long

int num = 0;
ll dp[1001][10];
void init_dp() {
    dp[1][9] = 1;
    for (int i = 8; i >= 0; i--)
        dp[1][i] = dp[1][i+1] + 1;
    // 0 ~ 9까지는 한 자릿수로 10개의 오르막수가 된다.
    // 그럼 그 다음부터는?
}

int main(){
    cin >> num;

    init_dp();
    for (int i = 2; i <= num; i++) {
        dp[i][9] = 1;

        for (int j = 8; j >= 0; j--)
            dp[i][j] += (dp[i - 1][j] + dp[i][j + 1]) % 10007;
    }

    cout << dp[num][0] % 10007;
    return 0;
}
