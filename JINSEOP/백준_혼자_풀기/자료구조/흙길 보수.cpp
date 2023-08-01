#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num = 0, len = 0, st = 0, end = 0, wood_count = 0, wood_cursor = 0;
	vector<pair<int, int>> pits;

	cin >> num >> len;
	for (int i = 0; i < num; i++) {
		cin >> st >> end;
		pits.push_back({ st, end });
	}

	sort(pits.begin(), pits.end()); // 시작 지점을 기준으로 웅덩이 정렬

	for (int i = 0; i < pits.size(); i++) {
		if (pits[i].first > wood_cursor)
			wood_cursor = pits[i].first; // 웅덩이의 시작지점에 나무를 놓는다.

		while (pits[i].second > wood_cursor) {
			wood_cursor += len; // 웅덩이에 나무를 하나씩 놓는다.
			wood_count++; // 웅덩이가 다 덮힐 때 까지 나무를 추가한다.
		}
	}

	cout << wood_count; // 단속 카메라와 유사한 문제였다.
	return 0;
}
