#include <iostream>
#include <queue>
using namespace std;
#define ll long long

ll depth = 0, dough = 0, each_dough = 0;
ll oven[300001];
int main() {
	cin >> depth >> dough;
	for (int i = 1; i <= depth; i++)
		cin >> oven[i];

	queue<int> oven_q;
	for (int i = 0; i < dough; i++) {
		cin >> each_dough;
		oven_q.push(each_dough);
	}

	int curr_width = oven[1];
	for (int i = 1; i <= depth; i++) {
		if (oven[i] >= curr_width)
			oven[i] = curr_width;
		else
			curr_width = oven[i];
	} // 여기서 오븐의 형태를 정제한다.

	int answer = 0;
	for (int i = depth; i >= 1; i--) {
		if (oven_q.empty()) {
			answer = i + 1;
			break;
		}

		if (oven_q.front() <= oven[i])
			oven_q.pop();
	}

	if (!oven_q.empty())
		cout << 0;
	else
		cout << answer;
	return 0;
}
