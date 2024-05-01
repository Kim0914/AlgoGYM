#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, colors = 0;
int color_jewels[300000];
int main() {
	cin >> num >> colors;
	for (int i = 0; i < colors; i++)
		cin >> color_jewels[i];
	sort(color_jewels, color_jewels + colors);
	// 오름차순으로 정렬

	int answer = 0;
	int left_v = 1, right_v = color_jewels[colors - 1];
		
	while (left_v <= right_v) {
		int mid = (left_v + right_v) / 2;

		int kids = 0;
		for (int i = 0; i < colors; i++) {
			kids += (color_jewels[i] / mid);
			// mid 값이 질투심이라면, 보석 / mid 명이 받을 수 있다.
			if (color_jewels[i] % mid != 0)
					kids++;
			// 나머지가 0이 아니라면 한명 더 받을 수 있다.
		}
			
		if (kids <= num) {
			right_v = mid - 1;
			answer = mid;
		}
		else
			left_v = mid + 1;
	}

	cout << answer;
	return 0;
}
