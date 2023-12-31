#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int row = 0, col = 0, cut_num = 0, dir = 0, pos = 0;
vector<int> vertical_pos, horizontal_pos;
vector<int> vertical_diff, horizontal_diff;
int main() {
	cin >> row >> col >> cut_num;
	for (int i = 0; i < cut_num; i++) {
		cin >> dir >> pos;
		// 0은 가로 1은 세로
		if (dir == 0)
			vertical_pos.push_back(pos);
		else
			horizontal_pos.push_back(pos);
	}

	vertical_pos.push_back(col);
	horizontal_pos.push_back(row);

	sort(vertical_pos.begin(), vertical_pos.end());
	sort(horizontal_pos.begin(), horizontal_pos.end());

	vertical_diff.push_back(vertical_pos[0]);
	horizontal_diff.push_back(horizontal_pos[0]);

	for (int i = 1; i < vertical_pos.size(); i++)
		vertical_diff.push_back(vertical_pos[i] - vertical_pos[i - 1]);

	for (int i = 1; i < horizontal_pos.size(); i++)
		horizontal_diff.push_back(horizontal_pos[i] - horizontal_pos[i - 1]);

	sort(vertical_diff.begin(), vertical_diff.end());
	sort(horizontal_diff.begin(), horizontal_diff.end());

	cout << vertical_diff[vertical_pos.size() - 1] * horizontal_diff[horizontal_diff.size() - 1];
	return 0;
}
