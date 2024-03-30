#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, int>

int num = 0, card = 0, dp[1000];
vector<int> cards;
int main(){
	cin >> num;
	cards.push_back(0); // 0장은 0원
	for (int i = 0; i < num; i++) {
		cin >> card;
		cards.push_back(card);
	}

	dp[0] = 0; // 안살거면 지불 안해도 됨
	for (int i = 1; i <= num; i++) {
		dp[i] = cards[i]; // 우선 1장 사는 가격으로 갱신
		for (int j = 1; j < cards.size(); j++) {
			if (i - j >= 0)
				dp[i] = min(dp[i - j] + cards[j], dp[i]);
			// 이전 카드에 현재 카드를 더하는게 싼가? 그냥 지금 카드를 사는게 싼가?
		}
	}

	cout << dp[num];
	return 0;
}
