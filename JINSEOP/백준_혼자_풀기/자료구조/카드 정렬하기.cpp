#include <iostream>
#include <queue>
using namespace std;

int num = 0, card_num = 0, answer = 0;
priority_queue<int, vector<int>, greater<>> card_pack;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> card_num;
		card_pack.push(card_num);
	}

	while (card_pack.size() > 1) {
		int first_pack = card_pack.top();
		card_pack.pop();
		int second_pack = card_pack.top();
		card_pack.pop(); // 순차적으로 작은 두 팩을 뺀다

		answer += (first_pack + second_pack); // 정답에 더해주고
		card_pack.push(first_pack + second_pack); // 다시 팩에 집어넣음
	}

	cout << answer;

	return 0;
}
