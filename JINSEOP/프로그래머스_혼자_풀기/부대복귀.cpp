#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define INF 9999999;

int dist[100001];
queue<int> node_q;

void init_map(int size, vector<vector<int>> roads, vector<vector<int>>& fw_map) {
    for (int i = 1; i <= size; i++)
        dist[i] = INF;

    for (auto vec : roads) {
        fw_map[vec[0]].push_back(vec[1]);
        fw_map[vec[1]].push_back(vec[0]);
    }
}

void dijkstra(int size, int destination, vector<vector<int>>& fw_map) {
    bool is_first = true;
    dist[destination] = 0;
    node_q.push(destination);

    while (!node_q.empty()) {
        int curr = node_q.front();
        node_q.pop();

        for (int i = 0; i < fw_map[curr].size(); i++) {
            int next = fw_map[curr][i];
         
            if (dist[curr] + 1 < dist[next]) {
                dist[next] = dist[curr] + 1;
                node_q.push(next);
            }
        }
    }
}

void fill_answer(vector<vector<int>> fw_map, vector<int> sources, vector<int>& answer) {
    for (auto i : sources) {
        int input_val = dist[i];
        if (input_val == 9999999)
            answer.push_back(-1);
        else
            answer.push_back(input_val);
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> fw_map(n+1, vector<int>());

    init_map(n, roads, fw_map);
    dijkstra(n, destination, fw_map);
    fill_answer(fw_map, sources, answer);

    return answer;
}
