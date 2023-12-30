#include <iostream>
#include <cmath>
using namespace std;

double ruler_length = 0;
pair<double, double> red_dots;
pair<double, double> blue_dots;
pair<double, double> yellow_dots;
bool fold_state[3];
int main() {
	cin >> ruler_length;
	cin >> red_dots.first >> red_dots.second;
	cin >> blue_dots.first >> blue_dots.second;
	cin >> yellow_dots.first >> yellow_dots.second;

	// 빨간 걸 먼저 접자. 접을 때 점 위치 모두 옮기기
	double fold_point = (red_dots.first + red_dots.second) / 2;
	double left = 0, right = ruler_length;
	fold_state[0] = true;

	blue_dots.first = fold_point + fabs(fold_point - blue_dots.first);
	blue_dots.second = fold_point + fabs(fold_point - blue_dots.second);

	yellow_dots.first = fold_point + fabs(fold_point - yellow_dots.first);
	yellow_dots.second = fold_point + fabs(fold_point - yellow_dots.second);

	// 접힌 길이는 어떻게 계산?
	// 둘 중 더 큰 쪽이 접힌 길이가 된다.
	if (fold_point < (left + right) / 2)
		left = fold_point;
	else
		right = fold_point;

	
	// 중요한 것은, 접었을 때 점 위치를 반대편으로 옮겨주어야 한다.
	if (blue_dots.first == blue_dots.second)
		fold_state[1] = true;
	// 파란 게 맞았는지 확인
	if (yellow_dots.first == yellow_dots.second)
		fold_state[2] = true;
	// 노란 게 맞았는지 확인

	if (!fold_state[1]) {
	// 파란 게 아직 안접혔으면
		fold_point = (blue_dots.first + blue_dots.second) / 2;
		fold_state[1] = true;

		yellow_dots.first = fold_point + fabs(fold_point - yellow_dots.first);
		yellow_dots.second = fold_point + fabs(fold_point - yellow_dots.second);

		if (yellow_dots.first == yellow_dots.second)
			fold_state[2] = true;

		if (fold_point < (left + right) / 2)
			left = fold_point;
		else
			right = fold_point;
	}

	if (!fold_state[2]) {
	// 노란 게 아직 안접혔으면
		fold_point = (yellow_dots.first + yellow_dots.second) / 2;
		fold_state[2] = true;

		if (fold_point < (left + right) / 2)
			left = fold_point;
		else
			right = fold_point;
	}

	cout << fabs(left - right);
	return 0;
}
