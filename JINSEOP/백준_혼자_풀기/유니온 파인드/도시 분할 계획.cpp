#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vertex = 0, edge = 0, max_cost = 0, answer = 0, mst[100001];
vector<pair<int, pair<int, int>>> village;
void init_mst() {
	for (int i = 1; i <= vertex; i++)
		mst[i] = i;
	// MST를 만드려면 유니온 파인드를 이용해야 한다.
}

int get_parent(int curr_node) {
	if (curr_node == mst[curr_node])
		return curr_node;
	// 자기 자신과 배열의 값이 같으면 부모 노드

	return mst[curr_node] = get_parent(mst[curr_node]);
}

void do_union(int node_x, int node_y) {
	node_x = get_parent(node_x);
	node_y = get_parent(node_y);

	if (node_x > node_y)
		mst[node_x] = node_y;
	else
		mst[node_y] = node_x;
	// 통상적으로 작은 쪽이 부모로 합쳐진다.
}

bool check_cycle(int node_x, int node_y) {
	node_x = get_parent(node_x);
	node_y = get_parent(node_y);

	if (node_x == node_y)
		return true;
	// 합치려는데 부모가 같으면? 사이클이 발생한다.
	return false;
}

void make_mst() {
	for (int i = 0; i < edge; i++) {
		int node_x = village[i].second.first;
		int node_y = village[i].second.second;

		if (!check_cycle(node_x, node_y)) {
			do_union(node_x, node_y);
			answer += village[i].first;
			// 병합될 때, 해당 도로의 유지비를 더한다.
			max_cost = (max_cost, village[i].first);
			// 마지막에 유지비가 가장 큰 도로를 빼서 마을을 분리한다.
		}
		// 사이클이 있으면 병합하지 않고, 없으면 진행
	}
}

int main() {
	cin >> vertex >> edge;

	int cost = 0, from = 0, to = 0;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> cost;
		village.push_back({ cost, {from, to} });
		// cost가 가장 앞에 오는 이유는, cost 기준 정렬을 위해
	}

	sort(village.begin(), village.end());
	// 입력받은 간선의 정보를 유지비 기준으로 오름차순 정렬한다.
	init_mst();
	make_mst();
  // Kruskal 알고리즘을 이용한다.
  
	cout << answer - max_cost;
	return 0;
}
