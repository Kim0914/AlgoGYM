#include <iostream>
#include <vector>
using namespace std;

int num = 0, dist = 0, from = 0, to = 0, cost = 0, answer = 0;
int dp[10001];
vector<pair<int, int>> info_vec[10001];
int main() {
	cin >> num >> dist;

	for (int i = 0; i < num; i++) {
		cin >> from >> to >> cost;	
		if (to > dist || to - from < cost)
			continue;
		// 도착 위치가 고속도로의 거리보다 멀면 갈 수 없다.
		// 또한 지름길의 거리가 기존 거리보다 길면 갈 필요가 없다.

		info_vec[to].push_back({ cost, from });
		// 양방향이 아님. 앞으로만 갈 수 있음
		// 목적지로부터 출발지를 탐색할 수 있도록 한다.
	}

	dp[0] = 0; // 시작지점
	for (int i = 1; i <= dist; i++) {
		dp[i] = dp[i - 1] + 1;
		// 기본적으로 앞으로 가는데, 거리 1을 할당한다.

		for (int j = 0; j < info_vec[i].size(); j++)
			dp[i] = min(dp[i], dp[info_vec[i][j].second] + info_vec[i][j].first);
		// 지름길이 존재하는 위치라면, 지름길을 살펴본다.
		// (지름길의 출발지 + 지름길 거리) vs 그냥 쭉 왔을 때 도착지까지의 거리
	}

	cout << dp[dist];
	return 0;
}
