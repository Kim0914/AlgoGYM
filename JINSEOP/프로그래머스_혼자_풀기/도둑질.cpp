#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[1000000];
int solution(vector<int> money) {
    int answer = 0, max_v = 0;
    int size = money.size();

    // 첫번째 집을 선택하느냐 마느냐가 관건이다.
    dp[0] = money[0]; // 선택
    dp[1] = dp[0];
    for (int i = 2; i < money.size() - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    dp[size - 1] = dp[size - 2];
    max_v = *max_element(dp, dp + size);

    dp[0] = 0; // 선택 안함
    for (int i = 1; i < money.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    answer = max(max_v, *max_element(dp, dp + size));

    cout << answer;
    return answer;
}

int main() {
    solution({ 10, 5, 3, 1, 10 });
	return 0;
}
