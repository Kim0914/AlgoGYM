#include <iostream>
using namespace std;

int num = 0, height = 0;
int buildings[50], seeing_count[50], answer = 0;
int main(){
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> buildings[i];
	}

	for (int i = 0; i < num; i++) {
		double max_gradient = -1000000000;
		// 기울기를 이용하는 문제이다.
    // 기울기가 점점 커져야 하므로 기울기를 가장 작게 만들어 놓아야 한다.
		for (int j = i + 1; j < num; j++) {
			int dy = buildings[j] - buildings[i];
			int dx = j - i;
			double gradient = dy / (dx * 1.0);
			
			if (gradient <= max_gradient)
				continue; 
			// 두 빌딩간의 선분을 그었을 때, 최대 기울기보다 작으면?
			// 보이지 않는 빌딩이 된다.
			// 왜? 예를 들어 기울기가 -3인 빌딩 다음에 기울기가 -4인 빌딩이 왔다.
			// 그 말인 즉슨 빌딩이 더 낮아졌다는 말이므로, 보이지 않는 것이 맞다.
			// 또, 예를 들어 기울기가 2인 빌딩 다음에 기울기가 -3인 빌딩이 왔다.
			// 그 말인 즉슨 내 앞의 빌딩에 가려 뒤에있는 빌딩은 보이지 않는다는 말이다.

			max_gradient = gradient;
			seeing_count[i]++;
			seeing_count[j]++; 
      // 빌딩은 서로 보이는 것이기 때문에 양쪽 다 추가
      // 양쪽 다 추가하면, 반대편으로 볼 필요가 없음
		}
	}

	for (int i = 0; i < num; i++)
		answer = max(answer, seeing_count[i]);
	cout << answer;

	return 0;
}
