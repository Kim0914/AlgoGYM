#include <iostream>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int row = 0, col = 0, st_x = 0, st_y = 0, timer = 0;
int main() {
	OPTIMIZE;
	
	cin >> row >> col;
	cin >> st_x >> st_y;
	cin >> timer;

	// 구현으로 한 번 풀어보자
	int curr_x = st_x, curr_y = st_y;
	bool x_state = true, y_state = true;
	while (timer--) {
		if (x_state)
			curr_x++;
		else
			curr_x--;
		if (y_state)
			curr_y++;
		else
			curr_y--;

		if (curr_x >= row || curr_x <= 0)
			x_state = !x_state;
		if (curr_y >= col || curr_y <= 0)
			y_state = !y_state;
	}

	cout << curr_x << " " << curr_y << '\n';
	return 0;
}
