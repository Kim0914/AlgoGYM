#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tc = 0, stock = 0, days = 0;

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		long long cursor = 0, res = 0;
		vector<int> stocks;
		cin >> days;

		for (int i = 0; i < days; i++) {
			cin >> stock;
			stocks.push_back(stock);
		}

		for (int i = stocks.size() - 1; i >= 0; i--) {
			if (cursor < stocks[i]) {
				cursor = stocks[i];
			}
			else {
				res += cursor - stocks[i];
			}
		}

		cout << res << '\n';
	}

	return 0;
}
