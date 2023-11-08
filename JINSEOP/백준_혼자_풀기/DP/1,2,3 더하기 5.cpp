#include <iostream>
using namespace std;
#define ll long long

int tc = 0, num = 0;
ll dp[100001][4];
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init_dp() {
	dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0; // 1
	dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0; // 2
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
	// 각 column의 의미는 해당 수가 마지막에 오는 식을 의미한다.
	// 예를 들어, 3의 경우는 2+1 1개 / 1+2 1개 / 3 1개가 된다.
}

int main(){
	optimize();
	init_dp();

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num;

		for (int j = 4; j <= num; j++) {
			// 1의 앞에는 2 또는 3밖에 못온다.
			// 그럼 당연히 2의 앞에는 1 또는 3밖에 못온다. 이 사실을 이용한 방식이다.
			dp[j][1] = (dp[j - 1][2] + dp[j - 1][3]) % 1000000009;
			dp[j][2] = (dp[j - 2][1] + dp[j - 2][3]) % 1000000009;
			dp[j][3] = (dp[j - 3][1] + dp[j - 3][2]) % 1000000009;
		}

		cout << (dp[num][1] + dp[num][2] + dp[num][3]) % 1000000009 << '\n';
	}
	return 0;
}
