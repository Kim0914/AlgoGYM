#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[500001];
bool is_cycle = false;
void init_graph(int size) {
	for (int i = 0; i < size; i++)
		graph[i] = i;
}

int get_parent(int node) {
	if (graph[node] == node)
		return node;
	return graph[node] = get_parent(graph[node]);
}

bool check_cycle(int node_x, int node_y) {
	if (node_x == node_y)
		return true;
	else
		return false;
}

void do_union(int node_x, int node_y) {
	node_x = get_parent(node_x);
	node_y = get_parent(node_y);

	if (check_cycle(node_x, node_y)) {
		is_cycle = true;
		return;
	}

	if (node_x > node_y) graph[node_y] = node_x;
	else graph[node_x] = node_y;
}

int main() {
	int ver = 0, turn = 0, node_x = 0, node_y = 0, answer = 0;

	cin >> ver >> turn;
	init_graph(ver);

	for(int i = 0; i < turn; i++) {
		cin >> node_x >> node_y;
		do_union(node_x, node_y);

		if (is_cycle) {
			answer = i + 1;
			break;
		}
	}

	cout << answer;

	return 0;
}
