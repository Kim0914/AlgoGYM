#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num = 0;
vector<int> graph[300001];
bool visit[300001];
int bfs(int start_node) {
	int last_node = 0;

	queue<int> bfs_q;
	bfs_q.push(start_node);
	visit[start_node] = true;

	while (!bfs_q.empty()) {
		int curr_node = bfs_q.front();
		bfs_q.pop();
		last_node = curr_node;

		for (int i = 0; i < graph[curr_node].size(); i++) {
			int next_node = graph[curr_node][i];

			if (!visit[next_node]) {
				bfs_q.push(next_node);
				visit[next_node] = true;
			}
		}
	}

	return last_node;
}

int main() {
	cin >> num;

	int from = 0, to = 0;
	for (int i = 0; i < num - 2; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vector<int> answer;
	if (num == 2)
		cout << "1 2" << ' ';
	else {
		for(int i = 1; i <= num; i++)
			if(!visit[i])
				answer.push_back(bfs(i));
	}

	for (auto i : answer)
		cout << i << " ";
	return 0;
}
