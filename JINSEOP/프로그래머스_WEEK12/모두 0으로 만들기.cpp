#include <iostream>
#include <vector>
using namespace std;

long long res_count = 0;
void init_weight(vector<long long>& weight, vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        weight[i] = a[i];
}

void make_tree(vector<vector<int>>& adj_list, vector<vector<int>> edges, vector<int> a) {
    for (auto edge : edges) {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }
}

void make_all_zero(vector<vector<int>>& adj_list, vector<long long>& weight, int curr, int parent) {
    for (int i = 0; i < adj_list[curr].size(); i++)
        if (adj_list[curr][i] != parent)
            make_all_zero(adj_list, weight, adj_list[curr][i], curr);

    weight[parent] += weight[curr];
    res_count += abs(weight[curr]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -1;
    vector<vector<int>> adj_list(a.size());
    vector<long long> weight(a.size());

    init_weight(weight, a);
    make_tree(adj_list, edges, a);
    make_all_zero(adj_list, weight, 0, 0);
    
    if (weight[0] == 0) return res_count;
    else return -1;
}
