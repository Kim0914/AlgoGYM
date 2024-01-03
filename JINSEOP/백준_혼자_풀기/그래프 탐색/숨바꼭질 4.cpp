#include <iostream>
#include <queue>
#include <string>
using namespace std;

int subin = 0, bro = 0;
bool visit[100001];
int parent[100001];
vector<int> shortest_path;
int calculate_pos(int opt, int target) {
	switch (opt)
	{
	case 0:
		return target - 1;
	case 1:
		return target + 1;
	case 2:
		return target * 2;
	}
}

void bfs() {
	queue<pair<int, int>> bfs_q;
	bfs_q.push({subin, 0});
	visit[subin] = true;

	while (!bfs_q.empty()) {
		int curr_pos = bfs_q.front().first;
		int curr_time = bfs_q.front().second;
		bfs_q.pop();

		if (curr_pos == bro) {
			int idx = curr_pos;

			while (idx != subin) {
				shortest_path.push_back(idx);
				idx = parent[idx];
        // 저장된 부모를 통해 경로를 역추적
			}
			cout << curr_time << '\n';

			return;
		}

		for (int i = 0; i < 3; i++) {
			int next_pos = calculate_pos(i, curr_pos);

			if (next_pos >= 0 && next_pos <= 100000) {
				if (!visit[next_pos]) {
					bfs_q.push({ next_pos, curr_time + 1 });
					visit[next_pos] = true;
					parent[next_pos] = curr_pos;
          // 부모를 저장하는 배열에 부모를 저장
				}
			}
		}
	}
}

int main() {
	cin >> subin >> bro;
	
	if (subin == bro) {
		cout << 0 << '\n';
		cout << bro;
	}
	else {
		bfs();
		cout << subin << " "; // 루트는 부모가 없음
		for (int i = shortest_path.size() - 1; i >= 0; i--)
			cout << shortest_path[i] << ' ';
	}

	return 0;
}
