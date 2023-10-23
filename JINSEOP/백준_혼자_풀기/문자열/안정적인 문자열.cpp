#include <iostream>
#include <stack>
using namespace std;

int tc = 1;
int main(){
	string braces;
	stack<char> brace_validator;
	while (true) {
		int answer = 0;
		cin >> braces;
		if (braces[0] == '-')
			break;

		for (int i = 0; i < braces.size(); i++) {
			if (!brace_validator.empty() && braces[i] == '}') {
				if (brace_validator.top() == '{') {
					brace_validator.pop();
					continue;
				}
			}

			brace_validator.push(braces[i]);
		} // 여기는 옳은 괄호 찾기랑 같음

		while (!brace_validator.empty()) {
			char target1 = brace_validator.top();
			brace_validator.pop();
			char target2 = brace_validator.top();
			brace_validator.pop();
			// 항상 길이가 짝수이기 때문에 이게 가능하다.

			if (target1 == target2)
				answer++;
			else
				answer += 2;
		}

		cout << tc << ". " << answer << '\n';
		tc++;
	}

	return 0;
}
