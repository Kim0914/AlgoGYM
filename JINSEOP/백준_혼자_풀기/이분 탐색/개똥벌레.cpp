#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int stalagmite[100001], stalactite[100001];
int cave_length = 0, cave_height = 0;
int count_stalagmite(int height) {
	int left_v = 0, right_v = (cave_length / 2) - 1;
	
	while (left_v <= right_v) {
		int mid = (left_v + right_v) / 2;

		if (stalagmite[mid] < height)
			left_v = mid + 1;
		else
			right_v = mid - 1;
	}

	return (cave_length / 2) - left_v;
}

int count_stalactite(int height) {
	int left_v = 0, right_v = (cave_length / 2) - 1;

	while (left_v <= right_v) {
		int mid = (left_v + right_v) / 2;

		if (stalactite[mid] < height)
			left_v = mid + 1;
		else
			right_v = mid - 1;
	}

	return (cave_length / 2) - left_v;
}

int main() {
	cin >> cave_length >> cave_height;

	for (int i = 0; i < cave_length; i++) {
		if (i % 2 == 0)
			cin >> stalagmite[i / 2];
		else
			cin >> stalactite[i / 2];
	}

	sort(stalagmite, stalagmite + (cave_length / 2));
	sort(stalactite, stalactite + (cave_length / 2));

	int min_collision = 99999999;
	int cnt = 0;
	for (int i = 1; i <= cave_height; i++) {
		int collision_count = count_stalagmite(i) + count_stalactite(cave_height - i + 1);
		// 석순은 바닥부터 체크, 종유석은 위 부터 체크
		// 이분탐색을 통해서, 현재 높이에서 부딪힐 수 있는 장애물의 개수를 찾는다.
		// 정렬된 배열 속에서 현재 높이보다 작은 장애물이 처음 등장하는 인덱스를 반환받는다.
		// 그럼 해당 인덱스 이전의 장애물은 모두 부딪힐 것!

		if (min_collision > collision_count) {
			min_collision = collision_count;
			cnt = 1;
		}
		else if (min_collision == collision_count)
			cnt++;
	}

	cout << min_collision << " " << cnt;
	return 0;
}
