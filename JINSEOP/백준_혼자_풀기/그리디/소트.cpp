#include <iostream>
#include <algorithm>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int num = 0, limit = 0;
int seq[50];
int main() {
	OPTIMIZE;

	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> seq[i];
	cin >> limit;

	// 큰 수가 앞으로 올 수록 뒷순서로 간다.
	// 매 회차마다 가장 큰 값을 찾아 최대한 앞으로 옮긴다.
	int curr_idx = 0;
	while (curr_idx < num && limit > 0) {
	// 단, 중요한 점은 limit만큼 밖에 이동을 못하는 것!
		int max_idx = curr_idx;

		for (int i = curr_idx; i <= min(num - 1, curr_idx + limit); i++)
			if (seq[max_idx] < seq[i])
				max_idx = i;
		// 현재 index부터 배열 끝까지 탐색을 하거나, limit 까지만 탐색
		
		for (int i = max_idx; i > curr_idx; i--) {
			swap(seq[i], seq[i - 1]);
			limit--;
		// 위에서 계산된 index에 대해서 swap을 진행하며 limit 감소
		}
		
		curr_idx++;
		// 가장 큰 수를 최대한 앞으로 옮겼다면?
		// 가장 앞자리는 더 이상 건들 필요가 없으므로 index + 1
	}

	for (int i = 0; i < num; i++)
		cout << seq[i] << " ";
	return 0;
}
