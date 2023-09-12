#include <iostream>
using namespace std;
#define MAX 99999999;

int num = 0, seq[100000], answer = MAX;
long long sum = 0;
void two_pointer() {
	int rear_ptr = 0, front_ptr = 0;
	long long checksum = 0;
	
	while (rear_ptr < num) {
		if (front_ptr < num) {
			checksum += seq[front_ptr];
			front_ptr++;
		}

		if (front_ptr == num && checksum < sum)
			break;

		while (checksum >= sum) {
			answer = min(answer, front_ptr - rear_ptr);
			checksum -= seq[rear_ptr];
			rear_ptr++;
		}
	}
}

int main() {
	cin >> num >> sum;
	for (int i = 0; i < num; i++) {
		cin >> seq[i];
	}

	two_pointer();
	if (answer == 99999999)
		cout << 0;
	else
		cout << answer;

	return 0;
}
