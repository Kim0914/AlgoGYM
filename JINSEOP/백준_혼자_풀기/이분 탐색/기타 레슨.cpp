#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll num = 0, limit = 0, lesson = 0, sum = 0;
vector<int> lessons;

ll checksum(ll mid) {
	ll temp_sum = 0, cnt = 0;

	for (int i = 0; i < lessons.size(); i++) {
		if (temp_sum + lessons[i] > mid) {
			temp_sum = 0;
			cnt++;
		}

		temp_sum += lessons[i];
	}

	if (temp_sum != 0)
		cnt++;

	return cnt;
}

void binary_search(ll left, ll right, ll &result) {
	if (left > right)
		return;

	ll mid = (left + right) / 2;
	ll lesson_cnt = checksum(mid);

	if (lesson_cnt <= limit)
		binary_search(left, mid - 1, result);
	else {
		result = mid + 1;
		binary_search(mid + 1, right, result);
	}
}

int main() {
	ll init_left = -1;
	cin >> num >> limit;
	for (int i = 0; i < num; i++) {
		cin >> lesson;
		sum += lesson;
		init_left = max(init_left, lesson); // 핵심은 여기! 왼쪽 끝이 가장 큰 레슨이어야 한다.
		lessons.push_back(lesson);
	}

	ll result = init_left; // 정답을 왼쪽 끝으로 초기화
	binary_search(init_left, sum, result); // 최소 1분, 최대 합분까지
	cout << result;

	return 0;
}
