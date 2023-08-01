#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll num = 0, limit = 0, lesson = 0, sum = 0, answer = 9999999999;
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

void binary_search(ll left, ll right) {
	if (left > right)
		return;

	ll mid = (left + right) / 2;
	ll lesson_cnt = checksum(mid);

	if (lesson_cnt <= limit)
		binary_search(left, mid - 1);
	else {
		answer = mid + 1;
		binary_search(mid + 1, right);
	}
}

int main() {
	cin >> num >> limit;
	for (int i = 0; i < num; i++) {
		cin >> lesson;
		sum += lesson;
		lessons.push_back(lesson);
	}

	binary_search(1, sum); // 최소 1분, 최대 합분까지
	cout << answer;

	return 0;
}
