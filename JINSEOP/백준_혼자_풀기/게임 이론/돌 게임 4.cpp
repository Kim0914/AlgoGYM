#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool dp[1001];
void init_dp() {
    // 적어도 4까지는 기저 조건으로 만들어야 한다.
    dp[1] = false; // False가 창영
    dp[2] = true; // True가 상근
    dp[3] = false; // 창영
    dp[4] = true; // 상근
}

int main() {
    int n = 0;
    cin >> n;

    init_dp();
    for (int i = 5; i <= n; i++) {
    // 이전 턴에서 한 번이라도 창영이가 이겼으면, 이번엔 상근이가 이김
        if (!dp[i - 4] || !dp[i - 3] || !dp[i - 1])
            dp[i] = true;
        else
            dp[i] = false;
    }

    if (dp[n])
        cout << "SK";
    else
        cout << "CY";
    return 0;
}
