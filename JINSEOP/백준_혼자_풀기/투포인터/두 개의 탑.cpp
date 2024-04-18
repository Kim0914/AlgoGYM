#include <iostream>
#include <cmath>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int num = 0, whole_dist = 0;
int tower_info[50001];
int main() {
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> tower_info[i];
		whole_dist += tower_info[i];
	}

	int max_dist = 0, curr_dist = 0, left_ptr = 1;
	for (int right_ptr = 1; right_ptr <= num; right_ptr++) {
		curr_dist += tower_info[right_ptr];
		whole_dist -= tower_info[right_ptr];
		max_dist = max(max_dist, min(curr_dist, whole_dist));

		// left_ptr을 늘리면 whole_dist가 늘어난다.
		// right_ptr을 늘리면 whole_dist가 줄어든다.
		// 그럼 포인터를 옮겨야 할 때의 기준은?
		if (curr_dist == whole_dist)
			break; // 합이 같으면 중단

		while (curr_dist > whole_dist) {
			whole_dist += tower_info[left_ptr];
			curr_dist -= tower_info[left_ptr];
			left_ptr++;
		} // curr_dist가 더 커졌을 경우, 포인터를 옮긴다.
		max_dist = max(max_dist, min(curr_dist, whole_dist));
	}

	cout << max_dist;
	return 0;
}
