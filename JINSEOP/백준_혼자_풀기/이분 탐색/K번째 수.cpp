#include <iostream>
using namespace std;

long long num, k, lower_count;
long long count_lower(long long target) {
	long long cnt = 0;

	for (int i = 1; i <= num; i++)
		cnt += min(target / i, num); 
  // 주어진 2차원 배열을 기준으로 생각한다.
  // 2차원 배열의 한 행을 넘어가는 경우는 num을 더하고
  // 넘어가지 않는 경우에는 target / i, 즉 해당 수보다 작은 수까지 개수를 더한다.

	return cnt;
}

int main() {
	cin >> num >> k;

	long long left = 1;
	long long right = num * num; // 최대 수
	long long answer = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		lower_count = count_lower(mid);
		// mid 값보다 작거나 같은 수를 셈 (k보다 큰 지 작은 지)

		if (lower_count >= k) {
			answer = mid; // k값과 동일해지는 순간 답을 저장한다.
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << answer; // 답을 출력
	return 0;
}
