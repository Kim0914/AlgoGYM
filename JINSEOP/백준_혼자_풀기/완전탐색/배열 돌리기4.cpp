#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<pair<pair<int, int>, int>> oper_list;
int origin_matrix[51][51], copied_matrix[51][51], oper_sequence[6];
bool visit[6];
int row = 0, col = 0, oper = 0, op_row = 0, op_col = 0, stride = 0;
int answer = INT_MAX;
void copy_matrix() {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			copied_matrix[i][j] = origin_matrix[i][j];
}

void rotate_matrix(int target_row, int target_col, int target_stride) {
	for (int std = 1; std <= target_stride; std++) {
		int last_piece = copied_matrix[target_row - std][target_col - std];

		// 왼쪽부터 (target_row, target_col) 기준으로 stride 만큼 진행
		// target_row - standard + 1 번째 칸 부터, 자신의 값을 다음(위) 칸에 대입
		for (int j = target_row - std + 1; j <= target_row + std; j++)
			copied_matrix[j - 1][target_col - std] = copied_matrix[j][target_col - std];
		// 아래
		for (int j = target_col - std + 1; j <= target_col + std; j++)
			copied_matrix[target_row + std][j - 1] = copied_matrix[target_row + std][j];
		// 오른쪽
		for (int j = target_row + std - 1; j >= target_row - std; j--)
			copied_matrix[j + 1][target_col + std] = copied_matrix[j][target_col + std];
		// 위쪽
		for (int j = target_col + std - 1; j >= target_col - std; j--)
			copied_matrix[target_row - std][j + 1] = copied_matrix[target_row - std][j];

		copied_matrix[target_row - std][target_col - std + 1] = last_piece;
		// 위의 코드대로 진행하면 모서리의 한 조각이 무조건 남는다.
		// 미리 저장 해놓은 해당 조각을 앞 칸에 대입
	}
}

void calculate_matrix() {
	for (int i = 1; i <= row; i++) {
		int partial_sum = 0;

		for (int j = 1; j <= col; j++)
			partial_sum += copied_matrix[i][j];

		answer = min(answer, partial_sum);
	}
	// 최소 A값 저장
}

void simulate() {
	for (int i = 0; i < oper; i++) {
		int order = oper_sequence[i];

		// 순서에 맞게 행렬을 회전 시킨다.
		rotate_matrix(oper_list[order].first.first, oper_list[order].first.second, oper_list[order].second);
	}
}

void permutate(int depth) {
	if (depth == oper) {
		// A값 계산해야 하는 자리
		copy_matrix(); // 원본 배열 복사
		simulate();
		calculate_matrix();
		return;
	}

	for (int i = 0; i < oper; i++) {
		if (!visit[i]) {
			visit[i] = true;
			oper_sequence[depth] = i;
			permutate(depth + 1);
			visit[i] = false;
		}
	}
}

int main(){
	cin >> row >> col >> oper;

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			cin >> origin_matrix[i][j];

	for (int i = 0; i < oper; i++) {
		cin >> op_row >> op_col >> stride;
		oper_list.push_back({{op_row, op_col}, stride});
	}

	permutate(0);
	cout << answer;

	return 0;
}
