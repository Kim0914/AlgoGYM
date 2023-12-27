#include <iostream>
#include <string>
using namespace std;

int clock_list[4], clock_num = 10000;
int check_clock_num(int target){
	int temp = target;

	for (int i = 0; i < 3; i++) {
		target = target % 1000 * 10 + target / 1000;
		// 수를 한 칸 씩 옮기는 과정

		if (temp > target)
			temp = target;
	}

	return temp;
	// 해당 지점에서 시계수 반환
}

void find_clock_num() {
	int iter = 4;
	while (iter--) {
		string temp_s = "";

		for (int i = iter % 4; i < (iter % 4) + 4; i++)
			temp_s += (clock_list[i % 4] + '0');

		clock_num = min(clock_num, stoi(temp_s));
	}
}

int count_clock_num() {
	int cnt = 0;

	for (int i = 1111; i <= clock_num; i++) {
		if (check_clock_num(i) == i) 
			// 해당 수가 시계수면 증가
			cnt++;
	}

	return cnt;
}

int main() {
	for (int i = 0; i < 4; i++)
		cin >> clock_list[i];

	find_clock_num();
	cout << count_clock_num();

	return 0;
}
