#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define pdd pair<double, double>
#define pdii pair<double, pair<int, int>>

int num = 0, msp_tree[101];
double x = 0.0, y = 0.0, whole_distance = 0;
pdd node_coordinates[101];
vector<pdii> graph;
void init_tree() {
    for (int i = 1; i <= num; i++)
        msp_tree[i] = i;
}

int find_parent(int node) {
    if (node == msp_tree[node])
        return node;

    return msp_tree[node] = find_parent(msp_tree[node]);
}

void do_union(int node_x, int node_y) {
    node_x = find_parent(node_x);
    node_y = find_parent(node_y);

    if (node_x > node_y)
        msp_tree[node_x] = node_y;
    else
        msp_tree[node_y] = node_x;
}

bool check_cycle(int node_x, int node_y) {
    node_x = find_parent(node_x);
    node_y = find_parent(node_y);

    if (node_x == node_y)
        return true;
    return false;
}

int main() {
    cin >> num;
    for (int i = 1; i <= num; i++) {
        cin >> x >> y;
        node_coordinates[i] = {x, y};
        // 주어지는 모든 노드의 좌표를 저장
    }

    for (int i = 1; i <= num; i++) {
        for (int j = i + 1; j <= num; j++) {
            double distance = sqrt((pow(node_coordinates[i].first - node_coordinates[j].first, 2) + pow(node_coordinates[i].second - node_coordinates[j].second, 2)));
            graph.push_back({ distance, {i, j} });
            // 출발지 = {목적지, 거리}
        }
    } // 여기서 모든 간선을 저장한다.

    sort(graph.begin(), graph.end());
    // 모든 간선의 정보를 오름차순 정렬해야 한다.
    // Kruskal 알고리즘을 사용해보기 위해서!

    init_tree();
    for (int i = 0; i < graph.size(); i++) {
        int from = graph[i].second.first;
        int to = graph[i].second.second;
        double curr_distnace = graph[i].first;

        if (!check_cycle(from, to)) {
            do_union(from, to);
            whole_distance += curr_distnace;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << whole_distance;
    return 0;
}
