#include <iostream>
#include <unordered_map>
using namespace std;

int num = 0, limit = 0, sequence[100001];
int front_ptr = 0, rear_ptr = 0, max_len = 0;
unordered_map<int, int> seq_map;
int main() {
	cin >> num >> limit;
	for (int i = 0; i < num; i++) {
		cin >> sequence[i];
	}

	while (rear_ptr < num) {
		while (front_ptr < num && seq_map[sequence[front_ptr]] < limit) {
			seq_map[sequence[front_ptr]]++;
			front_ptr++;
		}

		max_len = max(max_len, front_ptr - rear_ptr);
		if (front_ptr == num)
			break; // 더 이상 탐색하면 길이가 줄어들기만 함.

		seq_map[sequence[rear_ptr]]--;
		rear_ptr++;
	}

	cout << max_len;

	return 0;
}
