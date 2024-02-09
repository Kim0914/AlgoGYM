#include <iostream>
using namespace std;

int num = 0;
bool dp[1001];
void init_dp() {
    dp[0] = false;
    // 0을 상근, 1을 창영이라고 생각하자.
    dp[1] = false;
    // 1개 게임은 상근이가 반드시 이긴다.
    dp[2] = true;
    // 2개 게임은 창영이가 반드시 이긴다.
    dp[3] = false;
    dp[4] = false;
    // 3개 4개는 상근이가 이긴다.
}

int main() {
    cin >> num;
    init_dp();

    for (int i = 5; i <= num; i++) {
        if (dp[i - 1] == true || dp[i - 3] == true || dp[i - 4] == true)
            dp[i] = false;
        else
            dp[i] = true;
    }

    if (dp[num] == false)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}
