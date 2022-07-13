#include <string>
#include <vector>
using namespace std;
#define PUD -9

void set_puddle(vector<vector<int>> puddles, vector<vector<int>>& maps) {
    for (int i = 0; i < puddles.size(); i++)
        maps[puddles[i][1]-1][puddles[i][0]-1] = PUD;
}

void set_DP(vector<vector<int>>& DP) {
    DP[0][0] = 1;
}

void do_DP(vector<vector<int>>& DP) {
    for (int i = 0; i < DP.size(); i++) {
        for (int j = 0; j < DP[i].size(); j++) {
            if (DP[i][j] == PUD) continue;
            if (i != 0) {
                if (DP[i - 1][j] != 0 && DP[i - 1][j] != PUD) {
                    DP[i][j] += DP[i - 1][j];
                    DP[i][j] = DP[i][j] % 1000000007;
                }
            }
            if (j != 0) {
                if (DP[i][j - 1] != 0 && DP[i][j - 1] != PUD) {
                    DP[i][j] += DP[i][j - 1];
                    DP[i][j] = DP[i][j] % 1000000007;
                }
            }
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> DP(n, vector<int>(m, 0));

    set_puddle(puddles, DP);
    set_DP(DP);
    do_DP(DP);

    answer = DP[n-1][m-1];
    return answer;
}
