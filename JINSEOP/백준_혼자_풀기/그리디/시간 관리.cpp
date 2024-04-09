#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pii pair<int, int>

int num = 0, process_time = 0, deadline = 0;
int main() {
	OPTIMIZE;
	vector<pii> task_vec;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> process_time >> deadline;
		task_vec.push_back({ deadline, process_time });
	}
	sort(task_vec.begin(), task_vec.end(), greater<>());

	int finish_time = 1000001;
	bool can_finish = true;
	for (int i = 0; i < num; i++) {
		if (finish_time > task_vec[i].first)
			finish_time = task_vec[i].first;
		// 끝난 시간이 더 작은 경우엔 옮겨줘야 함

		finish_time = finish_time - task_vec[i].second;

		if (finish_time < 0) {
			can_finish = false;
			break;
		}
	}

	if (!can_finish)
		cout << -1;
	else
		cout << finish_time;
	return 0;
}
