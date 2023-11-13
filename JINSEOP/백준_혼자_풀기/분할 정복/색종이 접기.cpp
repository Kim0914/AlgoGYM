#include <iostream>
using namespace std;

int row = 0, white_paper = 0, blue_paper = 0;
int color_paper[128][128];
pair<bool, bool> check_compression(int x, int y, int limit) {
	bool white_flag = true, blue_flag = true;

	for (int i = x; i < x + limit; i++) {
		for (int j = y; j < y + limit; j++) {
			if (color_paper[i][j])
				white_flag = false;
			else
				blue_flag = false;
		}
	}

	return { white_flag, blue_flag };
}

void cut_paper(int x, int y, int limit) {
	if (limit == 1) {
		if (color_paper[x][y])
			blue_paper++;
		else
			white_paper++;

		return;
	}

	pair<bool, bool> flag_pair = check_compression(x, y, limit);

	if (flag_pair.first)
		white_paper++;
	else if (flag_pair.second)
		blue_paper++;
	else {
		cut_paper(x, y, limit / 2);
		cut_paper(x, y + limit/2, limit / 2);
		cut_paper(x + limit/2, y, limit / 2);
		cut_paper(x + limit/2, y + limit/2, limit / 2);
	}

	return;
}

int main() {
	cin >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> color_paper[i][j];

	cut_paper(0, 0, row);
	cout << white_paper << '\n' << blue_paper;

	return 0;
}
