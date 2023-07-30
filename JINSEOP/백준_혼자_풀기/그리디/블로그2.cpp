#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<char, int> prob_map;
stack<char> prob_stack;
int main() {
	int len = 0, br_cnt = 1;
	string probs = "";

	cin >> len >> probs;
	prob_map[probs[0]]++;
	prob_stack.push(probs[0]);

	for (int i = 1; i < len; i++) {
		if (!prob_stack.empty()) {
			if (prob_stack.top() != probs[i])
				prob_stack.push(probs[i]);
		}
	}

	probs = "";

	while (!prob_stack.empty()) {
		probs += prob_stack.top();
		prob_map[prob_stack.top()]++;
		prob_stack.pop();
	}

	for (int i = 0; i < probs.size(); i++) {
		if (prob_map['B'] >= prob_map['R']) {
			if (probs[i] == 'R')
				br_cnt++;
		}
		else {
			if (probs[i] == 'B')
				br_cnt++;
		}
	}

	cout << br_cnt;
	return 0;
}
