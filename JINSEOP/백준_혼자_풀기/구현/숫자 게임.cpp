#include <iostream>
#include <vector>
using namespace std;

int num = 0, temp_sum = 0, partial_sum = 0, answer = 0, answer_idx = 0;
int game_board[1001][5];
vector<int> sum_vec;
void make_combination(int curr_idx, int target, int depth) {
	if (depth == 3) {
		if ((temp_sum % 10) > (partial_sum % 10))
			partial_sum = temp_sum;

		return;
	}

	for (int i = curr_idx + 1; i < 5; i++) {
		temp_sum += game_board[target][i];
		make_combination(i, target, depth + 1);
		temp_sum -= game_board[target][i];
	}
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		for(int j = 0; j < 5; j++)
			cin >> game_board[i][j];
	// 1 ~ 10의 정수가 주어진다.
	// 1의 자리가 가장 큰 사람의 번호를 출력한다.

	for (int i = 1; i <= num; i++) {
		partial_sum = 0;

		for (int j = 0; j < 3; j++) {
			temp_sum = game_board[i][j];
			make_combination(j, i, 1);
		}

		sum_vec.push_back(partial_sum % 10);
		// 1의 자리를 저장해야 함
	}

	for (int i = 0; i < sum_vec.size(); i++) {
		if (answer <= sum_vec[i]) {
			answer = sum_vec[i];
			answer_idx = i + 1;
		}
	}

	cout << answer_idx;
	return 0;
}
