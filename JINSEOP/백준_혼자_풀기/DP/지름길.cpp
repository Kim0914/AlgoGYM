#include <iostream>
#include <vector>
using namespace std;

int num = 0, dist = 0, src = 0, dest = 0, weight = 0;
vector<pair<int, int>> shortcut[10001];
int min_dist[10001];
int main() {
	cin >> num >> dist;
	
	for (int i = 0; i < num; i++) {
		cin >> src >> dest >> weight;
		if (dest > dist || dest - src < weight)
			continue; // 역주행 불가능, 거리보다 가중치가 긴 경우 제외
		shortcut[dest].push_back({ src, weight });
	}

	min_dist[0] = 0;// 시작 지점
	for (int i = 1; i <= dist; i++) { // 도착할 때 까지
		min_dist[i] = min_dist[i - 1] + 1; // 지름길이 없으면 그냥 + 1

		for (int j = 0; j < shortcut[i].size(); j++)
			min_dist[i] = min(min_dist[i], min_dist[shortcut[i][j].first] + shortcut[i][j].second);
		// 해당 목적지(i)에 지름길이 있다면 해당 지름길을 훑는다.
		// 이전 도착지 (.first) + 현재 도착지까지 지름길을 탔을 때 거리로.
	}

	cout << min_dist[dist];
	return 0;
}
