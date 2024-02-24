#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define pii pair<int, int>

int solution(int n, vector<int> cores) {
	int answer = 0;

	if (n <= cores.size())
		return n;

	int left_v = 0, right_v = 50000;
	while (left_v + 1 < right_v) {
		int mid = (left_v + right_v) / 2;
		int std = cores.size(); // 기본적으로 진행하는 작업

		for (int i = 0; i < cores.size(); i++)
			std += mid / cores[i];
		// 작업 시간 내에 해당 코어가 몇 개의 작업을 처리할 수 있는지?

		if (std < n)
			left_v = mid;
		// 작업을 모두 끝낼 수 없다면 작업 시간을 늘려야 한다.
		else
			right_v = mid;
		// 작업을 모두 끝낼 수 있다면 작업 시간을 줄인다.
	}

	int std = cores.size(); // 기본 작업
	for (int i = 0; i < cores.size(); i++)
		std += left_v / cores[i];
	// 최대 시간 내에 처리할 수 있는 작업의 수
	for (int i = 0; i < cores.size(); i++) {
		if ((left_v + 1) % cores[i] == 0)
			std++;
	// 최대 시간 + 1의 시점에 작업 처리가 가능한 코어를 찾는다.
		if (std == n)
			return i + 1;
	// 그 중 마지막 코어
	}

	return 0;
}

int main() {
	solution(6, {1,2,3});
	return 0;
}
