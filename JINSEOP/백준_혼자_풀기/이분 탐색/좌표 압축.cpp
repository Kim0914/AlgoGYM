#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0;
int seq[1000000];
vector<int> press;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> seq[i];
		press.push_back(seq[i]);
	}

	sort(press.begin(), press.end());
	press.erase(unique(press.begin(), press.end()), press.end());

	for (int i = 0; i < num; i++)
		cout << lower_bound(press.begin(), press.end(), seq[i]) - press.begin() << " ";
	return 0;
}
