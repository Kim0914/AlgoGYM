#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define INF 1000001

int num = 0, a = 0, b = 0;
int dp[1000001];
void init_dp() {
	dp[0] = 0;
	for (int i = 1; i <= num; i++)
		dp[i] = INF;
}

int main() {
	cin >> num >> a >> b;

	init_dp();
	for (int i = 1; i <= num; i++) {
		dp[i] = dp[i - 1] + 1; // 그냥 기다리면 한 칸 앞으로 감
		
		if (i - a - 1 >= 0)
			dp[i] = min(dp[i], dp[i - a - 1] + 1);
		// a이전의 칸에서 건너 올 수 있다면 갱신
		if (i - b - 1 >= 0)
			dp[i] = min(dp[i], dp[i - b - 1] + 1);
		// b이전의 칸에서 건너올 수 있는데, 더 작다면 갱신
	}


	cout << dp[num];
	return 0;
}
