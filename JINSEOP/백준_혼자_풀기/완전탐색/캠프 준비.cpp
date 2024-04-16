#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pii pair<int, int>

int num = 0, lower_b = 0, upper_b = 0, diff_limit = 0, answer = 0;
int probs[16];
bool selected[16];
bool check_sum(int sum) {
	if (sum >= lower_b && sum <= upper_b)
		return true;
	return false;
}

bool check_diff(int max_v, int min_v) {
	if ((max_v - min_v) >= diff_limit)
		return true;
	return false;
}

void backtrack(int depth, int sum, int max_v, int min_v) {
	if (depth == num + 1) {
		if (check_sum(sum) && check_diff(max_v, min_v))
			answer++;

		return;
	}

	selected[depth] = false;
	backtrack(depth + 1, sum, max_v, min_v);
	selected[depth] = true;
	backtrack(depth + 1, sum + probs[depth], max(max_v, probs[depth]), min(min_v, probs[depth]));
}

int main() {
	OPTIMIZE;

	cin >> num >> lower_b >> upper_b >> diff_limit;
	for (int i = 1; i <= num; i++)
		cin >> probs[i];

	backtrack(1, 0, 0, 99999999);
	cout << answer;
	return 0;
}
