#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int row = 0, day = 0;
int honeycomb[1400];
void init_comb() {
	for (int i = 0; i < (2 * row - 1); i++)
		honeycomb[i] = 1;
}

int main(){
	OPTIMIZE;

	cin >> row >> day;
	init_comb();

	int zero = 0, one = 0, two = 0;
	while(day--){
		cin >> zero >> one >> two;
		for (int i = zero; i < zero + one; i++)
			honeycomb[i]++;
		for (int i = zero + one; i < (2 * row - 1); i++)
			honeycomb[i] += 2;
	}

	for (int i = 0; i < row; i++) {
		cout << honeycomb[row - i - 1] << " ";
		for (int j = 1; j < row; j++) {
			cout << honeycomb[row + j - 1] << " ";
		}
		cout << '\n';
	}

	return 0;
}
