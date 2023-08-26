#include <iostream>
#include <unordered_map>
using namespace std;

int num = 0, sequence[100001];
long long answer;
unordered_map<int, int> dupli_map;
int main() {
	int front_ptr = 0;

	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> sequence[i];

	for (int rear_ptr = 0; rear_ptr < num; rear_ptr++) {
		while (front_ptr < num) {
			if (dupli_map[sequence[front_ptr]] == 1)
				break; // 이미 있는 수면 바로 멈춤

			dupli_map[sequence[front_ptr]]++;
			front_ptr++;
		}

		answer += (front_ptr - rear_ptr);
		// 왜? 예를 들어, 1 12 123 1231로 훑는 경우라면?
		// 1 12 123 까지의 수열만 가능한 것이므로, 3개가 저장된다.
		dupli_map[sequence[rear_ptr]]--;
	}

	cout << answer;
	return 0;
}
