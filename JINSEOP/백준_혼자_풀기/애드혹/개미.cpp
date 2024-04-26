#include <iostream>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int row = 0, col = 0, st_x = 0, st_y = 0, timer = 0;
int main() {
	OPTIMIZE;
	
	cin >> row >> col;
	cin >> st_x >> st_y;
	cin >> timer;

	if (((st_x + timer) / row) % 2 == 0)
		cout << (st_x + timer) % row << ' ';
	// 나눠서 짝수면 밑에서 올라가는 경우
	else
		cout << row - ((st_x + timer) % row) << ' ';
	// 홀수면 위에서 내려오는 경우니, 끝에서 빼줌

	if (((st_y + timer) / col) % 2 == 0)
		cout << (st_y + timer) % col;
	else
		cout << col - ((st_y + timer) % col);
	// 가로 방향도 동일하게 적용
	return 0;
}
