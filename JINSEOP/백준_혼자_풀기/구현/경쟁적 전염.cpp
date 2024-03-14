#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

int row = 0, virus_num = 0, sec = 0, x = 0, y = 0;
int virus_map[201][201];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visit[201][201];
queue<pii> viruses[1001];
void contagious(queue<pii>& virus_pos) {
	queue<pii> bfs_q;
	while(!virus_pos.empty()) {
		bfs_q.push(virus_pos.front());
		virus_pos.pop();
	}

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		int curr_idx = virus_map[curr_x][curr_y];
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 1 && nx <= row) && (ny >= 1 && ny <= row)) {
				if (!visit[nx][ny] && virus_map[nx][ny] == 0) {
					virus_pos.push({ nx, ny });
					virus_map[nx][ny] = curr_idx;
					visit[nx][ny] = true;
				}
			}
		}
	}
}


int main() {
	cin >> row >> virus_num;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= row; j++) {
			cin >> virus_map[i][j];
			
			if (virus_map[i][j] != 0)
				viruses[virus_map[i][j]].push({ i, j });
		}
	}
	cin >> sec >> x >> y;

	while (sec--) {
		for (int i = 1; i <= virus_num; i++)
			contagious(viruses[i]);
		// 앞에서 부터 순서대로 전염시키기 위함
	}

	cout << virus_map[x][y];
	return 0;
}
