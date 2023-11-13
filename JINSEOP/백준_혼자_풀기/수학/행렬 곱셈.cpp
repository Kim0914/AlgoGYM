#include <iostream>
using namespace std;

int row = 0, col = 0, row_b = 0, col_b = 0;
int mat_A[100][100], mat_B[100][100], mat_fin[100][100];
void calculate() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col_b; j++)
			for (int k = 0; k < col; k++) 
				mat_fin[i][j] += (mat_A[i][k] * mat_B[k][j]);
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> mat_A[i][j];
	
	cin >> row_b >> col_b;
	for (int i = 0; i < row_b; i++)
		for (int j = 0; j < col_b; j++)
			cin >> mat_B[i][j];

	calculate();

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col_b; j++)
			cout << mat_fin[i][j] << " ";
		cout << '\n';
	}

	return 0;
}
