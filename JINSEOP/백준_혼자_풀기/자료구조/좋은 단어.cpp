#include <iostream>
#include <stack>
using namespace std;

int num = 0, answer = 0;
int main(){
	string target;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> target;
		
		if (target.size() % 2 != 0)
			continue;

		stack<char> ab_stack;
		for (int i = 0; i < target.size(); i++) {
			if (!ab_stack.empty() && ab_stack.top() == target[i])
				ab_stack.pop();
			else
				ab_stack.push(target[i]);
		}

		if (ab_stack.empty())
			answer++;
	}

	cout << answer;
	return 0;
}
