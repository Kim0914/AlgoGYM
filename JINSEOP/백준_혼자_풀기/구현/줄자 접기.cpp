#include <iostream>
#include <cmath>
using namespace std;

double ruler_length = 0;
pair<double, double> dots_pair[3];
double fold_dots(double fold_point, double target) {
	return fold_point + fabs(fold_point - target);
}

void fold_ruler(int color, double& left, double& right) {
	if (dots_pair[color].first == dots_pair[color].second)
		return;
	// 점 위치가 이미 겹쳤으면 탐색 안해도 됨

	double fold_point = (dots_pair[color].first + dots_pair[color].second) / 2;
	for (int i = color + 1; i < 3; i++) {
	// 현재 색부터 노랑색까지 쭉 탐색
		dots_pair[i].first = fold_dots(fold_point, dots_pair[i].first);
		dots_pair[i].second = fold_dots(fold_point, dots_pair[i].second);
	}

	left = fold_dots(fold_point, left);
	if (left > right)
		right = left;
	left = fold_point;
	// 종이를 접었을 때, 양 쪽 끝 위치를 변경한다.
}

int main() {
	cin >> ruler_length;
	double left = 0, right = ruler_length;

	for (int i = 0; i < 3; i++)
		cin >> dots_pair[i].first >> dots_pair[i].second;

	for (int i = 0; i < 3; i++)
		fold_ruler(i, left, right); // 빨 파 노 순서대로 접음

	double res = right - left;
	// 결과를 출력하는 부분이 약간 어렵다.
	cout << fixed;
	cout.precision(1);
	// 소수점 아래로 1자리까지 출력
	cout << res;
	return 0;
}
