#include <iostream>
using namespace std;
#define ll long long

int num = 0, limit = 0;
int merge_bottle() {
	int temp_num = num;
	int rest_bottle = 0;

	while (temp_num > 0) {
		if (temp_num % 2 == 1)
			rest_bottle++;
		// 2로 나눈 나머지가 1이면?
		// 병이 1개 남는다는 의미이다.

		temp_num >>= 1;
	}

	return rest_bottle;
}

int main() {
	cin >> num >> limit;
	// limit개를 넘지 않는 물병.

	int answer = 0;
	if (num <= limit)
		cout << 0;
	else {
		while (true) {
			if (merge_bottle() <= limit)
				break;
			// 남는 물병이 limit개 이하면
			// 들고 갈 수 있다.

			num++;
			answer++;
		}

		cout << answer;
	}
	return 0;
}
