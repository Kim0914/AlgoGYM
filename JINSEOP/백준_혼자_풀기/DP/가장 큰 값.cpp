#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, group_num = 0, answer = 0;
int dp[21], sum[21][21], seq[21];
void select_group(int depth, int prev_idx, int group_sum) {
    if (depth == group_num) {
        answer = max(answer, group_sum);
        return;
    }

    for (int i = prev_idx + 1; i < num; i++)
        for (int j = i; j < num; j++)
            select_group(depth + 1, j, group_sum + sum[i][j]);
}

int main() {
    cin >> num >> group_num;
    
    for (int i = 0; i < num; i++)
        cin >> seq[i];
    
    dp[0] = 0;
    for (int i = 1; i <= num; i++)
        dp[i] += dp[i - 1] + seq[i - 1];

    for (int i = 0; i <= num; i++)
        for (int j = i + 1; j <= num; j++)
            sum[i][j-1] = dp[j] - dp[i];

    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            select_group(1, j, sum[i][j]);

    cout << answer;
    return 0;
}
