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
		value -= num; // 미리 A로 다 채워놓는 것

		while (value >= 25) {
			answer += "Z";
			value -= 25;
		}

		if (value) // A보다 큰 알파벳을 넣을 값이 남으면
			answer += (value + 'A');

		int cursor = answer.length();
		for (int i = cursor; i < num; i++)
			answer += 'A';

		reverse(answer.begin(), answer.end());
		cout << answer;
	}

	return 0;
}
