#include <iostream>
using namespace std;

int num = 0;
int dp[31];
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void init_dp() {
    dp[0] = 1; // 하나도 안채우면 만들어짐
    dp[1] = 0; // 못만듬
    dp[2] = 3; // hvv vvh hhh
    // dp[4] = 11 =  dp[2] * dp[2] + 특수 * 2

    // dp[6] = 33 + 6 + 2// dp[4] * dp[2] + dp[2] * dp[4] + 특수[2]
    // 이 경우 부터는 중복되는 문양을 잘 생각해야 한다.
    // dp[4] dp[2]에서 dp[2]에 hvv vvh hhh가 오는 모든 경우가 다 포함되었기 때문에,
    // dp[2] dp[4]에서는 dp[4]가 반드시 특수 문양만 올 수 있다. 따라서 3 X 2 = 6
    // 거기에 6칸 짜리 특수문양 2가지.

    // dp[8] = dp[6] * dp[2] + dp[4] * dp[4] + dp[2] * dp[6] + 특수[2]
    // 위의 경우와 마찬가지이다.
    // dp[6] dp[2] = 123가지, dp[4] dp[4]에서 중복제거 = 22가지
    // dp[2] dp[6]에서 중복 제거 = 6가지 + 특수 2가지
    // 따라서 123 + 22 + 6 + 2 = 153가지.

    // 위의 설명을 미루어보았을 때, 점화식은 아래와 같이 계산할 수 있다.
    // dp[N] = dp[N-2] * dp[2] + dp[N-4] * 2 + dp[N-6] * 2 + dp[N-8] * 2 + ... + dp[0] * 2(특수)
}

int main() {
    optimize();

    cin >> num;
    if (num % 2 != 0) {
        // 홀수는 어차피 안됨
        cout << 0;
        return 0;
    }

    init_dp();

    for (int i = 4; i <= num; i += 2) {
        dp[i] += dp[i - 2] * dp[2];
        // 먼저 중복을 신경쓰지 않고 hvv vvh hhh 경우의 수 곱하기

        for (int j = 4; j <= i; j += 2)
            dp[i] += dp[i - j] * 2;
        // 중복을 신경써 특수한 경우만 곱해주는 부분
    }

    cout << dp[num];
}
