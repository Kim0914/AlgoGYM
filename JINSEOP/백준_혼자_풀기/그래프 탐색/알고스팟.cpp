#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999

int row = 0, col = 0;
string map_line = "";
int algo_map[101][101], dist[101][101];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void init_dist() {
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            dist[i][j] = INF;
}

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> dijk_q;
    dijk_q.push({0, { 1, 1 }});
    dist[1][1] = 0; // 시작 지점은 반드시 0
    
    while (!dijk_q.empty()) {
        int curr_x = dijk_q.top().second.first;
        int curr_y = dijk_q.top().second.second;
        int curr_cost = dijk_q.top().first;
        dijk_q.pop();

        if (dist[curr_x][curr_y] < curr_cost)
            continue;

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            int next_cost = curr_cost + algo_map[nx][ny];

            if (dist[nx][ny] > next_cost) {
                dist[nx][ny] = next_cost;
                dijk_q.push({ next_cost, {nx, ny} });
            }
        }
    }
}

int main(){

    cin >> col >> row;
    for (int i = 1; i <= row; i++) {
        cin >> map_line;
        for (int j = 0; j < map_line.size(); j++)
            algo_map[i][j + 1] = (map_line[j] - '0');
    }

    // 기본적으로 전체 맵을 훑되, 최단거리가 아닌
    // 벽을 가장 적게, 즉 "최소 가중치"가 되어야 한다.
    // 시작 지점은 반드시 (1, 1), 도착지는 (N, M)
    init_dist();
    dijkstra();
    cout << dist[row][col]; 
    return 0;
}
