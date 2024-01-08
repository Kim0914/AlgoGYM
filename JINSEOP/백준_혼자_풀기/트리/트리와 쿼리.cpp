#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertex = 0, root = 0, queries = 0, from = 0, to = 0, query = 0;
vector<int> graph[100001];
int subtree_count[100001];
void dfs(int curr_node) {
	for (int i = 0; i < graph[curr_node].size(); i++) {
		int next_node = graph[curr_node][i];

		if (!subtree_count[next_node]) {
			subtree_count[next_node] = 1;
			dfs(next_node);
			subtree_count[curr_node] += subtree_count[next_node];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> vertex >> root >> queries;
	for (int i = 0; i < vertex - 1; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	subtree_count[root] = 1;
	dfs(root);
	for (int i = 0; i < queries; i++) {
		cin >> query;
		cout << subtree_count[query] << '\n';
	}

	return 0;
}
