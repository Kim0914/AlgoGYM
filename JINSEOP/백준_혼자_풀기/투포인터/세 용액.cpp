#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define plll pair<pair<long long, long long>, long long>

int num = 0;
plll answer;
ll teammates[10000], min_sum = 9999999999;
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void two_pointer(int target) {
	int front_ptr = 0, rear_ptr = num - 1;

	while (front_ptr < target && rear_ptr > target) {
		ll sum = teammates[front_ptr] + teammates[target] + teammates[rear_ptr];

		if (abs(sum) < min_sum) {
			min_sum = abs(sum);
			answer = { {teammates[front_ptr], teammates[target]}, teammates[rear_ptr] };
		}

		if (sum < 0)
			front_ptr++;
		else if (sum > 0)
			rear_ptr--;
		else if (sum == 0)
			return;
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> teammates[i];

	sort(teammates, teammates + num);
	// 우선 포인터를 사용하기 위해 정렬이 필요하다.

	for (int i = 1; i < num - 1; i++)
		two_pointer(i);

	cout << answer.first.first << " " << answer.first.second << " " << answer.second;
	return 0;
}
