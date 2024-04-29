#include <iostream>
#include <vector>
using namespace std;

int limit = 0, num = 0;
int dp[1001][10001];
int main() {
	cin >> limit >> num;

	int importance = 0, need = 0;
	for (int i = 1; i <= num; i++) {
		cin >> importance >> need;

		for (int j = 0; j <= limit; j++)
			if (j - need >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - need] + importance);
			else
				dp[i][j] = dp[i - 1][j];
	}

	cout << dp[num][limit];
	return 0;
}

///////////////////////////////////////////// 위에는 O(N^2)
///////////////////////////////////////////// 아래는 O(N)

#include <iostream>
#include <vector>
using namespace std;

int limit = 0, num = 0;
int dp[10001];
int main() {
	cin >> limit >> num;

	int importance = 0, need = 0;
	for (int i = 1; i <= num; i++) {
		cin >> importance >> need;

		for (int j = limit; j >= need; j--)
			dp[j] = max(dp[j], dp[j - need] + importance);
	}

	cout << dp[limit];
	return 0;
}
