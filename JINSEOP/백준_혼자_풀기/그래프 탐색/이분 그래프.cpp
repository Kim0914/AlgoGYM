#include <iostream>
#include <vector>
using namespace std;

int tc = 0, vertex = 0, edges = 0, from = 0, to = 0;
vector<int> graph[20001];
int visit[20001];
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int curr_node) {
    if (!visit[curr_node])
        visit[curr_node] = 1;
    // 특정 색으로 변경

    for (int i = 0; i < graph[curr_node].size(); i++) {
        if (!visit[graph[curr_node][i]]) {
            if (visit[curr_node] == 1)
                visit[graph[curr_node][i]] = 2;
            else if (visit[curr_node] == 2)
                visit[graph[curr_node][i]] = 1;

            dfs(graph[curr_node][i]);
        }
    }
}

void clear_array() {
    for (int i = 1; i <= vertex; i++) {
        visit[i] = 0;
        graph[i].clear();
    }
}


bool check_bipartited() {
    for (int i = 1; i <= vertex; i++) {
        for (int j = 0; j < graph[i].size(); j++)
            if (visit[i] == visit[graph[i][j]])
                return false;
    }

    return true;
}

int main(){
    optimize();
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> vertex >> edges;
        for (int j = 0; j < edges; j++) {
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
            // 양방향 그래프
        }

        for (int j = 1; j <= vertex; j++)
            if (!visit[j])
                dfs(j);

        if (check_bipartited())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        clear_array();
    }

    return 0;
}
