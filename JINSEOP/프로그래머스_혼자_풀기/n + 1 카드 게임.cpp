#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool card_check[1001];
bool validate_hand(vector<int> &hands, int goal) {
	for (int card : hands) {
		if (find(hands.begin(), hands.end(), goal - card) != hands.end()) {
			hands.erase(remove(hands.begin(), hands.end(), card), hands.end());
			hands.erase(remove(hands.begin(), hands.end(), goal - card), hands.end());
			card_check[card] = 0;
			card_check[goal - card] = 0;

			return true;
		}
	}

	return false;
}

bool validate_draw_one(vector<int>& hands, int goal) {
	for (int card : hands) {
		if (card_check[goal - card]) {
			hands.erase(remove(hands.begin(), hands.end(), card), hands.end());
			card_check[card] = 0;
			card_check[goal - card] = 0;

			return true;
		}
	}

	return false;
}

bool validate_draw_two(int goal) {
	for (int k = 1; k < goal; k++) {
		if (card_check[k] && card_check[goal - k]) {
			card_check[k] = 0;
			card_check[goal - k] = 0;

			return true;
		}
	}

	return false;
}

int solution(int coin, vector<int> cards) {
	int answer = 1, goal = cards.size() + 1;
	vector<int> hands;

	for (int i = 0; i < cards.size() / 3; i++) {
		hands.push_back(cards[i]);
		// n/3 장의 카드를 첫 패로 뽑는다.
		card_check[cards[i]] = true;
	}

	for (int i = cards.size() / 3; i < cards.size(); i += 2) {
		// 남은 카드 두 장씩 훑는다
		card_check[cards[i]] = true;
		card_check[cards[i + 1]] = true;

		// 1. 손에 있는 두 패로 n + 1을 만들 수 있는 경우
		if (hands.size() >= 2 && validate_hand(hands, goal))
			answer++;
		// 2. 손에 있는 패 1장, 뽑은 카드 1장으로 n + 1을 만들 수 있는 경우
		else if (hands.size() >= 1 && coin >= 1 && validate_draw_one(hands, goal)) {
			answer++;
			coin--;
		}
		// 3. 손에 있는 패를 모두 써야 만들 수 있는 경우
		else if (coin >= 2 && validate_draw_two(goal)) {
			answer++;
			coin -= 2;
		}
		else
			break;
	}

	return answer;
}
