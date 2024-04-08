#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll row = 0, col = 0, result = 0;
ll board[50][50];
ll get_sum(int row_start, int row_end, int col_start, int col_end) {
	ll sum = 0;

	for (int i = row_start; i < row_end; i++)
		for (int j = col_start; j < col_end; j++)
			sum += board[i][j];

	return sum;
}

int main(){
	cin >> row >> col;
	
	string temp = "";
	for (int i = 0; i < row; i++) {
		cin >> temp;
		for (int j = 0; j < col; j++) {
			board[i][j] = temp[j] - '0';
		}
	}
	
	// 나눌 수 있는 경우는 총 6가지
	// 1. 가로 3등분, 2. 세로 3등분
	// 3. ㅏ 모양, 4. ㅜ 모양 5. ㅓ 모양, 6. ㅗ 모양

	ll partial_result = 1;

	for (int i = 1; i < row - 1; i++) {
		for (int j = i + 1; j < row; j++) {
			partial_result = 1;

			partial_result *= get_sum(0, i, 0, col);
			partial_result *= get_sum(i, j, 0, col);
			partial_result *= get_sum(j, row, 0, col);

			result = max(partial_result, result);
		}
	} // 1. 가로로 3등분 하는 경우

	for (int i = 1; i < col - 1; i++) {
		for (int j = i + 1; j < col; j++) {
			partial_result = 1;

			partial_result *= get_sum(0, row, 0, i);
			partial_result *= get_sum(0, row, i, j);
			partial_result *= get_sum(0, row, j, col);

			result = max(partial_result, result);
		}
	} // 2. 세로로 3등분 하는 경우

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			partial_result = 1;

			partial_result *= get_sum(0, row, 0, j);
			partial_result *= get_sum(0, i, j, col);
			partial_result *= get_sum(i, row, j, col);

			result = max(partial_result, result);
		}
	} // 3. ㅏ 모양으로 자르는 경우, row 하나 col 하나 골라야 한다.

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			partial_result = 1;

			partial_result *= get_sum(0, i, 0, col);
			partial_result *= get_sum(i, row, 0, j);
			partial_result *= get_sum(i, row, j, col);

			result = max(partial_result, result);
		}
	} // 4. ㅜ 모양으로 자르는 경우, row 하나 col 하나 골라야 한다.

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			partial_result = 1;

			partial_result *= get_sum(0, i, 0, j);
			partial_result *= get_sum(i, row, 0, j);
			partial_result *= get_sum(0, row, j, col);

			result = max(partial_result, result);
		}
	} // 5. ㅓ 모양으로 자르는 경우, row 하나 col 하나 골라야 한다.

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			partial_result = 1;

			partial_result *= get_sum(0, i, 0, j);
			partial_result *= get_sum(0, i, j, col);
			partial_result *= get_sum(i, row, 0, col);

			result = max(partial_result, result);
		}
	} // 6. ㅗ 모양으로 자르는 경우, row 하나 col 하나 골라야 한다.

	cout << result;
	return 0;
}
