#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[10001];
bool dfs(string dept, vector<vector<string>> tickets, vector<string>& answer, int depth) {
    answer.push_back(dept);
    if (depth == tickets.size()) return true;

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == dept && !visit[i]) {
            visit[i] = true;
            bool is_possible = dfs(tickets[i][1], tickets, answer, depth+1);
            if (is_possible) return true;
            visit[i] = false; // 잘못된 경로로 들어갔으면 Backtrack.
        }
    }

    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, answer, 0);

    return answer;
}
