#include <iostream>
using namespace std;

long long line_list[10001], result = 0;
int lines = 0, need = 0, need_cnt = 0;
long long check_count(long long std) {
	long long cnt = 0;

	for (int i = 0; i < lines; i++)
		cnt += (line_list[i] / std);

	return cnt;
}

void binary_search(long long left, long long right) {
	if (right < left)
		return;

	long long mid = (left + right) / 2;
	need_cnt = check_count(mid);

	if (need_cnt >= need) {
		result = max(result, mid);
		binary_search(mid + 1, right);
	}
	else
		binary_search(left, mid - 1);
}

int main() {
	long long max_len = 0;
	cin >> lines >> need;
	for (int i = 0; i < lines; i++) {
		cin >> line_list[i];
		max_len = max(max_len, line_list[i]);
	}

	binary_search(1, max_len);
	cout << result;

	return 0;
}
