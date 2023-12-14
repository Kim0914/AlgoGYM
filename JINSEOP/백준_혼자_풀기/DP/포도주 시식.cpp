#include <iostream>
using namespace std;

int num = 0;
int wines[10001], dp[10001];
int main() {
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> wines[i];

    dp[0] = wines[0];
    dp[1] = wines[0] + wines[1];
    dp[2] = max(dp[1], max(wines[0] + wines[2], wines[1] + wines[2]));

    for (int i = 3; i < num; i++)
        dp[i] = max(dp[i - 1], max(wines[i] + dp[i - 2], wines[i] + wines[i - 1] + dp[i-3]));

    cout << dp[num - 1];
    return 0;
}
