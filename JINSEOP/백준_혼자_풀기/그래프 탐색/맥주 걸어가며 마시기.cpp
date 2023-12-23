#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int tc = 0, conv_num = 0;
pair<int, int> home, conv, fest;
vector<pair<int, int>> conv_list;
bool visit[100];
void clear_visit() {
	for (int i = 0; i < conv_list.size(); i++)
		visit[i] = false;
}

bool check_conv(int x, int y) {
	for (int i = 0; i < conv_list.size(); i++)
		if (x == conv_list[i].first && y == conv_list[i].second)
			return true;

	return false;
}

void bfs() {
	queue<pair<int, int>> bfs_q;
	bfs_q.push({home.first, home.second});
	// 집에서 시작

	while (!bfs_q.empty()) {
		int curr_x = bfs_q.front().first;
		int curr_y = bfs_q.front().second;
		bfs_q.pop();

		if (abs(curr_x - fest.first) + abs(curr_y - fest.second) <= 1000) {
			cout << "happy" << '\n';
			return; // 맨해튼 거리 1000 이내에 페스티벌이 있으면 종료
		}

		for (int i = 0; i < conv_list.size(); i++) {
			if (curr_x == conv_list[i].first && curr_y == conv_list[i].second)
				continue;
			// 현재 위치랑 같은 편의점은 패스
			if (visit[i])
				continue; // 이미 방문했던 편의점 패스

			if (abs(curr_x - conv_list[i].first) + abs(curr_y - conv_list[i].second) <= 1000) {
				bfs_q.push({conv_list[i].first, conv_list[i].second});
				visit[i] = true;
			} // 다음 편의점과의 맨해튼 거리가 1000 이하면 이동 가능. (50 * 20)
		}
	}

	cout << "sad" << '\n';
}

int main() {
	cin >> tc;
	while (tc--) {
		int x = 0, y = 0;
		cin >> conv_num;

		cin >> x >> y;
		home = { x, y };

		for (int i = 0; i < conv_num; i++) {
			cin >> x >> y;
			conv = { x, y };
			conv_list.push_back(conv);
		}

		cin >> x >> y;
		fest = { x, y };

		bfs();
		clear_visit();
		conv_list.clear();
	}
}
