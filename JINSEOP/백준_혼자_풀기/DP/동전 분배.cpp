#include <iostream>
#include <vector>
using namespace std;

int kind_num = 0, price = 0, num = 0;
int dp[50001]; // 반으로 나누려면 최대 5만임
void clear_dp() {
	for (int i = 0; i < 50001; i++)
		dp[i] = 0;
}

int main(){
	for (int i = 0; i < 3; i++) {
		clear_dp();
		vector<pair<int, int>> coin; // 코인 수를 저장해야 함
		int sum = 0;
		cin >> kind_num;

		for (int i = 0; i < kind_num; i++) {
			cin >> price >> num;
			coin.push_back({ price, num });
			sum += (price * num);
		}

		if (sum % 2 != 0) {
			cout << "0" << '\n';
			continue; // 합이 홀수면 어차피 반으로 못나눔
		}

		dp[0] = 1; // 0은 무조건 가능
		for (int i = 0; i < kind_num; i++) {
			for (int j = 50000; j >= 0; j--) { // 최대 금액부터 훑으며
				if (j - coin[i].first >= 0) { // 현재 금액을 더 채울 수 있을 때
					if (dp[j - coin[i].first] == 1) { 
						// 현재 금액을 사용했을 떄의 금액이 만들 수 있는 금액이었으면?
						// 왜 이렇게 해야 하는가?
						// 그래야 이전 단계에서 만든 모든 돈에 현재 돈을 추가할 수 있음.
						// 예를 들어 이전 단계가 100원짜리 3개, 현재 단계가 50원 2개면?
						// 100에 대해서 150 200
						// 200에 대해서 250 300
						// 300에 대해서 350 400 모든 경우의 수를 다 만들 수 있게 됨

						for (int k = 0; k < coin[i].second; k++) {
						// 해당 동전을 사용해 만들 수 있는 경우의 수 모두 생성
							if (j + coin[i].first * k < 50001)
								dp[j + coin[i].first * k] = 1;
						}
					}
				}
			}
		}

		cout << dp[(sum / 2)] << '\n';
	}

	return 0;
}
