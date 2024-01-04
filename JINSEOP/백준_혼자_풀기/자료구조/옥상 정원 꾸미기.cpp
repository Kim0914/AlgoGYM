#include <iostream>
#include <stack>
using namespace std;
#define ll long long

ll num = 0, answer = 0;
ll buildings[80000];
stack<ll> building_stack;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> buildings[i];

	building_stack.push(buildings[0]);
	for (int i = 1; i < num; i++) {
		while (!building_stack.empty() && building_stack.top() <= buildings[i])
			building_stack.pop();

		answer += building_stack.size();
		building_stack.push(buildings[i]);
	}

	cout << answer;
	return 0;
}
