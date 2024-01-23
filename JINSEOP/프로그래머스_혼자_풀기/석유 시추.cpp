#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
#define pii pair<int, int>

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
unordered_map<int, int> oil_counter;
bool visit[501][501];
int count_oil_area(int start_x, int start_y, vector<vector<int>>& land, int label) {
	queue<pii> bfs_q;
	bfs_q.push({ start_x, start_y });
	visit[start_x][start_y] = true;
	land[start_x][start_y] = label;
	int area = 1;

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if ((nx >= 0 && nx < land.size()) && (ny >= 0 && ny < land[0].size())) {
				if (!visit[nx][ny] && land[nx][ny]) {
					visit[nx][ny] = true;
					bfs_q.push({ nx, ny });
					land[nx][ny] = label;
					area++;
				}
			}
		}
	}

	return area;
}

int solution(vector<vector<int>> land) {
	int answer = 0;

	int label = 2;
	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[0].size(); j++)
			if (!visit[i][j] && land[i][j]) {
				oil_counter[label] = count_oil_area(i, j, land, label);
				label++;
			}
	}
	// 여기서 땅 속 석유량을 측정
  // 각 석유 덩어리들에 라벨을 달아주고, 맵에 총량 저장
  
	for (int i = 0; i < land[0].size(); i++) {
		int oil_sum = 0;
		set<int> oil_labels;
    // 원래는 다른 방식으로 계산했었는데, 실패했다.
    // 그래서 중복되는 라벨을 제거하기 위해 Set 자료구조 이용
    
		for (int j = 0; j < land.size(); j++) {
			if (land[j][i])
				oil_labels.insert(land[j][i]);
		}

		for (auto i : oil_labels)
			oil_sum += oil_counter[i];

		answer = max(answer, oil_sum);
	}
	// 여기서 열 별 최대 시추량을 계산한다.

	return answer;
}

int main() {
	solution({ {1, 0, 1, 0, 1, 1} ,{1, 0, 1, 0, 0, 0},{1, 0, 1, 0, 0, 1},{1, 0, 0, 1, 0, 0},{1, 0, 0, 1, 0, 1},{1, 0, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1}});
	return 0;
}
