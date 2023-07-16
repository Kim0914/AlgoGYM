#include <iostream>
#include <queue>
using namespace std;

int min_time = 0, cnt = 0;
queue<pair<int, int>> bfs_q;
bool visit[100001];

bool validate(int pos) {
	if (pos >= 0 && pos <= 100000)
		return true;

	return false;
}

void bfs(int start, int goal) {
	bfs_q.push({ start, 0 });
	visit[start] = true;

	while (!bfs_q.empty()) {
		int curr = bfs_q.front().first;
		int timer = bfs_q.front().second;
		bfs_q.pop();
		visit[curr] = true;

		if (cnt != 0 && curr == goal && timer == min_time)
			cnt++;

		if (cnt == 0 && curr == goal) {
			// 처음으로 동생 위치에 도착한게 최소일 것!
			min_time = timer;
			cnt++;
		}

		if (validate(curr + 1) && !visit[curr + 1])
			bfs_q.push({ curr + 1, timer + 1 });
		if (validate(curr - 1) && !visit[curr - 1])
			bfs_q.push({ curr - 1, timer + 1 });
		if (validate(curr * 2) && !visit[curr * 2])
			bfs_q.push({ curr * 2, timer + 1 });
	}
}

int main() {
	int start = 0, goal = 0, timer = 0;
	cin >> start >> goal;

	bfs(start, goal);
	cout << min_time << '\n';
	cout << cnt;

	return 0;
}
