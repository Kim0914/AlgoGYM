#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define INF 9999999

int FW[201][201];
void init_floyd_warshall(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) FW[i][j] = 0;
            else FW[i][j] = INF;
        }
    }
}

void init_fares(vector<vector<int>> fares) {
    for (auto fare : fares) {
        FW[fare[0]][fare[1]] = fare[2];
        FW[fare[1]][fare[0]] = fare[2];
    }
}

void floyd_warshall(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                FW[i][j] = min(FW[i][j], FW[i][k] + FW[k][j]);

}

int find_min_cost(int n, int s, int a, int b) {
    int answer = INF;

    for (int i = 1; i <= n; i++)
        answer = min(answer, FW[s][i] + FW[i][a] + FW[i][b]);

    return answer;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    init_floyd_warshall(n);
    init_fares(fares);
    floyd_warshall(n);
    answer = find_min_cost(n, s, a, b);

    return answer;
}

// Floyd-Warshall 알고리즘도 쓸데가 있다!!
