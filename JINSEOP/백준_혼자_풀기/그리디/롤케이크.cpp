#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int num = 0, limit = 0;
int main()
{
	cin >> num >> limit;

	int length = 0, answer = 0;
	priority_queue<int, vector<int>, greater<>> ten_rollcakes, rest_rollcakes;
	queue<int> rollcakes;
	for (int i = 0; i < num; i++) {
		cin >> length;
		if (length < 10)
			continue;
		if (length == 10)
			answer++;
		else if (length % 10 == 0)
			ten_rollcakes.push(length);
		else
			rest_rollcakes.push(length);
    // 10의 배수인 롤케이크를 먼저 자르는게 이득이다.
    // 왜? 10의 배수는 잘라도 남지 않아서, 1회 아낄 수 있기 때문
	}

	while (!ten_rollcakes.empty()) {
		rollcakes.push(ten_rollcakes.top());
		ten_rollcakes.pop();
	}

	while (!rest_rollcakes.empty()) {
		rollcakes.push(rest_rollcakes.top());
		rest_rollcakes.pop();
	}

	while ((limit > 0) && !rollcakes.empty()) {
		int cursor = rollcakes.front();
		int diff = cursor / 10;

		if (cursor % 10 == 0) {
		// 10의 배수일 경우, 자투리가 남지 않음
			if (limit < (diff - 1)) {
				answer += limit;
				break;
			}
			else {
				answer += diff;
				limit -= (diff - 1);
			}
		}
		else {
		// 10의 배수가 아닐 경우, 자투리가 남음 (한 번 더 잘라야함)
			if (limit < diff) {
				answer += limit;
				break;
			}
			else {
				answer += diff;
				limit -= diff;
			}
		}

		rollcakes.pop();
	}

	cout << answer;
	return 0;
}
