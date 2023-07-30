#include <iostream>
#include <vector>
using namespace std;

int kdp[101][100001];
int main() {
	int num = 0, limit = 0;
	cin >> num >> limit;

	vector<int> weights(num + 1, 0);
	vector<int> values(num + 1, 0);

	for (int i = 1; i <= num; i++)
		cin >> weights[i] >> values[i];

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= limit; j++) {
			if (j - weights[i] >= 0) kdp[i][j] = max(kdp[i - 1][j], kdp[i - 1][j - weights[i]] + values[i]);
			else kdp[i][j] = kdp[i - 1][j];
		}
	}

	cout << kdp[num][limit];
	return 0;
}
