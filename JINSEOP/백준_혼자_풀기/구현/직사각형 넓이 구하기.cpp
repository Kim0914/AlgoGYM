#include <iostream>
using namespace std;

int quadrant[100][100];
int st_x = 0, st_y = 0, end_x = 0, end_y = 0;
void draw_rectangle() {
	for (int row = st_y + 1; row <= end_y; row++)
		for (int col = st_x + 1; col <= end_x; col++)
			quadrant[row][col] = 1;
}

int count_area() {
	int area = 0;

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (quadrant[i][j] == 1)
				area++;

	return area;
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> st_x >> st_y >> end_x >> end_y;
		draw_rectangle();
	}

	cout << count_area();
	return 0;
}
