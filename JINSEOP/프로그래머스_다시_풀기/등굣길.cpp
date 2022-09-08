#include <string>
#include <vector>
using namespace std;
#define PUDDLE -5

void put_puddle(vector<vector<int>>& maps, vector<vector<int>> puddles) {
    for (auto coord : puddles)
        maps[coord[1]][coord[0]] = PUDDLE;
}

void init_map(vector<vector<int>>& maps, vector<vector<int>> puddles) {
    put_puddle(maps, puddles);
    maps[1][1] = 1;
}

void do_DP(vector<vector<int>>& maps) {
    for (int i = 1; i < maps.size(); i++) {
        for (int j = 1; j < maps[i].size(); j++) {
            if (maps[i][j] == PUDDLE) continue;
            maps[i][j] += (maps[i - 1][j] == PUDDLE ? 0 : maps[i-1][j])
                       + (maps[i][j - 1] == PUDDLE ? 0 : maps[i][j-1]);
            maps[i][j] = maps[i][j] % 1000000007;
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> maps(n+1, vector<int>(m+1, 0));
    init_map(maps, puddles);
    do_DP(maps);
    answer = maps[n][m];

    return answer;
}

// 정석적인 DP문제였다.
