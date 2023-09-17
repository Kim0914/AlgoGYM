#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tc = 0, num = 0;
vector<string> answer;
void backtrack(int curr, int sum, string oper) {
	if (curr == num + 1) {
		if (sum == 0)
			answer.push_back(oper.substr(1));
		return;
	}

	backtrack(curr + 1, sum + curr, oper + "+" + to_string(curr)); // 더하기
	if (curr <= num - 1) // 마지막 칸이 아니라면, 두 칸을 뛰어넘어 숫자 이어붙이기 연산 가능
		backtrack(curr + 2, sum + ((curr * 10) + (curr + 1)), oper + "+" + to_string(curr) + " " + to_string(curr + 1));

	if (curr == 1)
		return;
	// 1을 넣은 상태로 시작하면 되지 않느냐?
	// 그렇게 하면 12로 시작하는 수열을 검사할 수 없다.
	// 또한 이 구문으로 -1로 시작하는 수열을 모두 제외할 수 있다.

	backtrack(curr + 1, sum - curr, oper + "-" + to_string(curr)); // 빼기
	if (curr <= num - 1)
		backtrack(curr + 2, sum - ((curr * 10) + (curr + 1)), oper + "-" + to_string(curr) + " " + to_string(curr + 1));
}

int main(){
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num;
		backtrack(1, 0, "");

		sort(answer.begin(), answer.end());
		for (auto s : answer)
			cout << s << "\n";
		cout << '\n';

		answer.clear();
	}
	return 0;
}
