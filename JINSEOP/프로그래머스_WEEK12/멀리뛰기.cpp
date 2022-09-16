#include <string>
#include <vector>
using namespace std;

long long DP[2001];

void init_DP() {
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
}

void do_DP(int n) {
    init_DP();
    for (int i = 3; i <= n; i++)
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1234567;
}

long long solution(int n) {
    long long answer = 0;

    do_DP(n);
    answer = DP[n];
    return answer;
}
