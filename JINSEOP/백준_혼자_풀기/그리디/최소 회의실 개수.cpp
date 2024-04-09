#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pii pair<int, int>

int num = 0;
int main() {
	OPTIMIZE;

	cin >> num;

	int from = 0, to = 0;
	vector<pii> times;
	for (int i = 0; i < num; i++) {
		cin >> from >> to;
		times.push_back({ from, to });
	}
	sort(times.begin(), times.end());
	// 시작시간 기준으로 정렬

	priority_queue<int, vector<int>, greater<>> conf_rooms;
	int answer = 0;
	for (int i = 0; i < num; i++) {
		while (!conf_rooms.empty() && conf_rooms.top() <= times[i].first)
			conf_rooms.pop();
		// 다음 회의 시작시간에 대해서 끝나는 시간보다 뒤면 pop
		
		conf_rooms.push(times[i].second);
		int size = conf_rooms.size();
		answer = max(answer, size);
	}

	cout << answer;
	return 0;
}
