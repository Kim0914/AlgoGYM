#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> milks;
int num = 0, answer = 0, milk = 0;
int main(){
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> milk;
		milks.push_back(milk);
	}

	sort(milks.begin(), milks.end(), greater<>());

	for (int i = 0; i < milks.size(); i++) {
		if ((i+1) % 3 == 0)
			continue;

		answer += milks[i];
	}

	cout << answer;
	return 0;
}
