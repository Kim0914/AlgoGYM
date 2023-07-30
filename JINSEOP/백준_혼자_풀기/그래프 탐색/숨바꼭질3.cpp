#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> bfs_q;
bool visit[100001];
int min_time = 999999;

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

		if (curr == goal)
      // 이젠 처음 만나는 시점이 최소 시간이라는 보장이 없다.
      // 따라서, 최소 시간을 갱신하며 계속 진행한다.
			min_time = min(min_time, timer);

		if (validate(curr + 1) && !visit[curr + 1])
			bfs_q.push({ curr + 1, timer + 1 });
		if (validate(curr - 1) && !visit[curr - 1])
			bfs_q.push({ curr - 1, timer + 1 });
		if (validate(curr * 2) && !visit[curr * 2])
			bfs_q.push({ curr * 2, timer});
	}
}

int main() {
	int start = 0, goal = 0;
	cin >> start >> goal;

	bfs(start, goal);
	cout << min_time;

	return 0;
}
