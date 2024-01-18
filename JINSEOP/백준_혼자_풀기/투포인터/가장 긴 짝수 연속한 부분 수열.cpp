#include <iostream>
using namespace std;

void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int num = 0, delete_num = 0;
int seq[1000000];
int main() {
	optimize();
	cin >> num >> delete_num;
	for (int i = 0; i < num; i++)
		cin >> seq[i];
	// 어느 숫자를 삭제할 것인가?
	// 홀수를 지우되, 부분 수열의 길이가 최대가 되도록 지워야 한다.

	int front_ptr = 0, max_length = 0, odd_cnt = 0;
	bool even_check = false;
	for (int rear_ptr = 0; rear_ptr < num; rear_ptr++) {
		if (seq[rear_ptr] % 2 == 0)
			even_check = true;
		if (seq[rear_ptr] % 2 == 1)
			odd_cnt++;
		
		max_length = max(max_length, rear_ptr - front_ptr - odd_cnt);
		
		while (odd_cnt > delete_num) {
			if (seq[front_ptr] % 2 == 1)
				odd_cnt--;
			front_ptr++;
		}
	}

	if (!even_check)
		cout << 0;
	else
		cout << max_length + 1;
	return 0;
}
