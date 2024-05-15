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
		int cursor = 6;
		string answer = "";
		while (value > 26) {
			answer += "Z";
			value -= 26;
			cursor--;
		}

		if (value > cursor) {
			char temp = (value - cursor) + 'A';
			answer += temp;
			value -= (value - cursor - 1);
			cursor--;
		}

		for (int i = cursor; i < num; i++) {
			answer += "A";
			value--;
		}

		reverse(answer.begin(), answer.end());
		cout << answer;
	}

	return 0;
}
