#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue<int> bfs_q;
void dfs(vector<vector<int>> graph, vector<bool>& visit, int curr) {
    cout << curr << " ";

    for (int i = 0; i < graph[curr].size(); i++) {
        if (!visit[graph[curr][i]]) {
            visit[graph[curr][i]] = true;
            dfs(graph, visit, graph[curr][i]);
        }
    }
}

void bfs(vector<vector<int>> graph, vector<bool>& visit, int start) {
    bfs_q.push(start);
    visit[start] = true;

    while (!bfs_q.empty()) {
        int curr = bfs_q.front();
        bfs_q.pop();
        cout << curr << " ";

        for (int i = 0; i < graph[curr].size(); i++) {
            if(!visit[graph[curr][i]]){
                visit[graph[curr][i]] = true;
                bfs_q.push(graph[curr][i]);
            }
        }
    }
}

int main() {
    int vertex = 0, edge = 0, start = 0;
    int y = 0, x = 0;
    cin >> vertex >> edge >> start;
    vector<vector<int>> graph(vertex + 1, vector<int>());
    vector<bool> d_visit(vertex + 1, false);
    vector<bool> b_visit(vertex + 1, false);

    for (int i = 0; i < edge; i++) {
        cin >> y >> x;
        graph[y].push_back(x);
        graph[x].push_back(y);
    }

    for (int i = 0; i < graph.size(); i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    d_visit[start] = true;
    dfs(graph, d_visit, start);
    cout << "\n";
    bfs(graph, b_visit, start);
    return 0;
}

// 인접리스트로 구현하는 것 보다 인접 행렬이 더 빠르다.
// 왜? DFS 수행 시 정렬을 하지 않아도 되기 때문
