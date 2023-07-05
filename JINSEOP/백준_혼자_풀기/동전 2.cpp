#include <iostream>
#include <vector>
using namespace std;

int dp[10001];
vector<int> coins;
void init_dp(int sum) {
    for (int i = 1; i <= sum; i++)
        dp[i] = 99999; // 최소를 구하기 위해 큰 값으로 초기화
}

void do_dp(int sum) {
    for (int i = 0; i < coins.size(); i++) {
        // 각 coin으로 만들 수 있는 방법을 추가하는 것이다.
        for (int j = coins[i]; j <= sum; j++)
            // 현재 돈의 값과 동일한 idx에서 시작한다.
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            // 이미 계산된 방법과 현재 돈을 사용해서 만드는 방법.
            // 더 작은 동전이 사용되는 쪽을 채택한다.
            // 예를 들어, 기본적으로 1원을 사용하려면 돈 그대로의 동전 갯수가 필요하다.
            // 하지만 5원을 사용할 것이라면, DP[5] = 1이 되고, DP[6] = 2가 될 수 있다.
            // DP[5-5] + 1 = 1 (0원에서 5원을 바로 더하는 경우)
            // DP[6-5] + 1 = 2 (1원에서 5원을 바로 더하는 경우, 동전 2개 사용)
    }
}

int main() {
    int num = 0, sum = 0, coin = 0;

    cin >> num >> sum;
    for (int i = 0; i < num; i++) {
        cin >> coin;
        coins.push_back(coin);
    }

    init_dp(sum);
    do_dp(sum);

    if (dp[sum] == 99999)
        cout << -1;
    else
        cout << dp[sum];
    return 0;
}
