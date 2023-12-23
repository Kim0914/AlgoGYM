#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num = 0, target_src = 0, target_dst = 0, edge = 0, src = 0, dest = 0;
vector<int> relationship[101];
bool visit[101];
void bfs(int curr_node) {
	queue<pair<int, int>> bfs_q;
	bfs_q.push({ curr_node, 0 });
	visit[curr_node] = true;

	while (!bfs_q.empty()) {
		int curr_node = bfs_q.front().first;
		int curr_walk = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < relationship[curr_node].size(); i++) {
			int next_node = relationship[curr_node][i];

			if (next_node == target_dst) {
				cout << curr_walk + 1;
				return;
			}

			if (!visit[next_node]) {
				bfs_q.push({ next_node, curr_walk + 1 });
				visit[next_node] = true;
			}
		}
	}

	cout << -1;
}

int main() {
	cin >> num;
	cin >> target_src >> target_dst;
	cin >> edge;

	for (int i = 0; i < edge; i++) {
		cin >> src >> dest;
		relationship[src].push_back(dest);
		relationship[dest].push_back(src);
		// 부모 - 자식 인접리스트
	}

	bfs(target_src);
}
