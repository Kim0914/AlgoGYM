#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int kr_map[101];

void init_map(int size) {
    for (int i = 0; i < size; i++)
        kr_map[i] = i;
}

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int get_parent(int curr) {
    if (kr_map[curr] == curr)
        return curr;

    return kr_map[curr] = get_parent(kr_map[curr]);
}

void kruskal(int& answer, vector<vector<int>> costs) {
    for (int i = 0; i < costs.size(); i++) {
        int start = get_parent(costs[i][0]);
        int end = get_parent(costs[i][1]);
        int cost = costs[i][2];

        if (start != end) {
            answer += cost;
            kr_map[end] = start;
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    init_map(n);
    sort(costs.begin(), costs.end(), cmp);
    kruskal(answer, costs);

    return answer;
}
