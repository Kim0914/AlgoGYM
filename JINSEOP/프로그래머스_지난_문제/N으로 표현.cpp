#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int make_sequence(int N, int idx) {
    int seq = N;

    for (int i = 0; i < idx; i++)
        seq = (seq * 10) + N;

    return seq;
}

int fill_dp(int N, int number, vector<unordered_set<int>>& DP) {
    if (N == number) return 1;

    DP[0].insert(N);
    for (int i = 1; i < 8; i++) {
        DP[i].insert(make_sequence(N, i));

        for (int a = 0; a < i; a++) {
            for (int b = 0; b < i; b++) {
                if (a + b + 1 != i) continue;

                for (int pv : DP[a]) {
                    for (int nx : DP[b]) {
                        DP[i].insert(pv + nx);
                        DP[i].insert(pv * nx);
                        if (pv - nx > 0) DP[i].insert(pv - nx);
                        if (pv / nx > 0) DP[i].insert(pv / nx);
                    }
                }
            }
        }
        if (DP[i].find(number) != DP[i].end()) return i + 1;
    }
    return -1;
}

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int>> DP(8);

    answer = fill_dp(N, number, DP);

    return answer;
}
