#include <vector>
#include <queue>
using namespace std;
#define INF 100000000

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> node_q;
vector<pair<int, int>> maps[51];
int dist[51];

void make_map(vector<vector<int>> road) {
    for (auto i : road) {
        maps[i[0]].push_back({ i[1], i[2] });
        maps[i[1]].push_back({ i[0], i[2] });
    }
}

void init_dist(int n) {
    for (int i = 1; i < n + 1; i++)
        dist[i] = INF;
}

void dijkstra(int start) {
    dist[start] = 0;
    node_q.push({ 0, start }); // first 기준으로 정렬하기 때문.

    while (!node_q.empty()) {
        int cost = node_q.top().first;
        int curr = node_q.top().second;
        node_q.pop();

        if (dist[curr] < cost) continue;

        for (int i = 0; i < maps[curr].size(); i++) {
            int next = maps[curr][i].first;
            int next_cost = cost + maps[curr][i].second;
            if (next_cost < dist[next]) {
                dist[next] = next_cost;
                node_q.push({ next_cost, next});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    make_map(road);
    init_dist(N);
    dijkstra(1);

    for (int i = 1; i < N + 1; i++)
        if (dist[i] <= K) answer++;

    return answer;
}
