#include <iostream>
using namespace std;
#define ll long long

ll dp[31][31];
void count_pill() {
	for (int i = 0; i <= 30; i++)
		dp[0][i] = 1;

	for (int w = 1; w <= 30; w++) {
		for (int h = 0; h <= 30; h++) {
			if (h == 0) // 알약을 하나 빼내기만 하는 경우
				dp[w][0] = dp[w - 1][1];
			// 알약을 하나만 빼먹는 경우는 w는 하나 빼고 h + 1
			else
				dp[w][h] = dp[w - 1][h + 1] + dp[w][h - 1];
			// 현재의 값은 알약 한 개 빼내는 경우 + 반 개 빼내는 경우
		}
	}
}

int main() {
	int pill = 0;
	count_pill();

	while (true) {
		cin >> pill;
		if (pill == 0)
			break;

		cout << dp[pill][0] << '\n';
	}

	return 0;
}
