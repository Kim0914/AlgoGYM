#include <iostream>
#include <algorithm>
using namespace std;

int num = 0, value = 0;
int main() {
	cin >> num >> value;
	if ((num * 26) < value || value < num) {
		cout << '!';
	}
	else {
		string answer = "";

		for (int i = 0; i < num; i++) {
			if (value > 26) {
				answer += "Z";
				value -= 26;
			// Z를 넣을 수 있으면 Z부터 채운다.
			}
			else {
				if (value > (num - i)) {
					char temp = (value - (num - i)) + 'A';
					answer += temp;
					value -= (value - (num - i - 1));
				} // 26 아래로 내려갔지만 값이 남으면?
				// 남은 칸만큼 남겨두고 알파벳으로 치환
				else {
					answer += "A";
					value--;
				}
			}
		}

		reverse(answer.begin(), answer.end());
		cout << answer;
	}

	return 0;
}
