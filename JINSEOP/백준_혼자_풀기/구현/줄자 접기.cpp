#include <iostream>
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
	fold_state[0] = true;

	// 접힌 길이는 어떻게 계산?
	// 둘 중 더 큰 쪽이 접힌 길이가 된다.
	ruler_length = (fold_point, ruler_length - fold_point);
	
	if (abs(fold_point - blue_dots.first) == abs(fold_point - blue_dots.second))
		fold_state[1] = true;
	// 파란 게 접혔는 지 확인
	if (abs(fold_point - yellow_dots.first) == abs(fold_point - yellow_dots.second))
		fold_state[2] = true;
	// 노란 게 접혔는 지 확인

	cout << fold_point << ' ' << ruler_length << '\n';
	if (!fold_state[1]) {
	// 파란 게 아직 안접혔으면
		fold_point = (blue_dots.first + blue_dots.second) / 2;
		fold_state[1] = true;

		if (abs(fold_point - yellow_dots.first) == abs(fold_point - yellow_dots.second))
			fold_state[2] = true;

		ruler_length = (fold_point, ruler_length - fold_point);
	}

	cout << fold_point << ' ' << ruler_length << '\n';

	if (!fold_state[2]) {
	// 노란 게 아직 안접혔으면
		fold_point = (yellow_dots.first + yellow_dots.second) / 2;
		fold_state[2] = true;

		ruler_length = (fold_point, ruler_length - fold_point);
	}

	cout << fold_point << ' ' << ruler_length << '\n';
	return 0;
}
