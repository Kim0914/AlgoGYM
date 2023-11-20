#include <iostream>
using namespace std;

int num = 0;
int dp[301], stairs[301];
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void init_dp() {
    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
    // 2번째 계단은, 첫 계단을 밟고 오던지 건너 뛰던지 둘 중 하나다.
}

int main() {
    optimize();

    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> stairs[i];
    
    // DP이므로, 각 단계별 최대 점수를 갱신하며 나아가자.
    // 한 계단 또는 두 계단 이므로 둘 중 최대를 뽑으면 됨.
    for (int i = 3; i < num; i++)
        dp[i] = max(dp[i - 2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
    // 단, 연속된 3개의 계단을 모두 밟을 수는 없다는 점이 핵심!
    // 그래서 두 계단 전에서 건너뛰어오는 경우와 
    // (세 계단 전의 값 + 바로 전 계단 + 현재 계단) 을 통해서 세 계단을 이어 밟지 않도록 하자.
  
    cout << dp[num - 1];
    return 0;
}
