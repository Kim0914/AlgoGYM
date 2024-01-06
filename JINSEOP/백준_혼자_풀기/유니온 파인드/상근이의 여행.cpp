#include <iostream>
#include <vector>
using namespace std;

int tc = 0, air_num = 0, nat_num = 0, src = 0, dest = 0;
int mst[1001];
void init_tree() {
	for (int i = 1; i <= nat_num; i++)
		mst[i] = i;
}

int find_parent(int node) {
	if (mst[node] == node)
		return node;
	// 자기 자신이면 부모임
	return mst[node] = find_parent(mst[node]);
}

void do_union(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x < node_y)
		mst[node_x] = node_y;
	// 일반적으로 더 큰 쪽이 부모가 된다
	else
		mst[node_y] = node_x;
}

bool check_cycle(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);
	// 두 노드를 검사했는데 부모가 같으면
	// 사이클이 발생하기 때문에 union 불가

	if (node_x == node_y)
		return true;

	return false;
}

int main() {
	cin >> tc;
	
	while (tc--) {
		int answer = 0;
		vector<pair<int, int>> graph;
		cin >> nat_num >> air_num;

		for (int i = 0; i < air_num; i++) {
			cin >> src >> dest;
			// 어떤 자료구조에 저장할 것인가?
			// 우선 인접리스트로 진행해보자.
			graph.push_back({ src, dest });
		}

		init_tree();
		for (int i = 0; i < graph.size(); i++) {
			if (!check_cycle(graph[i].first, graph[i].second)) {
				do_union(graph[i].first, graph[i].second);
				answer++;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}
