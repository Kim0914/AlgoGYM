#include <iostream>
#include <vector>
using namespace std;

int len = 0, sum = 0, num = 0, result = 0;
vector<int> sequence;
void backtrack(int depth, int idx, int curr_sum, vector<bool> &visit) {
	if (curr_sum == sum && depth != 0)
		result++;

	for (int i = idx; i < len; i++) {
		if (!visit[i]) {
			visit[i] = true;
			backtrack(depth + 1, i, curr_sum + sequence[i], visit);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> len >> sum;

	for (int i = 0; i < len; i++) {
		cin >> num;
		sequence.push_back(num);
	}

	vector<bool> visit(sequence.size(), 0);
	backtrack(0, 0, 0, visit);

	cout << result;

	return 0;
}
