#include <iostream>
using namespace std;

int row = 0, neg_paper = 0, zero_paper = 0, pos_paper = 0;
int color_paper[2187][2187];
pair<bool, pair<bool, bool>> check_compression(int x, int y, int limit) {
	bool neg_flag = true, zero_flag = true, pos_flag = true;

	for (int i = x; i < x + limit; i++) {
		for (int j = y; j < y + limit; j++) {
			if (color_paper[i][j] == -1) {
				zero_flag = false;
				pos_flag = false;
			}
			
			if (color_paper[i][j] == 1) {
				zero_flag = false;
				neg_flag = false;
			}

			if (color_paper[i][j] == 0) {
				neg_flag = false;
				pos_flag = false;
			}
		}
	}

	return { neg_flag, { zero_flag, pos_flag } };
}

void cut_paper(int x, int y, int limit) {
	if (limit == 1) {
		if (color_paper[x][y] == -1)
			neg_paper++;
		if (color_paper[x][y] == 0)
			zero_paper++;
		if (color_paper[x][y] == 1)
			pos_paper++;

		return;
	}

	pair<bool, pair<bool, bool>> flag_pair = check_compression(x, y, limit);

	if (flag_pair.first)
		neg_paper++;
	else if (flag_pair.second.first)
		zero_paper++;
	else if (flag_pair.second.second)
		pos_paper++;
	else {
		// 상단 3개 순서대로 좌, 중, 우
		cut_paper(x, y, limit / 3);
		cut_paper(x, y + limit / 3, limit / 3);
		cut_paper(x, y + (limit / 3) * 2, limit / 3);
		// 중단 3개 순서대로 좌, 중, 우
		cut_paper(x + limit / 3, y, limit / 3);
		cut_paper(x + limit / 3, y + limit / 3, limit / 3);
		cut_paper(x + limit / 3, y + (limit / 3) * 2, limit / 3);
		// 하단 3개 순서대로 좌, 중, 우
		cut_paper(x + (limit / 3) * 2, y, limit / 3);
		cut_paper(x + (limit / 3) * 2, y + limit / 3, limit / 3);
		cut_paper(x + (limit / 3) * 2, y + (limit / 3) * 2, limit / 3);
	}

	return;
}

int main() {
	cin >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> color_paper[i][j];

	cut_paper(0, 0, row);
	cout << neg_paper << '\n' << zero_paper << '\n' << pos_paper;

	return 0;
}
