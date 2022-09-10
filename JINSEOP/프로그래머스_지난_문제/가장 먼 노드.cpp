#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 9999999
#define START 1

int dist[20001];
vector<pair<int, int>> graph[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijk_q;
void init_graph(int n, vector<vector<int>> vertex) {
    for (auto ver : vertex) {
        graph[ver[0]].push_back({ ver[1], 1 });
        graph[ver[1]].push_back({ ver[0], 1 });
    }

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dijk_q.push({START, 0});
    dist[START] = 0;
}

void dijkstra_with_pq() {
    while (!dijk_q.empty()) {
        int curr_node = dijk_q.top().first;
        int cost = dijk_q.top().second;
        dijk_q.pop();

        if (dist[curr_node] < cost) continue;

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i].first;
            int next_cost = cost + graph[curr_node][i].second;

            if (next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                dijk_q.push({ next_node, next_cost });
            }
        }
    }
}

int count_max_node(int n) {
    int max_node = *max_element(dist, dist+n);
    int cnt = 0;

    for (int i = 1; i <= n; i++)
        if (dist[i] == max_node) cnt++;

    return cnt;
}

int solution(int n, vector<vector<int>> vertex) {
    int answer = 0;

    init_graph(n, vertex);
    dijkstra_with_pq();
    answer = count_max_node(n);

    return answer;
}

// DIJKSTRA의 정석 문제!
