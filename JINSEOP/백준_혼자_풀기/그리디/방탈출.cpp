#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int num = 0;
bool states[1000001];
int main() {
	OPTIMIZE;

	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> states[i];
	// 이미 완성된 state를 모두 꺼진 상태로 얼마만에 만드는가? 를 생각해보자

	int answer = 0;
	for (int i = 0; i < num; i++) {
		if (states[i]) {
			if (i == num - 2) {
				answer++;
				states[i] = !states[i];
				states[i + 1] = !states[i + 1];
			}

			else if (i == num - 1) {
				answer++;
				states[i] = !states[i];
			}

			else {
				answer++;
				states[i] = !states[i];
				states[i + 1] = !states[i + 1];
				states[i + 2] = !states[i + 2];
			}
		}
	}

	cout << answer;
	return 0;
}
