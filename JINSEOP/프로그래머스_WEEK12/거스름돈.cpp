#include <string>
#include <vector>
using namespace std;

int DP[100001];
int solution(int n, vector<int> money) {
    int answer = 0;
    DP[0] = 1;

    for (int i = 0; i < money.size(); i++) {
        for (int j = money[i]; j <= n; j++) {
            DP[j] += DP[j - money[i]];
            DP[j] %= 1000000007;
        }
    }

    answer = DP[n];
    return answer;
}
