#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001]; // 그래프
long long answer = 0;
bool noCycle = false;
vector<pair<int, pair<int, int>>> graph;
void init_map(int size) {
	for (int i = 1; i <= size; i++)
		parent[i] = i;
}

int get_parent(int node) {
	if (parent[node] == node) return node;
	return parent[node] = get_parent(parent[node]);
}

void do_union(int node_x, int node_y) {
	noCycle = false;

	node_x = get_parent(node_x);
	node_y = get_parent(node_y);

	// 부모가 같은데 연결을 한다?
	// 사이클이 생긴다는 것이므로 연결하지 않는다.
	if (node_x == node_y)
		return;
	else {
		if (node_x < node_y) parent[node_x] = node_y;
		else parent[node_y] = node_x;

		noCycle = true;
	}
}

int main() {
	int ver = 0, ed = 0;
	int node_x = 0, node_y = 0, weight = 0;

	cin >> ver >> ed;
	for (int i = 0; i < ed; i++) {
		cin >> node_x >> node_y >> weight;
		graph.push_back({ weight, { node_x, node_y } });
	}

	init_map(ver);
	sort(graph.begin(), graph.end()); // 가중치 오름차순 정렬

	// 이제부터 간선을 잇는다.
	for (int i = 0; i < ed; i++) {
		do_union(graph[i].second.first, graph[i].second.second);
		if (noCycle) answer += graph[i].first;
	}

	cout << answer;

	return 0;
}
