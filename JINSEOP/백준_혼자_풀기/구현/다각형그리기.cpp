#include <iostream>
#include <vector>
using namespace std;

int len = 0, num = 0;
int specimen[50], seq[50][100];
vector<int> answer_vec;
void reverse_sequence(int target, int rev_seq[50]) {
	for (int i = 0; i < len; i++) {
		switch (seq[target][i])
		{
			case 1:
				rev_seq[i] = 3;
				break;
			case 2:
				rev_seq[i] = 4;
				break;
			case 3:
				rev_seq[i] = 1;
				break;
			case 4:
				rev_seq[i] = 2;
				break;
		}
	}
}

bool check_sequence(int target) {
	for (int i = 0; i < len; i++) {
		int iter = 0;

		while (true) {
			if (specimen[iter] == seq[target][(iter + i) % len])
				iter++;
			else
				break;

			if (iter >= len)
				return true;
		}
	}

	return false;
}

bool check_reversed_sequence(int target) {
	int rev_seq[50];
	reverse_sequence(target, rev_seq);
	
	for (int i = 0; i < len; i++) {
		int iter = 0;
		int reversed_iter = len - 1;

		while (true) {
			if (specimen[reversed_iter] == rev_seq[(iter + i) % len]) {
				iter++;
				reversed_iter--;
			}
			else
				break;

			if (iter >= len || reversed_iter <= 0)
				return true;
		}
	}

	return false;
}

int main() {
	cin >> len;
	for (int i = 0; i < len; i++)
		cin >> specimen[i];

	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < len; j++)
			cin >> seq[i][j];

		// 여기서 동일 모양인지 검사
		// 1. 아예 동일한 순서를 가졌거나
		// 2. 2 -> 4 -> 2, 3 -> 1 -> 3 으로 뒤집었을 때 동일 순서여야 함
		if (check_sequence(i))
			answer_vec.push_back(i);
		else if (check_reversed_sequence(i))
			answer_vec.push_back(i);
	}

	cout << answer_vec.size() << '\n';
	for (int i = 0; i < answer_vec.size(); i++) {
		for (int j = 0; j < len; j++)
			cout << seq[answer_vec[i]][j] << " ";

		cout << '\n';
	}

	return 0;
}
