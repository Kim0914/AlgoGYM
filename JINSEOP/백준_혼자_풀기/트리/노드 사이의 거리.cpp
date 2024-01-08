#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertex = 0, queries = 0, from = 0, to = 0, cost = 0;
vector<pair<int, int>> graph[1001];
int visit[1001];
void clear_visit() {
	for (int i = 0; i <= vertex; i++)
		visit[i] = 0;
}

int bfs(int start_node, int target_node) {
	queue<int> bfs_q;
	bfs_q.push(start_node);
	visit[start_node] = 0;

	while (!bfs_q.empty()) {
		int curr_node = bfs_q.front();
		int curr_distance = visit[curr_node];
		bfs_q.pop();

		for (int i = 0; i < graph[curr_node].size(); i++) {
			int next_node = graph[curr_node][i].first;
			int next_distance = curr_distance + graph[curr_node][i].second;

			if (!visit[next_node]) {
				if (next_node == target_node)
					return next_distance;

				bfs_q.push(next_node);
				visit[next_node] = next_distance;
			}
		}
	}
}

int main() {
	cin >> vertex >> queries;
	for (int i = 0; i < vertex - 1; i++) {
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	for (int i = 0; i < queries; i++) {
		cin >> from >> to;
		cout << bfs(from, to) << '\n';
		clear_visit();
	}

	return 0;
}
