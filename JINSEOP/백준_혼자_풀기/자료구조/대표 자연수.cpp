#include <iostream>
#include <queue>
using namespace std;

int num = 0, digit = 0;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<>> min_heap;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> digit;

		if (max_heap.size() == min_heap.size())
			max_heap.push(digit);
		// 둘의 크기가 같으면 짝수개의 수가 있다는 것
		// max_heap에 추가하도록 한다.
		else
			min_heap.push(digit);
		// min_heap의 원소 수가 하나 적은 것이므로 push

		if (!max_heap.empty() && !min_heap.empty()) {
		// 두 큐가 동시에 비어있지 않을 때
			if (max_heap.top() > min_heap.top()) {
			// 작은 수들 중 가장 큰 값(중간)이 큰 수들 중 가장 작은 값보다 크면?
		    // 둘은 위치가 바뀌어야 함.
				int max_val = max_heap.top();
				int min_val = min_heap.top();

				max_heap.pop(); min_heap.pop();
				max_heap.push(min_val); min_heap.push(max_val);
			}
		}
	}

	cout << max_heap.top();
	return 0;
}
