#include <string>
#include <vector>
using namespace std;

int DP[1001] = {0,};
bool is_end = false;
int x = 0, y = 0, value = 1, outer = 0;

void init_dp(int n) {
    DP[1] = 1;
    for (int i = 2; i <= n; i++)
        DP[i] = DP[i - 1] + i;
}

void upward(int n, vector<vector<int>>& snail) {
    for (int i = outer; i < n; i++) {
        snail[y++][x] = value;
        value++;
        if (value > DP[n]) {
            is_end = true;
            return;
        }
    }

    outer++; x++; y--;
}

void rightward(int n, vector<vector<int>>& snail) {
    for (int i = outer; i < n; i++) {
        snail[y][x++] = value;
        value++;
        if (value > DP[n]) {
            is_end = true;
            return;
        }
    }

    outer++; x -= 2; y--;
}

void diagonal_ward(int n, vector<vector<int>>& snail) {
    for (int i = outer; i < n; i++) {
        snail[y--][x--] = value;
        value++;
        if (value > DP[n]) {
            is_end = true;
            return;
        }
    }

    outer++; x++; y += 2;
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n, vector<int>(n, 0));

    init_dp(n);

    while (true) {
        upward(n, snail);
        if (is_end) break;

        rightward(n, snail);
        if (is_end) break;
        
        diagonal_ward(n, snail);
        if (is_end) break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++)
            answer.push_back(snail[i][j]);
    }

    return answer;
}
