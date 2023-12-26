#include <iostream>
using namespace std;

int num = 0;
int students[1001], dp[1001];
int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> students[i];

	for (int i = 2; i <= num; i++) {
		int min_score = students[i], max_score = students[i];
		// i번째 학생을 혼자 둔다고 가정하자.
		for (int j = i - 1; j >= 0; j--) {
			max_score = max(students[j + 1], max_score);
			min_score = min(students[j + 1], min_score);
			dp[i] = max(dp[i], dp[j] + max_score - min_score);
		}
	}

	cout << dp[num];
}
