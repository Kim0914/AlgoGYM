#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

int num = 0, from = 0, to = 0, answer = 0, last_day = 0;
int calender[366];
vector<pii> todo_list;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> from >> to;
		todo_list.push_back({ from, to });
		last_day = max(to, last_day);
	}
	sort(todo_list.begin(), todo_list.end());
	// 시작일 기준으로 정렬해야 함

	for (auto todo : todo_list) {
		for (int i = todo.first; i <= todo.second; i++)
			calender[i]++;
		// 일정이 있는 날에 달력에 표시를 함
	}

	int height = 0, width = 0;
	for (int i = 1; i <= last_day; i++) {
		if (calender[i]) {
			height = max(height, calender[i]);
			width++;
		}

		if (!calender[i] || i == last_day) {
			answer += (height * width);
			height = 0;
			width = 0;
		}
	}

	cout << answer;
	return 0;
}
