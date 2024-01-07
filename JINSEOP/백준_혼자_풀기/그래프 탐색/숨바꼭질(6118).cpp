#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertex = 0, edges = 0, from = 0, to = 0;
vector<int> network[20001];
int visit[20001];
void bfs() {
	queue<int> bfs_q;
	bfs_q.push(1);
	visit[1] = 1;

	while (!bfs_q.empty()) {
		int curr_barn = bfs_q.front();
		bfs_q.pop();

		for (int i = 0; i < network[curr_barn].size(); i++) {
			int next_barn = network[curr_barn][i];

			if (!visit[next_barn]) {
				bfs_q.push(next_barn);
				visit[next_barn] = visit[curr_barn] + 1;
			}
		}
	}
}

int main() {
	cin >> vertex >> edges;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;

		network[from].push_back(to);
		network[to].push_back(from);
		// 헛간들은 양방향 이동 가능
	}

	bfs();
	int max_distance = 0, target_barn = 0, barn_cnt = 0;
	for (int i = 2; i <= vertex; i++) {
		if (visit[i] > max_distance) {
			max_distance = visit[i];
			target_barn = i;
			barn_cnt = 1;
		}
		else if (visit[i] == max_distance)
			barn_cnt++;
	}

	cout << target_barn << " " << max_distance - 1 << " " << barn_cnt;
	return 0;
}
