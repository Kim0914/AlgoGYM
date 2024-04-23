#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int vertices = 0, from = 0, to = 0, move_cnt = 0;
vector<int> graph[500001];
bool visit[500001];
void dfs(int curr_node, int depth) {
	if (curr_node != 1 && graph[curr_node].size() == 1) {
	// Leaf_node 일 때
		if (depth % 2 != 0)
			move_cnt++;
		return;
	}

	for (int i = 0; i < graph[curr_node].size(); i++) {
		int next_node = graph[curr_node][i];

		if (!visit[next_node]) {
			visit[next_node] = true;
			dfs(next_node, depth + 1);
			visit[next_node] = false;
		}
	}
}

int main() {
	OPTIMIZE;

	cin >> vertices;
	for (int i = 0; i < vertices - 1; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	} // 최선을 다하면 이길 수 있는가?
	// 성원이가 항상 선을 잡는다.

	visit[1] = true;
	dfs(1, 0);
	if (move_cnt % 2 != 0)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
