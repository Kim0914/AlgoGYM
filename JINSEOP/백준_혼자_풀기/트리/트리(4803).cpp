#include <iostream>
#include <vector>
using namespace std;

int vertex = 0, edge = 0, tc = 1, from = 0, to = 0;
int simple_tree[501];
bool cycle[501];
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void clear_tree() {
	for (int i = 1; i <= vertex; i++) {
		simple_tree[i] = 0;
		cycle[i] = false;
	}
}

void init_tree() {
	for (int i = 1; i <= vertex; i++)
		simple_tree[i] = i;
}

int find_parent(int node) {
	if (simple_tree[node] == node)
		return node;

	return simple_tree[node] = find_parent(simple_tree[node]);
}

void do_union(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x < node_y)
		simple_tree[node_y] = node_x;
	else
		simple_tree[node_x] = node_y;
}

bool check_cycle(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x == node_y)
		return true;
	return false;
}

int main() {
	optimize();

	while (true) {
		cin >> vertex >> edge;

		if (vertex == 0 && edge == 0)
			break;
		
		init_tree();
		for (int i = 0; i < edge; i++) {
			cin >> from >> to;
			if (check_cycle(from, to))
				cycle[find_parent(from)] = true;
      // 사이클이 검출되면 최상위 부모에 표시
			else {
				if (cycle[find_parent(from)] || cycle[find_parent(to)]) {
					cycle[find_parent(from)] = true;
					cycle[find_parent(to)] = true;
				// 사이클이 이미 형성되었을 때를 생각해야 함.
				// 새로 노드가 들어오면, 사이클 집단이 아닌 것으로 간주될 수 있음
				}

				do_union(from, to);
			}
		}

		int cnt = 0;
		for (int i = 1; i <= vertex; i++) {
			if (simple_tree[i] == i && !cycle[i])
				cnt++;
    // 사이클이 없고, 최상위 부모만 카운트하면 됨
		}

		if (cnt > 1)
			cout << "Case " << tc << ": A forest of " << cnt << " trees." << '\n';
		else if (cnt == 1)
			cout << "Case " << tc << ": There is one tree." << '\n';
		else
			cout << "Case " << tc << ": No trees." << '\n';

		clear_tree();
		tc++;
	}

	return 0;
}
