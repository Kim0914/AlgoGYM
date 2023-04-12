#include <string>
#include <vector>
#include <iostream>
using namespace std;

int limit = 0;
// 이걸 미리 저장해 놓을 생각을 하네;
int keypath[10][10] = { {1, 7, 6, 7, 5, 4, 5, 3, 2, 3},
                        {7, 1, 2, 4, 2, 3, 5, 4, 5, 6},
                        {6, 2, 1, 2, 3, 2, 3, 5, 4, 5},
                        {7, 4, 2, 1, 5, 3, 2, 6, 5, 4},
                        {5, 2, 3, 5, 1, 2, 4, 2, 3, 5},
                        {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
                        {5, 5, 3, 2, 4, 2, 1, 5, 3, 2},
                        {3, 4, 5, 6, 2, 3, 5, 1, 2, 4},
                        {2, 5, 4, 5, 3, 2, 3, 2, 1, 2},
                        {3, 6, 5, 4, 5, 3, 2, 4, 2, 1} };

void fill_dp(vector<vector<vector<int>>> &DP) {
    for (int i = 0; i < limit + 1; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++)
                DP[i][j][k] = -1;
        }
    }
}

int recursive_dp(vector<vector<vector<int>>> &DP, string &numbers, int idx, int left, int right) {
    if (idx == limit)
        return 0;
    if (DP[idx][left][right] != -1)
        return DP[idx][left][right];

    int digit = numbers[idx] - '0';
    int result = 9999999;

    if (digit != right) // 왼손을 움직이는 경우
        result = min(recursive_dp(DP, numbers, idx + 1, digit, right) + keypath[left][digit], result);
    if (digit != left) // 오른손을 움직이는 경우
        result = min(recursive_dp(DP, numbers, idx + 1, left, digit) + keypath[right][digit], result);

    return DP[idx][left][right] = result;
}

int solution(string numbers) {
    limit = numbers.size();
    vector<vector<vector<int>>> DP(limit + 1, vector<vector<int>>(10, vector<int>(10, 0)));

    fill_dp(DP);
    return recursive_dp(DP, numbers, 0, 4, 6);
}
