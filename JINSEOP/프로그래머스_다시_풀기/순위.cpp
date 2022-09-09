#include <iostream>
#include <string>
#include <vector>
using namespace std;

int FW[101][101];
void init_result(int n, vector<vector<int>> result) {
    for (auto res : result)
        FW[res[0]][res[1]] = 1;
}

void floyd_warshall(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (FW[i][k] && FW[k][j]) FW[i][j] = 1;
}

void count_can_rank(int n, int& answer) {
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++)
            temp += (FW[i][j] + FW[j][i]); 
        if (temp == n - 1) answer++;
    }
}

int solution(int n, vector<vector<int>> result) {
    int answer = 0;

    init_result(n, result);
    floyd_warshall(n);
    count_can_rank(n, answer);
    
    return answer;
}
