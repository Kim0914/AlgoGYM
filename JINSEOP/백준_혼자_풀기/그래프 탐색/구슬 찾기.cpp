#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 200

int num = 0, pair_num = 0, heavy = 0, light = 0;
bool visit[100];
void clear_visit() {
	for (int i = 1; i <= num; i++)
		visit[i] = false;
}

int bfs(int start_node, vector<int> target_arr[100]) {
	clear_visit();

	int cnt = 0;
	queue<int> bfs_q;
	bfs_q.push(start_node);
	visit[start_node] = true;

	while (!bfs_q.empty()) {
		int curr_node = bfs_q.front();
		bfs_q.pop();

		for (int i = 0; i < target_arr[curr_node].size(); i++) {
			int next_node = target_arr[curr_node][i];
			if (!visit[next_node]) {
				bfs_q.push(next_node);
				visit[next_node] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	cin >> num >> pair_num;

	vector<int> heavy_marble[100], light_marble[100];
	for (int i = 0; i < pair_num; i++) {
		cin >> heavy >> light;
		heavy_marble[light].push_back(heavy);
		light_marble[heavy].push_back(light);
	}
	
	int answer = 0;
	for (int i = 1; i <= num; i++) {
		int heavy_cnt = bfs(i, heavy_marble);
		int light_cnt = bfs(i, light_marble);

		if (heavy_cnt > ((num - 1) / 2) || light_cnt > ((num - 1) / 2))
			answer++;
	}

	cout << answer;
	return 0;
}
