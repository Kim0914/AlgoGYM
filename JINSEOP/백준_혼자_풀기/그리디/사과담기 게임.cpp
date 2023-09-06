#include <iostream>
using namespace std;

int num = 0, basket = 0, apple_num = 0, answer = 0;
int main() {
	cin >> num >> basket >> apple_num;
	int left = 1, right = basket; // 바구니의 시작과 끝을 지정

	for (int i = 0; i < apple_num; i++) {
		int apple_pos; // 떨어지는 사과의 위치
		cin >> apple_pos;

		while (left > apple_pos || right < apple_pos) {
			// 현재 떨어진 사과가 바구니의 크기보다 바깥에 위치하면
			if (apple_pos > right) {
				right++; left++; answer++;
				// 오른쪽에 위치하면 바구니를 앞으로 옮김
			}
			if (apple_pos < left) {
				right--; left--; answer++;
				// 왼쪽에 위치하면 바구니를 뒤로 옮김
			}
		}
	}

	cout << answer;
	return 0;
}
