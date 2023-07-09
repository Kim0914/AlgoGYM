#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001]; // 그래프
long long answer = 0;
vector<pair<int, pair<int, int>>> graph;
void init_map(int size) {
	for (int i = 1; i <= size; i++)
		parent[i] = i;
}

int get_parent(int node) {
	if (parent[node] == node) return node;
	return parent[node] = get_parent(parent[node]);
}

bool checkCycle(int node_x, int node_y) {
	// Cycle이 존재하는 지 확인하는 함수
	node_x = get_parent(node_x);
	node_y = get_parent(node_y);

	// 부모가 같으면 연결했을 때, Cycle이 발생한다.
	if (node_x == node_y)
		return true;

	return false;
}

void do_union(int node_x, int node_y) {
	node_x = get_parent(node_x);
	node_y = get_parent(node_y);

	if (node_x < node_y) parent[node_x] = node_y;
	else parent[node_y] = node_x;
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
		if (!checkCycle(graph[i].second.first, graph[i].second.second)) {
			// Cycle 발생 가능성이 없으면 아래의 로직 진행
			do_union(graph[i].second.first, graph[i].second.second);
			answer += graph[i].first;
		}
	}

	cout << answer;

	return 0;
}
