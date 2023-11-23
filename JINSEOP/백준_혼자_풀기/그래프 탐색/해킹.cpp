#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 999999999

int tc = 0, vertex = 0, edge = 0, init_hacked = 0, from = 0, to = 0, cost = 0;
int dist[10001];
void init_dist() {
    for (int i = 0; i <= vertex; i++)
        dist[i] = INF;
}

void dijkstra(vector<pair<int, int>> pc_network[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk_q;
    dijk_q.push({0, init_hacked});

    while (!dijk_q.empty()) {
        int curr_node = dijk_q.top().second;
        int curr_cost = dijk_q.top().first;
        dijk_q.pop();

        if (dist[curr_node] < curr_cost)
            continue;

        for (int i = 0; i < pc_network[curr_node].size(); i++) {
            int next_node = pc_network[curr_node][i].first;
            int next_cost = pc_network[curr_node][i].second + curr_cost;

            if (dist[next_node] > next_cost) {
                dist[next_node] = next_cost;
                dijk_q.push({next_cost, next_node});
            }
        }
    }
}

int main(){
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        vector<pair<int, int>> pc_network[10001];
        int answer = 0, max_cost = 0;
        cin >> vertex >> edge >> init_hacked;

        init_dist();
        dist[init_hacked] = 0;// 시작점 초기화

        for (int j = 0; j < edge; j++) {
            cin >> to >> from >> cost;
            pc_network[from].push_back({ to, cost });
            // 단방향, to가 from을 의존한다.
        }

        dijkstra(pc_network);
        
        for (int i = 1; i <= vertex; i++) {
            if (dist[i] != INF) {
                answer++;
                max_cost = max(max_cost, dist[i]);
            }
        }
        // 여기서, 감염되는 컴퓨터의 수는 dist에서 INF가 아닌 컴퓨터의 수
        // 그리고, 가장 큰 값이 가장 마지막에 감염된 컴퓨터이다.
        cout << answer << " " << max_cost << '\n';
    }

    return 0;
}
