#include <string>
#include <vector>
using namespace std;
#define MOD 1000000007

long long DP[5002] = { 0, }; // Long Long 타입 사용에 주의할 것! 숫자가 매우 커질 수 있어서 써야함.
void fill_DP(int n) {
    DP[0] = 1; DP[2] = 3;

    for (int i = 4; i <= n; i += 2) {
        DP[i] = DP[i - 2] * DP[2];
        for (int j = i - 4; j >= 0; j -= 2) {
            DP[i] += (DP[j] * 2); // N - 4 ~ 0까지
        }

        DP[i] = DP[i] % MOD;
    }
}

int solution(int n) {
    int answer = 0;

    if (n % 2 != 0) return 0;
    else {
        fill_DP(n);
        answer = DP[n];
    }

    return answer;
}
