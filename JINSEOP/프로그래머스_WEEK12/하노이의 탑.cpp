#include <string>
#include <vector>
using namespace std;

void do_hanoi(int n, int from, int via, int to, vector<vector<int>>& answer) {
    if (n == 1)
        answer.push_back({ from, to });
    else {
        do_hanoi(n - 1, from, to, via, answer);
        answer.push_back({ from, to });
        do_hanoi(n - 1, via, from, to, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    do_hanoi(n, 1, 2, 3, answer);
    return answer;
}

// 하노이의 탑 알고리즘 좀 더 공부 !
