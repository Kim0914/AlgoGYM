#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

ll num = 0, wood_length = 0, max_length = 0, answer = 0;
ll woods[1000000];
ll cut_woods(ll mid) {
	ll wood_sum = 0;

	for (int i = 0; i < num; i++) {
		ll rest = woods[i] - mid;
		if(rest > 0)
			wood_sum += woods[i] - mid;
	}

	return wood_sum;
}

void binary_search() {
	ll left = 1, right = max_length;

	while (left <= right) {
		ll mid = (left + right) / 2;

		if (wood_length <= cut_woods(mid)) {
			// 이분탐색에서 왜 작은 쪽에서 답을 갱신해야 하는가?
			// 이 문제의 경우, cut_woods 보다 많거나 같아야 답이 될 수 있기 때문.
			answer = mid;
			left = mid + 1;
		}
		else 
			right = mid - 1;
	}
}

int main() {
	cin >> num >> wood_length;
	for (int i = 0; i < num; i++) {
		cin >> woods[i];
		max_length = max(max_length, woods[i]);
	}

	binary_search();
	cout << answer;

	return 0;
}
