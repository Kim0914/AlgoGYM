#include <iostream>
#include <string>
using namespace std;
#define MAX 9999999

string target = "";
int a_count = 0, answer = MAX;
int main() {
	cin >> target;

	for (int i = 0; i < target.size(); i++)
		if (target[i] == 'a')
			a_count++;

	for (int i = 0; i < target.size(); i++) {
		int a_to_trans = a_count;
		int b_to_trans = 0;

		for (int j = i; j < i + target.size(); j++) {
			if (a_to_trans == 0)
				break; // 몰아넣어야 할 a의 수를 모두 채웠으면 중지

			if (target[j % target.size()] == 'b') {
				b_to_trans++; // b는 a로 치환이 가능하다.
				a_to_trans--; // a의 수를 하나 줄인다.
			}
			else
				a_to_trans--; // 그냥 a인 경우엔 a의 수만 줄여도 된다.
		}

		answer = min(b_to_trans, answer);
	}

	cout << answer;
	return 0;
}

// Brute force 문제
