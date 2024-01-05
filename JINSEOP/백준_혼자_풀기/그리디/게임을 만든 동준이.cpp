#include <iostream>
using namespace std;

int num = 0, levels[100], answer = 0;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> levels[i];

	for (int i = num - 2; i >= 0; i--) {
		if (levels[i] >= levels[i + 1]) {
			answer += ((levels[i] - levels[i + 1]) + 1);
			levels[i] = levels[i + 1] - 1;
		}
	}

	cout << answer;
	return 0;
}
