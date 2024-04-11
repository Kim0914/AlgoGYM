#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pii pair<int, int>

int num = 0, goal = 0, length = 0, quantity = 0;
vector<pii> pipe_info;
int dp[10001]; // 길이 저장
int main() {
	OPTIMIZE;

	cin >> num >> goal;

	dp[0] = 1; // Base case 1
	for (int i = 0; i < num; i++) {
		cin >> length >> quantity;

		for (int j = goal; j >= 0; j--) // 목표 길이부터 뒤로 탐색한다.
    // 앞에서부터 탐색하게 되면, DP 배열이 미리 차버리게 된다.
    // 즉, 다음 단계에 진행에 있어서 오염되어 버리는 것이다.
			for(int quan = 1; quan <= quantity && j - length * quan >= 0; quan++)
				dp[j] += dp[j - length * quan];
      // 주어진 수량만큼 반복문을 수행한다. => 수량이 다 떨어지면 무게 - 1
	}

	cout << dp[goal];
	return 0;
}
