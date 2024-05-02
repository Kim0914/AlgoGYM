#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000001
#define INF 10000000000
typedef long long ll;

int num = 0;
ll stones[5000], dp[5000];
void init_dp() {
	for (int i = 0; i < num; i++)
		dp[i] = MAX;
}

void calculate_dp() {
	dp[0] = 0;
	dp[1] = abs(stones[0] - stones[1]) + 1;

	for (int i = 2; i < num; i++) {
		for (int j = 0; j < i; j++) {
			ll each_fatigue = (i - j) * (1 + abs(stones[i] - stones[j]));
			dp[i] = min(dp[i], max(dp[j], each_fatigue));
		// 이 부분이 핵심이다. 왜 max(dp[j], each_fatigue)를 계산하는가?
		// dp[j]와 each_fatigue 중 큰 값이 K보다 작아야 해당 경로로 움직일 수 있다!
		}
	}
}

void print_dp() {
	for (int i = 0; i < num; i++) {
		cout << dp[i] << " ";
	}
}

bool check_stone(ll target_fatigue) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			ll each_fatigue = (j - i) * (1 + abs(stones[i] - stones[j]));
			
			if (each_fatigue > target_fatigue)
				return false;
		}
	}

	return true;
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> stones[i];
	// i -> j 번째 돌로 이동하는 경우
	// (j - i) * (1 + |A[i] - A[j]|) 만큼 힘을 쓴다.
	// 모든 i -> j가 K 이하여야 한다는 말!

	init_dp();
	calculate_dp();
	print_dp();

	cout << dp[num - 1];
	return 0;
}
