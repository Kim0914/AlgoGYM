#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> min_heap;
int num = 0;
long long target = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> target;
		if (target == 0) {
			if (min_heap.empty())
				cout << 0 << '\n';
			else {
				cout << min_heap.top() << '\n';
				min_heap.pop();
			}
		}
		else
			min_heap.push(target);
	}

	return 0;
}
