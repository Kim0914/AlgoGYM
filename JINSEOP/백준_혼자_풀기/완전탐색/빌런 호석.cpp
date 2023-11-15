#include <iostream>
using namespace std;

int story = 0, num = 0, reversed_bit = 0, curr_floor = 0, answer = 0;
bool segment[10][7] = { {1, 1, 1, 1, 1, 1, 0}, // 0
				{0, 1, 1, 0, 0, 0, 0}, // 1
				{1, 1, 0, 1, 1, 0, 1}, // 2
				{1, 1, 1, 1, 0, 0, 1}, // 3
				{0, 1, 1, 0, 0, 1, 1}, // 4
				{1, 0, 1, 1, 0, 1, 1}, // 5
				{1, 0, 1, 1, 1, 1, 1}, // 6
				{1, 1, 1, 0, 0, 0, 0}, // 7
				{1, 1, 1, 1, 1, 1, 1}, // 8
				{1, 1, 1, 1, 0, 1, 1} }; // 9
// unordered_map을 이용하다 실패함

int main() {
	cin >> story >> num >> reversed_bit >> curr_floor;
	// 최소 1개 ~ 최대 reversed_bit개 반전

	for (int i = 1; i <= story; i++) {
		// 1부터 최대 층 수까지 모두 반전 가능한지 훑는다.
		if (i == curr_floor)
			continue; // 현재 층과 같은 수는 볼 필요가 없음

		int reverse_cnt = 0; // LED를 몇 번 반전시켜야 하는지?
		int src = curr_floor, dest = i; // 현재 층을 목표하는 층수로 바꿀 수 있는지?

		for (int j = 0; j < num; j++) { // 정해진 자릿수 만큼 돌아야한다.
			for (int k = 0; k < 7; k++) { // LED의 수는 한 자리당 7개
				if (segment[src % 10][k] != segment[dest % 10][k])
					reverse_cnt++; // 만약 둘의 비트가 다르면 반전해야 한다는 것
			}

			src /= 10; dest /= 10; // 다음 자릿수로
		}

		if (reverse_cnt <= reversed_bit)
			answer++; // 반전 제한 횟수보다 덜 썼으면 가능한 것!
	}

	cout << answer;

	return 0;
}
