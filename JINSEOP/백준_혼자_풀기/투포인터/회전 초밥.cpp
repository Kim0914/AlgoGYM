#include <iostream>
#include <vector>
using namespace std;

int dish_num = 0, sushi_num = 0, sushi_in_a_row = 0, coupon = 0;
int dishes[50001];
int kind_of_sushi[3001];
int count_kind_of_sushi() {
	int cnt = 0;

	for (int i = 0; i <= sushi_num; i++) {
		if (kind_of_sushi[i] != 0)
			cnt++;
	}

	if (kind_of_sushi[coupon] == 0)
			cnt++;

	return cnt;
}

int main() {
	int front_ptr = 0, rear_ptr = 0, kind_counter = 0, result = 0;

	cin >> dish_num >> sushi_num >> sushi_in_a_row >> coupon;
	for (int i = 0; i < dish_num; i++)
		cin >> dishes[i];
	for (int i = dish_num; i < dish_num + sushi_in_a_row - 1; i++)
		dishes[i] = dishes[i - dish_num]; // 회전 초밥이니까 반대편도 갈 수 있어야 함

	while (front_ptr < dish_num + sushi_in_a_row - 1) { // 투 포인터
			kind_of_sushi[dishes[front_ptr]]++; // 집어먹음
			front_ptr++;

		while ((front_ptr - rear_ptr) > sushi_in_a_row) {
			kind_of_sushi[dishes[rear_ptr]]--; // 슬라이드
			rear_ptr++;
		}

		kind_counter = count_kind_of_sushi();
		result = max(result, kind_counter);
	}

	cout << result;
	return 0;
}
