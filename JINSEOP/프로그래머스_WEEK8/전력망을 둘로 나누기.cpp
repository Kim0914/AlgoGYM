#include <string>
#include <vector>
#include <queue>
using namespace std;
#define INF 9999999

queue<int> bfs_q;
void clear_map(vector<vector<int>>& adj_list, vector<bool>& visit) {
    for (int i = 0; i < adj_list.size(); i++)
        adj_list[i].clear();
    for (int i = 0; i < visit.size(); i++)
        visit[i] = 0;
}

void cut_wires(int point, vector<vector<int>> wires, vector<vector<int>>& adj_list) {
    for (int i = 0; i < wires.size(); i++) {
        if (i == point) continue;
        adj_list[wires[i][0]].push_back(wires[i][1]);
        adj_list[wires[i][1]].push_back(wires[i][0]);
    }
}

int bfs(int st, vector<vector<int>>& adj_list, vector<bool>& visit) {
    int cnt = 1;
    bfs_q.push(st);
    visit[st] = true;

    while (!bfs_q.empty()) {
        for (int i = 0; i < adj_list[bfs_q.front()].size(); i++) {
            if (!visit[adj_list[bfs_q.front()][i]]) {
                visit[adj_list[bfs_q.front()][i]] = true;
                bfs_q.push(adj_list[bfs_q.front()][i]);
                cnt++;
            }
        }
        bfs_q.pop();
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;

    vector<vector<int>> adj_list(n+1);
    vector<bool> visit(n + 1);

    for (int i = 0; i < wires.size(); i++) {
        int cnt = 0, p_cnt = 0;
        cut_wires(i, wires, adj_list);

        for (int j = 1; j < n; j++) {
            if (!visit[j]) {
                p_cnt = cnt;
                cnt = bfs(j, adj_list, visit);
            }
        }

        answer = min(answer, abs(p_cnt - cnt));
        clear_map(adj_list, visit);
    }

    return answer;
}
