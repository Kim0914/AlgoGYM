#include <iostream>
#include <vector>
using namespace std;

int num = 0, box = 0, dp[1001];
vector<int> box_vec;
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> box;
		box_vec.push_back(box);
	}
	
	dp[0] = 1; // 시작하는 박스는 반드시 하나
	int answer = 0;
	for (int i = 0; i < num; i++) {
		dp[i] = 1; // 기본적으로 모든 박스는 1개.

		for (int j = i; j >= 0; j--) {
			if (box_vec[j] < box_vec[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		answer = max(dp[i], answer);
	}

	cout << answer;
	return 0;
}
