#include <iostream>
#include <vector>
using namespace std;

void dfs(int idx, vector<vector<int>> computers, vector<bool>& visit) {
    visit[idx] = true;

    for (int i = 0; i < computers.size(); i++) {
        if (!visit[i] && computers[idx][i] == 1) { // 모든 Computer를 돌며 더 이상 연결된 Computer가 없으면 종료!
            dfs(i, computers, visit);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);
    
    for (int i = 0; i < n; i++)
        if (!visit[i]) {
            answer++;
            dfs(i, computers, visit);
        }

    return answer;
}

int main() {
    vector<vector<int>> computers = { {1,1,0}, {1,1,0}, {0,0,1} };
    cout << solution(3, computers); // 각 Column은 연결된 Computer를 의미하는 것.
    return 0;
}

// 간단한 DFS 문제!
