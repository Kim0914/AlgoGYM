#include <string>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int, int>

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void bfs(int st_x, int st_y, vector<vector<string>>& board, int& answer) {
	queue<pii> bfs_q;
	bfs_q.push({ st_x, st_y });
	string target = board[st_x][st_y];

	for (int i = 0; i < 4; i++) {
		int nx = st_x + dx[i];
		int ny = st_y + dy[i];

		if ((nx >= 0 && nx < board.size()) && (ny >= 0 && ny < board[0].size())) {
			if (board[nx][ny] == target) {
				bfs_q.push({ nx, ny });
				answer++;
			}
		}
	}
}

int solution(vector<vector<string>> board, int h, int w) {
	int answer = 0;

	bfs(h, w, board, answer);
	return answer;
}

int main() {
	solution({ {"blue", "red", "orange", "red"}, {"red", "red", "blue", "orange"}, {"blue", "orange", "red", "red"}, {"orange", "orange", "red", "blue"}}, 
		1, 1);
	return 0;
}
