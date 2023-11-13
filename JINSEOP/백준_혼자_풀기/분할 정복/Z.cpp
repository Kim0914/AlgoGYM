#include <iostream>
#include <cmath>
using namespace std;

int num = 0, row = 0, col = 0, sequence = 0;
int z_map[15][15];
bool is_founded = false;
void count_z_sequence(int x, int y, int limit) {
	if (is_founded)
		return;
	// pruning

	if (limit == 1) {
		if (x == row && y == col) {
			cout << sequence;
			is_founded = true;
		}

		sequence++;
		return;
	}

	count_z_sequence(x, y, limit / 2);
	count_z_sequence(x, y + limit/2, limit / 2);
	count_z_sequence(x + limit/2, y, limit / 2);
	count_z_sequence(x + limit/2, y + limit/2, limit / 2);
}

int main() {
	cin >> num >> row >> col;
	count_z_sequence(0, 0, pow(2, num));
	// 2^n승의 칸을 가진다.
	return 0;
}
