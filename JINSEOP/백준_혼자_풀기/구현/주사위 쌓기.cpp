#include <iostream>
using namespace std;

int dice[10000][6], top_pair[6];
int num = 0, answer = 0;
void init_pair() {
	top_pair[0] = 5;
	top_pair[1] = 3;
	top_pair[2] = 4;
	top_pair[3] = 1;
	top_pair[4] = 2;
	top_pair[5] = 0;
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 6; j++)
			cin >> dice[i][j];
	}

	// 면이 정해지는 방식
	// 0 - 5 짝 1 - 3 짝 2 - 4 짝
	// 1번 주사위의 아랫면이 정해지면, 다음 주사위 윗면 정해짐.
	init_pair();

	int sum = 0, std_top = 0, max_v = 0;
	for (int i = 0; i < 6; i++) {
		// i가 윗면을 정해줄 것이다.
		sum = 0, max_v = 0;
		
		for (int j = 1; j <= 6; j++)
			if (j != dice[0][i] && j != dice[0][top_pair[i]])
				max_v = max(max_v, j);
		sum += max_v;
		// 위, 아래면 제외 가장 큰 값 찾아서 더해주기
		std_top = dice[0][i];
		// 가장 첫 주사위의 윗면이 정해짐
		int curr_bottom = 0;
		for (int j = 1; j < num; j++) {
			max_v = 0;

			for (int k = 0; k < 6; k++) {
			// 현재 보고있는 주사위의 윗면
				if (dice[j][k] == std_top) {
					curr_bottom = k;
					break;
				}
			}

			int top = dice[j][top_pair[curr_bottom]];
			int bottom = std_top;
			// 윗면은 이전 주사위의 윗면의 반대편
			// 아랫면은 이전 주사위의 윗면과 같다.
			for (int k = 1; k <= 6; k++)
				if (k != top && k != bottom)
					max_v = max(max_v, k);

			sum += max_v;
			std_top = top; // 윗면을 옮겨줘야 함
		}

		answer = max(answer, sum);
	}

	cout << answer;
	return 0;
}
