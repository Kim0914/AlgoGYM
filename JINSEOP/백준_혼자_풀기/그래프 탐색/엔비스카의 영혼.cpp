#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int num = 0, a = 0, b = 0;
bool visit[1000001];
int bfs() {
	queue<pii> bfs_q;
	bfs_q.push({num, 0});
	// 앞에 있는 사람 수, 걸린 시간

	while (!bfs_q.empty()) {
		int curr_wait = bfs_q.front().first;
		int curr_time = bfs_q.front().second;
		bfs_q.pop();

		if (curr_wait == 0)
			return curr_time;

		int nx_wait = curr_wait - 1;
		if (!visit[nx_wait]) {
			bfs_q.push({ nx_wait, curr_time + 1 }); // 기다리기
			visit[nx_wait] = true;
		}
		if (nx_wait - a >= 0 && !visit[nx_wait - a]) {
			bfs_q.push({ nx_wait - a, curr_time + 1 }); // a만큼 새치기
			visit[nx_wait - a] = true;
		}
		if (nx_wait - b >= 0 && !visit[nx_wait - b]) {
			bfs_q.push({ nx_wait - b, curr_time + 1 }); // b만큼 새치기
			visit[nx_wait - b] = true;
		}
	}
}

int main() {
	cin >> num >> a >> b;

	cout << bfs();
	return 0;
}
