#include <iostream>
using namespace std;

int row = 0;
int quad_tree[64][64];
string temp_input = "";
pair<bool, bool> check_compression(int x_idx, int y_idx, int len) {
	bool zero_flag = true, one_flag = true;

	for (int i = x_idx; i < x_idx + len; i++) {
		for (int j = y_idx; j < y_idx + len; j++) {
			if (quad_tree[i][j])
				zero_flag = false;
			// 4방향 검사 시, 1이 등장하면 zero flag는 당연히 false이다.
			else
				one_flag = false;
			// 0이 등장하면 당연히 one flag는 false이다.
		}
	}

	return { zero_flag, one_flag };
}

void compress_quad_tree(int x_idx, int y_idx, int len) {
	if (len == 1) {
		// 길이가 1까지 왔다면 그냥 출력을 하면 된다.
		cout << quad_tree[x_idx][y_idx];
		return;
	}

	pair<bool, bool> flag_pair = check_compression(x_idx, y_idx, len);
  // 0이나 1로 압축이 가능한지 검사하는 함수
  
	if (flag_pair.first) // 모두 0인 경우
		cout << 0;
	else if (flag_pair.second)
		cout << 1; // 모두 1인 경우
	else { // 0과 1이 섞여있는 경우
		cout << "(";
		// 쿼드트리의 기본, 순서를 반드시 맞춰주어야 함.
		compress_quad_tree(x_idx, y_idx, len/2); // 왼쪽 위
		compress_quad_tree(x_idx, y_idx + len/2, len/2); // 오른쪽 위
		compress_quad_tree(x_idx + len/2, y_idx, len/2); // 왼쪽 아래
		compress_quad_tree(x_idx + len/2, y_idx + len/2, len/2); // 오른쪽 아래
		cout << ")";
	}

	return;
}

int main() {
	cin >> row;
	for (int i = 0; i < row; i++) {
		cin >> temp_input;
		for (int j = 0; j < temp_input.size(); j++)
			quad_tree[i][j] = temp_input[j] - '0';
	}

	compress_quad_tree(0, 0, row);

	return 0;
}
