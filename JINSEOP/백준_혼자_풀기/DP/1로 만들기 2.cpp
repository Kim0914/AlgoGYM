#include <iostream>
using namespace std;

int num = 0, dp[1000001];
int main() {
	cin >> num;

	for (int i = 1; i <= num; i++)
		dp[i] = i;

	for (int i = 2; i <= num; i++) {
    // 앞으로 진행하며 항상 최솟값을 저장하며 진행한다.
		if (i % 2 == 0) // 2로 나눠지는 경우 2로 나눈 위치의 값을 데려온다.
			dp[i] = min(dp[i], dp[i / 2]);
		if (i % 3 == 0) // 3으로 나눠지는 경우 3으로 나눈 위치의 값을 데려온다.
			dp[i] = min(dp[i], dp[i / 3]);

		dp[i] = min(dp[i], dp[i - 1]) + 1; // 1을 빼는 경우 이전 칸 값을 데려오고 1회 추가
	}

	cout << dp[num] - 1 << '\n';

	while (num > 0) {
		cout << num << " ";
		if (dp[num] == dp[num - 1] + 1)
			num -= 1; // 10을 예로 들면, 9는 3번만에 종료되므로 한 번 더 간 10은 같은 라인이라는 것 
		else if (num % 2 == 0 && (dp[num] == dp[num / 2] + 1))
			num /= 2; // 4를 예로 들면, 2는 2번만에 종료되므로 한 번 더 간 4는 같은 라인이라는 것
		else if (num % 3 == 0 && (dp[num] == dp[num / 3] + 1))
			num /= 3; // 9를 예로 들면, 3은 2번만에 종료되므로 한 번 더 간 9는 같은 라인이라는 것
	}

	return 0;
}
