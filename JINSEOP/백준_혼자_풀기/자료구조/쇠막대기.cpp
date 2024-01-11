#include <iostream>
#include <stack>
using namespace std;

stack<char> validator;
string parenthesis;
int answer = 0;
bool laser_turn = false;
int main() {
	cin >> parenthesis;
	for (auto c : parenthesis) {
		if (c == '(') {
			validator.push(c);
			laser_turn = true;
			// 여는 괄호가 들어감
			// 다음으로 나오는 첫 닫는 괄호는 레이저가 됨
		}
		if (!validator.empty() && validator.top() == '(' && c == ')') {
		// 레이저가 쏴지는 순간
			if (validator.size() == 1 && laser_turn) {
				validator.pop(); // 막대가 없을 때
				laser_turn = false;
			}
			else if (validator.size() > 1 && laser_turn) {
				validator.pop(); // 레이저 제거

				answer += validator.size();
				laser_turn = false;
				// 크기가 1보다 크면, 막대가 들어있는 것
				// 다음 닫는 괄호는 레이저가 아님
			}
			else if (!laser_turn) {
				answer += 1;
				// 레이저가 아닌데 닫는 괄호이면 토막을 하나 더 해줌
				validator.pop(); // 막대 제거
			}
		}
	}

	cout << answer;
	return 0; 
}
