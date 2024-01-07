#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertex = 0, edges = 0, from = 0, to = 0;
vector<int> network[501];
bool visit[501];
int bfs() {
	int answer = 0;
	queue<pair<int, int>> bfs_q;
	bfs_q.push({ 1, 0 }); // 상근이의 학번
	// 친구거리는 본인이므로 0
	visit[1] = true;

	while (!bfs_q.empty()) {
		int curr_person = bfs_q.front().first;
		int curr_distance = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < network[curr_person].size(); i++) {
			int next_person = network[curr_person][i];
			int next_distance = curr_distance + 1;
			
			if (!visit[next_person] && next_distance <= 2) {
				// 친구의 친구까지만 초대, 거리가 2보다 작아야함
				answer++;
				bfs_q.push({ next_person, next_distance});
				visit[next_person] = true;
			}
		}
	}

	return answer;
}

int main() {
	cin >> vertex >> edges;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;

		network[from].push_back(to);
		network[to].push_back(from);
		// 친구관계는 양방향이다.
	}

	cout << bfs();
	return 0;
}
