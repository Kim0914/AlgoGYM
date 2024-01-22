#include <iostream>
#include <queue>
using namespace std;
#define pdd pair<pair<double, double>, double>

pdd second_to_degree(int second) {
	int h = second / 3600;
	int m = (second % 3600) / 60;
	int s = (second % 3600) % 60;

	double h_degree = (h % 12) * 30.0 + m * 0.5 + s * (1/120.0);
	double m_degree = m * 6.0 + s * 0.1;
	double s_degree = s * 6.0;

	return { {h_degree, m_degree}, s_degree };
}

bool match_hour(pdd prev, pdd curr) {
	if (prev.first.first > prev.second && curr.first.first <= curr.second)
		return true;
	// 시침의 각도가 초침보다 컸다가, 작아지게 되면 겹친 것

	if (prev.second == 354 && prev.first.first > 354)
		return true;
	// 초침이 354도에서 0도로 넘어가게 되면, 360이 아니라 검사가 안됨.

	return false;
}

bool match_minute(pdd prev, pdd curr) {
	if (prev.first.second > prev.second && curr.first.second <= curr.second)
		return true;
	// 분침의 각도가 초침보다 컸다가, 작아지게 되면 겹친 것

	if (prev.second == 354 && prev.first.second > 354)
		return true;
	// 초침이 354도에서 0도로 넘어가게 되면, 360이 아니라 검사가 안됨.

	return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
	int answer = 0;
	// h1시 m1분 s1초 부터 h2시 m2분 s2초 내에 몇 번 알람이 울리나?
	// 알람은 초, 시/분침이 겹쳐야 울린다.
	
	// 초침은 1초에 6도 움직임
	// 초침이 시계를 1바퀴 돌 때 분침은 6도 움직임
	// 그럼 분침은 1초에 1/10도 움직이는 것

	// 그럼 시침은 1분에 1/2도를 움직임
	// 시침은 1초에 1/120도를 움직이는 것
	int from = h1 * 3600 + m1 * 60 + s1;
	int to = h2 * 3600 + m2 * 60 + s2;

	for (int i = from; i < to; i++) {
		pdd prev_degree = second_to_degree(i);
		pdd curr_degree = second_to_degree(i + 1);

		bool is_match_h = match_hour(prev_degree, curr_degree);
		bool is_match_m = match_minute(prev_degree, curr_degree);

		if (is_match_h && is_match_m) {
			// 시침과 분침의 각도가 같아 모두 겹치면 1번
			if (curr_degree.first.first == curr_degree.first.second)
				answer++;
			// 아니면 2번 겹친 것이니 2번
			else
				answer += 2;
		}
		else if (is_match_h || is_match_m)
		// 둘 중 하나만 겹치면 1번
			answer++;
	}
	
	if (from == 0 || from == 43200)
		answer++;
	// 시작 시간에 겹치는 경우는 따로 예외처리

	return answer;
}

int main() {
	solution(0, 5, 30, 0, 7, 0);
	return 0;
}
