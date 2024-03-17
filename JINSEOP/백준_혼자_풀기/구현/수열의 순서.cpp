#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long num = 0, prob_num = 0, target_num = 0, digit = 0, answer_idx = 0;
vector<int> target_perm, answer;
long long factorial[21];
bool visit[21];
void optimize() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void init_factorial() {
	factorial[0] = 1;
	for (int i = 1; i <= 20; i++)
		factorial[i] = factorial[i - 1] * i;
}

int main() {
	optimize();
	init_factorial();

	cin >> num;
	cin >> prob_num;
	if (prob_num == 1) {
		cin >> target_num;
		
		for (int i = 0; i < num; i++) {
			for (int j = 1; j <= num; j++) {
				if (!visit[j]) {
					if (factorial[num - i - 1] < target_num)
						target_num -= factorial[num - i - 1];
					// 목표한 숫자보다 팩토리얼 값이 작으면?
					// 목표 숫자에서 깎아서 
					else {
						answer.push_back(j);
						visit[j] = true;
						break;
					}
					// 목표 숫자보다 커지는 순간 멈춘다.
				}
			}
		}

		for (auto i : answer)
			cout << i << " ";
	}
	else {
		for (int i = 0; i < num; i++) {
			cin >> digit;
			target_perm.push_back(digit);
		}

		for (int i = 0; i < target_perm.size(); i++) {
			int curr_num = target_perm[i];
			for (int j = 1; j < curr_num; j++) {
				if (!visit[j])
					answer_idx += factorial[num - i - 1];
				// 1부터 현재 값까지 훑으며 사용하지 않은 값 확인
				// 숫자 하나 당 (n - i - 1)!의 수를 가질 수 있다.
				// 왜? 예를 들어 3 4 2 1 이라고 가정해보자.
				// 3이 제일 첫 자리에 와있으니 (4 - 1)!개의 조합을 가진다.
				// 또한 3보다 작은 수는 1 2 뿐이니, 2 X 3!이 된다.

				// 다음으로 오는 4의 경우, (4 - 2)! 개의 조합을 가진다.
				// 4보다 작은 수는 1 2 3인데 3은 이미 사용했으니, 2 X 2!개가 된다.
			}

			visit[curr_num] = true;
		}

		cout << answer_idx + 1;
		// 위에서 계산한 값의 바로 다음 순서이니, +1을 해야함
	}

	return 0;
}
