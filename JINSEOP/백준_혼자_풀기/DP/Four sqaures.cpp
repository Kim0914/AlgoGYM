#include <iostream>
using namespace std;

int num = 0, dp[50001], square_num = 1;
int main() {
    cin >> num;
    dp[0] = 0;
    dp[1] = 1; // 1은 1^2 끝

    for (int i = 2; i <= num; i++) {
        if ((square_num + 1) * (square_num + 1) == i)
            square_num++;
        // 다음 제곱 대상과 i가 같아지면, 제곱 대상을 더해줘야 함

        dp[i] = dp[i - (square_num * square_num)] + 1;
        for(int j = square_num - 1; j >= 1; j--)
            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
        // 내 생각에 사용할 수 있는 논리는 다음과 같다.
        // 1. 이전 수에 그냥 1^2을 더해서 수를 만든다.
        // 2. dp[i - (제곱수)]에 더해서 (제곱수)^2 + 1^2 을 하는 경우
        // 둘 중 더 작은 쪽으로 저장!
    }

    cout << dp[num];
    return 0;
}
