#include <iostream>
#include <vector>
using namespace std;

int dp[10001] = {};
vector<int> coins;
void init_dp() {
    dp[0] = 1;
}

void do_dp(int sum) {
    for (int i = 0; i < coins.size(); i++) {
        // 각 coin으로 만들 수 있는 방법을 추가하는 것이다.
        for (int j = coins[i]; j <= sum; j++)
            // 현재 돈의 값과 동일한 idx에서 시작한다.
            dp[j] += dp[j - coins[i]];
            // 현재 방법 + 현재 돈으로 j원을 만들 수 있는 방법
    }
}

int main() {
    int num = 0, sum = 0, coin = 0;

    cin >> num >> sum;
    for (int i = 0; i < num; i++) {
        cin >> coin;
        coins.push_back(coin);
    }

    init_dp();
    do_dp(sum);

    cout << dp[sum];
    return 0;
}
