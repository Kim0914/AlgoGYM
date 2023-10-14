#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> min_heap;
int main(){
	int num = 0, sum = 0, wholesum = 0, digit = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> digit;
		min_heap.push(digit);
	}

	while (!min_heap.empty()) {
		sum += min_heap.top();
		wholesum += sum;

		min_heap.pop();
	}

	cout << wholesum;
	return 0;
}
// 음.
