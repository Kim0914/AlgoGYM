#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertex = 0, edge = 0;
int from = 0, to = 0;
int degree[32001];
vector<int> graph[32001];
void topology_sort() {
	priority_queue<int, vector<int>, greater<>> topo_q;

	for (int i = 1; i <= vertex; i++)
		if (degree[i] == 0)
			topo_q.push(i); // 진입차수가 0인 노드부터 입장

	while (!topo_q.empty()) {
		int curr = topo_q.top();
		topo_q.pop();
		cout << curr << " ";

		for (int i = 0; i < graph[curr].size(); i++) {
			int next_node = graph[curr][i];
			degree[next_node]--; // 진입차수 감소, 간선 제거의 단계
			if (degree[next_node] == 0)
				topo_q.push(next_node); // 간선을 제거했을 때, 진입차수가 0이면?
			// 큐에 집어넣고 진행하면 된다.
		}
	}
}

int main() {
	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		degree[to]++;
	}

	topology_sort();
	return 0;
}
