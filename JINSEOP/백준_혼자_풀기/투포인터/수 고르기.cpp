#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long 

ll num = 0, target_diff = 0, min_diff = LLONG_MAX;
ll sequence[100000];
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();

	cin >> num >> target_diff;
	for (int i = 0; i < num; i++)
		cin >> sequence[i];
	sort(sequence, sequence + num);

	int front_ptr = 0;
	ll diff = 0;
	for (int rear_ptr = 1; rear_ptr < num; rear_ptr++) {
		while (sequence[rear_ptr] - sequence[front_ptr] >= target_diff) {
			min_diff = min(min_diff, sequence[rear_ptr] - sequence[front_ptr]);
			front_ptr++;
		}
	}

	cout << min_diff;
	return 0;
}
