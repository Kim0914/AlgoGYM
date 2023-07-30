#include <iostream>
#include <vector>
using namespace std;

bool dp[101][1001];
vector<int> volume_list;
int main() {
	int num = 0, start = 0, limit = 0, vol = 0;
	bool isImpossible = false;

	cin >> num >> start >> limit;
	for (int i = 0; i < num; i++) {
		cin >> vol;
		volume_list.push_back(vol);
	}
	
	if (start + volume_list[0] <= limit) dp[1][start + volume_list[0]] = true;
	if (start + volume_list[0] >= 0) dp[1][start - volume_list[0]] = true;

	for (int i = 2; i <= num; i++) {
		for (int j = 0; j <= limit; j++) {
			// j는 볼륨을 의미한다.
			// 결국 가능한 모든 볼륨 중 가장 큰 마지막 볼륨을 찾는 것!
			if (dp[i - 1][j] == true) { // 이전 음악의 볼륨을 조정할 수 있었으면 진행
				if (j + volume_list[i - 1] <= limit) dp[i][j + volume_list[i - 1]] = true; // 범위를 안넘으면 true
				if (j - volume_list[i - 1] >= 0) dp[i][j - volume_list[i - 1]] = true;
			}
		}
	}

	for (int i = limit; i >= 0; i--) {
		if (dp[num][i] == true) { // 마지막 음악의 뒷 볼륨부터 훑는다.
			cout << i; // 가장 먼저 걸리는 볼륨이 최대 볼륨!
			isImpossible = true;
			break;
		}
	}

	if (!isImpossible)
		cout << -1;

	return 0;
}
