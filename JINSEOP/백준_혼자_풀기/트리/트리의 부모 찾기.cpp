#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num = 0, x = 0, y = 0;
vector<int> simple_tree[100001];
int visit[100001];
void bfs() {
	queue<int> bfs_q;
	bfs_q.push(1); // root는 1
	visit[1] = 1;

	while (!bfs_q.empty()) {
		int curr_node = bfs_q.front();
		bfs_q.pop();

		for (int i = 0; i < simple_tree[curr_node].size(); i++) {
			int next_node = simple_tree[curr_node][i];
			if (!visit[next_node]) {
				bfs_q.push(next_node);
				visit[next_node] = curr_node;
			}
		}
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num - 1; i++) {
		cin >> x >> y;
		simple_tree[x].push_back(y);
		simple_tree[y].push_back(x);
	}

	bfs();
	for (int i = 2; i <= num; i++)
		cout << visit[i] << "\n";
	return 0;
}
