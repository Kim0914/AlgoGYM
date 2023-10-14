#include <iostream>
#include <algorithm>
using namespace std;

int armors[15000];
int main(){
	int num = 0, code = 0, sum = 0, ans_cnt = 0;
	cin >> num >> code;
	for (int i = 0; i < num; i++)
		cin >> armors[i];

	sort(armors, armors + num);
	int front_ptr = 0, rear_ptr = num - 1;
	
	while (front_ptr < rear_ptr) {
		sum = armors[front_ptr] + armors[rear_ptr];

		if (sum >= code) {
			if (sum == code)
				ans_cnt++;

			rear_ptr--;
		}
		else
			front_ptr++;
	}

	cout << ans_cnt;

	return 0;
}
