#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int, int>> bfs_q;
priority_queue<int, vector<int>, greater<>> apt_q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1 };
int apt_cnt = 0;
void bfs(pair<int, int> start, vector<string> graph, vector<vector<bool>> &visit, int n) {
    bfs_q.push(start);
    visit[start.first][start.second] = true;
    apt_cnt++;

    while (!bfs_q.empty()) {
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if ((nx < n && nx >= 0) && (ny < n && ny >= 0)) {
                if (!visit[nx][ny] && graph[nx][ny] == '1') {
                    visit[nx][ny] = true;
                    bfs_q.push(make_pair(nx, ny));
                    apt_cnt++;
                }
            }
        }
    }
}

int main() {
    int n = 0, complex = 0;
    string apt = "";
    vector<string> graph;

    cin >> n;
    vector<vector<bool>> visit(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        cin >> apt;
        graph.push_back(apt);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && graph[i][j] == '1') {
                bfs(make_pair(i, j), graph, visit, n);
                apt_q.push(apt_cnt);
                apt_cnt = 0;
                complex++;
            }
        }
    }

    cout << complex << "\n";
    while (!apt_q.empty()) {
        cout << apt_q.top() << "\n";
        apt_q.pop();
    }

    return 0;
}
