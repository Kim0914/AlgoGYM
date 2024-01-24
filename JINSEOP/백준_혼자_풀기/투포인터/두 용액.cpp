#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define MAX 99999999999

int num = 0;
int liquids[100000];
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> liquids[i];

	sort(liquids, liquids + num);
	// 일단 오름차순으로 정렬하자.

	pii answer_liquids;
	int front_ptr = 0, rear_ptr = num - 1;
	ll min_diff = MAX;
	while (front_ptr < rear_ptr) {
		ll diff = liquids[front_ptr] + liquids[rear_ptr];

		if (min_diff > abs(diff)) {
			min_diff = abs(diff);
			answer_liquids = { liquids[front_ptr], liquids[rear_ptr] };
		}

		if (diff > 0)
			rear_ptr--;
		// 용액을 합쳤는데 양수가 나오면, 더 작은 특성 값 필요
		else if (diff < 0)
			front_ptr++;
		// 음수가 나오면, 더 큰 음수 특성 값 필요
		else if (diff == 0)
			break;
		// 0이 나왔다는 것은 더 이상 탐색할 필요가 없음
	}

	cout << answer_liquids.first << " " << answer_liquids.second;
	return 0;
}
