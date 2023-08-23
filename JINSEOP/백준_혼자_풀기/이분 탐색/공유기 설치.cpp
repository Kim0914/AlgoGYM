#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int home_num = 0, ap_num = 0, loc = 0, ap_count = 0, answer = 0, curr = 0;
vector<int> home_map;
int main() {
	cin >> home_num >> ap_num;
	for (int i = 0; i < home_num; i++) {
		cin >> loc;
		home_map.push_back(loc);
	} // 집 위치 저장
	
	sort(home_map.begin(), home_map.end());
	// 집 위치를 오름차순으로 정렬한다.

	int left = 1; // 최소 거리
	int right = home_map[home_num - 1] - home_map[0]; // 최대 거리
	while (left <= right) {
		curr = 0; // 첫 집에는 반드시 공유기 설치
		ap_count = 1; // 시작하는 위치에 반드시 설치가 되어야 하므로 공유기 수는 1
		int mid = (left + right) / 2;

		for (int i = 1; i < home_map.size(); i++) {
			if (home_map[i] - home_map[curr] >= mid) {
				ap_count++; // mid를 지난 위치에 공유기를 설치할 수 있으면 설치
				curr = i; // 현재 위치 변경(계속 mid 이상의 거리 유지가 가능한지 판단)
			}
		}

		if (ap_count >= ap_num) { // 제한 갯수 이상 설치 되었다면?
			answer = max(answer, mid); // 일단 답은 맞으므로 갱신
			left = mid + 1; // 간격이 너무 좁다는 말! 넓히자.
		}
		else
			right = mid - 1; // 제한 갯수를 채우지 못하면 간격이 너무 넓으므로 좁힌다.
	}

	cout << answer;

	return 0;
}
