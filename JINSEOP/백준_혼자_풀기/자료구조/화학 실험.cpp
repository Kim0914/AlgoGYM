#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int num = 0, colors = 0, each_color = 0;
priority_queue<pair<int, int>> cylinder_q;
stack<int> cylinder_st;
int main() {
	cin >> num >> colors;
	for (int i = 1; i <= colors; i++) {
		cin >> each_color;
		cylinder_q.push({ each_color, i });
		// 우선 순위 큐에 집어넣는다.
	}

	while (!cylinder_q.empty()) {
		int curr_color = cylinder_q.top().first;
		int curr_num = cylinder_q.top().second;
		cylinder_q.pop();

		if (cylinder_q.empty()) {
			if (curr_color > 1)
				break;
			else
				cylinder_st.push(curr_num);
		}
		else {
			int next_color = cylinder_q.top().first;
			int next_num = cylinder_q.top().second;
			cylinder_q.pop();

			cylinder_st.push(curr_num);
			if (curr_color > 1)
				cylinder_q.push({ curr_color - 1, curr_num });

			cylinder_st.push(next_num);
			if (next_color > 1)
				cylinder_q.push({ next_color - 1, next_num });
		}
	// 두 개를 뽑지 않으면, 동일한 개수의 시험관이 여러개일 때
	// 어느 것을 우선적으로 뽑는 지 보장할 수가 없다.
	}

	if (cylinder_st.size() < num)
		cout << -1;
	else {
		while (!cylinder_st.empty()) {
			cout << cylinder_st.top() << " ";
			cylinder_st.pop();
		}
	}

	return 0;
}
