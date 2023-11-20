#include <iostream>
using namespace std;
#define ll long long

int target_num = 0, kind = 0;
int dp[201][201];
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void init_dp() {
    for (int i = 0; i <= kind; i++)
        dp[1][i] = i;
    // N = 1 일때 K는 1, 2, 3, 4, 5 ..
    // 왜? 1, 01, 001, 0001과 같이 증가하기 때문
}

int main() {
    optimize();
    cin >> target_num >> kind;

    init_dp();
    for (int i = 2; i <= target_num; i++)
        for (int j = 1; j <= kind; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
    // DP를 풀 때 반드시 모든 경우를 직접 적어 볼 것!!
    // K = 1일때는, N이 몇이든 자기자신을 선택하는 경우 하나 뿐이다.
    // N이 증가하며 K가 증가하는 표를 직접 적어보면,
    // (N, K-1)의 경우의 수 + (N-1, K)의 경우의 수가 됨을 알 수 있다.
  
    cout << dp[target_num][kind];
    return 0;
}
