#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define ll long long

ll num = 0, x = 0, y = 0, answer = 0;
vector<pair<ll, ll>> line_infos;
stack<pair<ll, ll>> line_q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		line_infos.push_back({ x, y });
	}

	sort(line_infos.begin(), line_infos.end());
	// 선이 시작되는 위치 기준 오름차순

	ll start_point = line_infos[0].first; // 첫 시작
	ll end_point = line_infos[0].second; // 첫 끝
	for (int i = 0; i < line_infos.size(); i++) {
		while (!line_q.empty() && line_q.top().second < line_infos[i].first) {
			line_q.pop();

			if (line_q.empty()) {
				answer += (end_point - start_point);
				start_point = line_infos[i].first;
			}
		}

		line_q.push(line_infos[i]);
		end_point = max(line_q.top().second, end_point);
	}

	while (!line_q.empty()) {
		line_q.pop();

		if (line_q.empty())
			answer += (end_point - start_point);
	}

	cout << answer;
	return 0;
}
