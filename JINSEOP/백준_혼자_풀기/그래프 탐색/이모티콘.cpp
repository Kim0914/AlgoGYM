#include <iostream>
#include <queue>
#define LIMIT 2001 // 왜? 클립보드 길이 제한 1000 + 1000
using namespace std;

queue<pair<int, pair<int, int>>> bfs_q; // {클립보드, {길이, 시간}}
bool visit[2001][2001]; // 방문체크를 해야 메모리 초과가 안남!!
// 왜? 빼고 더하고 하다보면, 이미 들렀던 상황에 다시 가버릴 수가 있다! 이는 시간낭비
void bfs(int limit) {
	bfs_q.push({ 0, { 1, 0 } });
	visit[1][0] = true; // 현재 이모티콘, 클립보드 방문

	while (!bfs_q.empty()) {
		int clip_board = bfs_q.front().first;
		int curr = bfs_q.front().second.first;
		int curr_time = bfs_q.front().second.second;
		bfs_q.pop();

		if (curr == limit) {
			cout << curr_time;
			return;
		}

		if (curr > 0) {
			if (curr < LIMIT) {
				if (!visit[curr][curr]) {
					visit[curr][curr] = true; // 현재 이모티콘, 저장될 클립보드
					bfs_q.push({ curr, { curr ,curr_time + 1 } }); // 클립보드에 저장
				}
				if (!visit[curr - 1][clip_board] && curr - 1 >= 0) {
					visit[curr - 1][clip_board] = true;
					bfs_q.push({ clip_board, { curr - 1, curr_time + 1} }); // 이모티콘 하나 삭제
				}
			}
			if (curr + clip_board < LIMIT) {
				if (!visit[curr + clip_board][clip_board] && clip_board != 0) {
					visit[curr + clip_board][clip_board] = true;
					bfs_q.push({ clip_board, { curr + clip_board, curr_time + 1 } }); // 클립보드에 있는 거 복붙
				}
			}
		}
	}
}

int main() {
	int num = 0;

	cin >> num;
	bfs(num);

	return 0;
}
