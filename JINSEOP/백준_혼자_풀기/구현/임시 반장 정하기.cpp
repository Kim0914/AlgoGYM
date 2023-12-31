#include <iostream>
using namespace std;

int num = 0, answer = 0;
int student_book[1001][6];
bool student_state[1001][1001];
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < 5; j++)
			cin >> student_book[i][j];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < num; j++) {
			for (int k = 0; k < num; k++) {
				if (j == k)
					continue;

				if (student_book[j][i] == student_book[k][i] && !student_state[j][k])
					student_state[j][k] = true;
			}
		}
	}

	int max_sum = 0;
	for (int i = 0; i < num; i++) {
		int partial_sum = 0;

		for (int j = 0; j < num; j++)
			partial_sum += student_state[i][j];

		if (partial_sum > max_sum) {
			answer = i;
			max_sum = partial_sum;
		}
	}

	cout << answer + 1;
	return 0;
}
