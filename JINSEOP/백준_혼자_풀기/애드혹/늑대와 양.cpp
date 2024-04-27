#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int row = 0, col = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<string> sheep_wolf_map;
int main() {
	OPTIMIZE;
	cin >> row >> col;

	string temp = "";
	for (int i = 0; i < row; i++) {
		cin >> temp;
		sheep_wolf_map.push_back(temp);
	}

	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++){
			if (sheep_wolf_map[i][j] == 'W') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
						if (sheep_wolf_map[nx][ny] == 'S') {
							cout << 0;
							return 0;
						}
						else if (sheep_wolf_map[nx][ny] == 'W')
							continue;
						else
							sheep_wolf_map[nx][ny] = 'D';
					}
				}
			}
		}
	}

	cout << 1 << '\n';
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << sheep_wolf_map[i][j];
		}
		cout << '\n';
	}

	return 0;
}
