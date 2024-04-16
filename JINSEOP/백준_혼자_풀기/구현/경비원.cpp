#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pii pair<int, int>

int row = 0, col = 0, num = 0, x = 0, y = 0;
vector<pii> coords;
pii dong_coord;
int main() {
	OPTIMIZE;

	cin >> col >> row >> num;
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		switch (x)
		{
		case 1:
			coords.push_back({y, 0});
			break;
		case 2:
			coords.push_back({y, row});
			break;
		case 3:
			coords.push_back({0, y});
			break;
		case 4:
			coords.push_back({col, y});
			break;
		}
	}
	cin >> x >> y;
	switch (x)
	{
	case 1:
		dong_coord = {y, 0};
		break;
	case 2:
		dong_coord = {y, row};
		break;
	case 3:
		dong_coord = { 0, y };
		break;
	case 4:
		dong_coord = { col, y };
		break;
	}

	int sum = 0;
	for (int i = 0; i < coords.size(); i++) {
		int curr_x = coords[i].first; // 가로
		int curr_y = coords[i].second; // 세로

		if (dong_coord.first - curr_x == 0 && (curr_x == 0 || curr_x == col)) { // 같은 세로줄에 있을 때
			sum += abs(dong_coord.second - curr_y);
			continue;
		}
		if (dong_coord.second - curr_y == 0 && (curr_y == 0 || curr_y == row)) {
			sum += abs(dong_coord.first - curr_x); // 같은 가로줄에 있을 때
			continue;
		}

		if (dong_coord.first == 0) { // 서쪽에 위치
			sum += curr_x;

			if (curr_x != col || curr_x != 0)
				sum += abs(curr_y - dong_coord.second);
			else
				sum += min(dong_coord.second + curr_y, (row - dong_coord.second) + (row - curr_y));
		}

		if (dong_coord.first == col) { // 동쪽에 위치
			sum += (dong_coord.first - curr_x);

			if (curr_x != col || curr_x != 0)
				sum += abs(curr_y - dong_coord.second);
			else
				sum += min(dong_coord.second + curr_y, (row - dong_coord.second) + (row - curr_y));
		}

		if (dong_coord.second == 0) { // 북쪽에 위치
			sum += curr_y;

			if (curr_y != row || curr_y != 0)
				sum += abs(curr_x - dong_coord.first);
			else
				sum += min(dong_coord.first + curr_x, (col - dong_coord.first) + (col - curr_x));
		}

		if (dong_coord.second == row) { // 남쪽에 위치
			sum += (dong_coord.second - curr_y);

			if (curr_y != 0)
				sum += abs(curr_x - dong_coord.first);
			else
				sum += min(dong_coord.first + curr_x, (col - dong_coord.first) + (col - curr_x));
		}
	}

	cout << sum;
	return 0;
}
