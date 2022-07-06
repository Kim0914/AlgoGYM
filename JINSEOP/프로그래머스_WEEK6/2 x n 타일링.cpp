#include <string>
#include <vector>
using namespace std;

void set_base(vector<int>& DP) {
    DP[0] = 1; DP[1] = 1;
}

int solution(int n) {
    int answer = 0;
    vector<int> DP(n+1, 0);

    set_base(DP);
    for (int i = 2; i <= n; i++) {
        DP[i] = (DP[i - 1] + DP[i - 2])%1000000007;
    }

    answer = DP[n];
    return answer;
}
