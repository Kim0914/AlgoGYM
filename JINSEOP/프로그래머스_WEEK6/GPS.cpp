#include <iostream>
#include <vector>
using namespace std;
#define INF 100000000

vector<vector<int>> make_map(int n, vector<vector<int>> edge_list) {
    vector<vector<int>> maps(n + 1);
    for (auto i : edge_list) {
        maps[i[0]].push_back(i[1]);
        maps[i[1]].push_back(i[0]);
    }

    return maps;
}

void set_base(vector<vector<int>>& DP, vector<int> gps_log) {
    DP[0][gps_log[0]] = 0;
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    vector<vector<int>> maps(n + 1);
    vector<vector<int>> DP(k, vector<int>(n + 1, INF));

    maps = make_map(n, edge_list);
    set_base(DP, gps_log);

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            DP[i][j] = min(DP[i - 1][j], DP[i][j]);
            for (int node : maps[j])
                DP[i][j] = min(DP[i - 1][node], DP[i][j]);

            DP[i][j] += (gps_log[i] == j) ? 0 : 1;
        }
    }

    if (DP[k - 1][gps_log[k - 1]] >= INF) return -1;
    answer = DP[k - 1][gps_log[k - 1]];

    for (auto i : DP) {
        for (auto k : i) cout << k << " ";
        cout << '\n';
    }
    return answer;
}
