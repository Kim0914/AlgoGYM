#include <iostream>
#include <vector>
using namespace std;

int nodes[1000001]; // 그래프
void init_nodes(int size) {
	for (int i = 1; i <= size; i++)
		nodes[i] = i;
}

int get_parent(int node) {
	// 인덱스와 자기 자신이 같으면 root node
	if (nodes[node] == node) return node;
	// 재귀적으로 부모(root)를 찾는다.
	return nodes[node] = get_parent(nodes[node]);
}

void do_union(int node_a, int node_b) {
	node_a = get_parent(node_a); // root 노드를 받아온다.
	node_b = get_parent(node_b);

	// 통상적으로 유니온 파인드는 작은 쪽이 부모가 된다.
	if (node_a > node_b) nodes[node_a] = node_b;
	else nodes[node_b] = node_a;
}

void find(int node_a, int node_b) {
	node_a = get_parent(node_a);
	node_b = get_parent(node_b);

	// 부모가 같음은, 같은 집합임을 의미한다.
	if (node_a == node_b) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0, op_num = 0;
	int oper = 0, node_a = 0, node_b = 0;

	cin >> num >> op_num;
	init_nodes(num);

	for (int i = 0; i < op_num; i++) {
		cin >> oper >> node_a >> node_b;

		if (oper == 0)
			do_union(node_a, node_b);
		else
			find(node_a, node_b);
	}

	return 0;
}
