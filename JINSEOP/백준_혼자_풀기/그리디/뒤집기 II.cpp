#include <iostream>
#include <vector>
using namespace std;

int row = 0, col = 0;
vector<string> coin_map;
void flip_coin(int x, int y) {
	for (int i = 0; i <= x; i++)
		for (int j = 0; j <= y; j++)
			coin_map[i][j] == '0' ? coin_map[i][j] = '1' : coin_map[i][j] = '0';
}

int main()
{
	cin >> row >> col;

	string coin_state = "";
	for (int i = 0; i < row; i++) {
		cin >> coin_state;
		coin_map.push_back(coin_state);
	}

	int answer = 0;
	for (int i = row - 1; i >= 0; i--) {
		for (int j = col - 1; j >= 0; j--) {
			if (coin_map[i][j] == '1') {
				flip_coin(i, j);
				answer++;
			}
		}
	}

	cout << answer;
	return 0;
}
