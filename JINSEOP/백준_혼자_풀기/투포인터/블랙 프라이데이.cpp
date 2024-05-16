#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll num = 0, limit = 0;
vector<int> item_vec;
int main() {
	cin >> num >> limit;

	ll weight = 0;
	for (int i = 0; i < num; i++) {
		cin >> weight;
		item_vec.push_back(weight);
	}
	sort(item_vec.begin(), item_vec.end());
	// 오름차순으로 정렬
	
	int front_ptr = 0, rear_ptr = item_vec.size() - 1;
	while (front_ptr < rear_ptr) {
		if (item_vec[front_ptr] + item_vec[rear_ptr] == limit) {
			cout << 1;
			return 0;
		} // 두 개 선택해서 끝낼 수 있는 경우

		for (int i = front_ptr + 1; i < rear_ptr; i++) {
			int sum = item_vec[front_ptr] + item_vec[rear_ptr] + item_vec[i];

			if (item_vec[front_ptr] == limit || item_vec[rear_ptr] == limit || item_vec[i] == limit) {
				cout << 1;
				return 0;
			} // 한 개 선택해서 끝낼 수 있는 경우

			if (sum == limit) {
				cout << 1;
				return 0;
			} // 세 개 선택해서 끝나는 경우
		}

		if (item_vec[front_ptr] + item_vec[rear_ptr] < limit)
			front_ptr++;
		else if (item_vec[front_ptr] + item_vec[rear_ptr] > limit)
			rear_ptr--;
		// 둘의 합이 limit보다 크면 줄여야 함, 볼 필요 없음
	}

	cout << 0;
	return 0;
}
