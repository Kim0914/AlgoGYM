#include <iostream>
using namespace std;

int tc = 0;
string target = "";
bool fold_paper(int start, int end) {
	if (start >= end)
		return true;
  // 이 경우는, 끝까지 모든 면을 다 탐색한 경우

	int left = start, right = end;
	while (left < right) {
		if (target[left] == target[right])
			return false;
    // 우선 각 면을 탐색할 때마다, 반대편은 반드시 다른 모양이어야 한다.
    // 왜? 제대로 접혔다면 한 쪽이 IN이라면 겹치는 면은 반드시 OUT 일 것
		left++; right--;
	}

	return fold_paper(start, right - 1);
  // 재귀를 하는 이유는 각 면도 올바르게 접혔는지 확인하기 위함이다.
  // 예를 들어, 3번 접었다면 총 7개의 접히는 구간이 나오게 될 텐데
  // 처음 7개를 확인한 뒤, 절반인 3개를 확인해야만 한다.
  // 절반인 3개를 확인했을 때도 올바르게 001 / 100과 같이 겹쳐있어야 하기 때문이다.
  // 그래서 이 문제는 분할 정복 문제!
}

int main() {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> target;
		// 핵심은 접히는 부분끼리는 반대 모양이어야 한다는 것!

		if (target.size() == 1) {
			cout << "YES" << '\n';
			continue; // 하나 짜리는 그냥 접을 수 있음
		}

		if (target.size() % 2 == 0) {
			cout << "NO" << '\n';
			continue; // 짝수는 그냥 못 접음
		}

		if (fold_paper(0, target.size() - 1))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}
