#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> bfs_q;
bool visit[100001];

bool validate(int pos) {
	if (pos >= 0 && pos <= 100000)
		return true;

	return false;
}

int bfs(int start, int goal) {
	bfs_q.push({ start, 0 });
	visit[start] = true;

	while (!bfs_q.empty()) {
		int curr = bfs_q.front().first;
		int timer = bfs_q.front().second;
		bfs_q.pop();
		visit[curr] = true;

		if (curr == goal)
			// 처음 만나는 동생이 최소 시간
			return timer;

		if (validate(curr + 1) && !visit[curr + 1])
			bfs_q.push({ curr + 1, timer + 1 });
		if (validate(curr - 1) && !visit[curr - 1])
			bfs_q.push({ curr - 1, timer + 1 });
		if (validate(curr * 2) && !visit[curr * 2])
			bfs_q.push({ curr * 2, timer + 1 });
	}
}

int main() {
	int start = 0, goal = 0;
	cin >> start >> goal;

	int timer = bfs(start, goal);
	cout << timer << '\n';

	return 0;
}
