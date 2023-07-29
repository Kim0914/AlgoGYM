#include <iostream>
#include <vector>
using namespace std;

bool src_mat[50][50];
bool dest_mat[50][50];
void flip_matrix(int x, int y) {
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++)
			src_mat[i][j] = !src_mat[i][j];
}

int main() {
	int row = 0, col = 0, result = 0; 
	char cell;

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> cell;
			src_mat[i][j] = (cell == '1') ? true : false;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> cell;
			dest_mat[i][j] = (cell == '1') ? true : false;;
		}
	}

	for (int i = 0; i < row - 2; i++) {
		for (int j = 0; j < col - 2; j++) {
			if (src_mat[i][j] != dest_mat[i][j]) {
				flip_matrix(i, j);
				result++;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (src_mat[i][j] != dest_mat[i][j]) {
				result = -1;
				break;
			}
		}
	}

	cout << result;

	return 0;
}
