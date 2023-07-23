#include <iostream>
#include <vector>
using namespace std;
#define INF 99999999

int paths[1001];
void fill_n_by_m1(int n) {
	for (int i = 0; i <= n; i++)
		paths[i] = INF;

	paths[0] = 0;
}

void count_path(string road, int num) {
	for (int i = 1; i < num; i++) {
		if (road[i] == 'B') {
			for (int j = i; j >= 0; j--) {
				if (road[j] == 'J' && paths[j] != INF)
					paths[i] = min(paths[j] + (j - i) * (j - i), paths[i]);
			}
		}
		if (road[i] == 'O') {
			for (int j = i; j >= 0; j--) {
				if (road[j] == 'B' && paths[j] != INF)
					paths[i] = min(paths[j] + (j - i) * (j - i), paths[i]);
			}
		}
		if (road[i] == 'J') {
			for (int j = i; j >= 0; j--) {
				if (road[j] == 'O' && paths[j] != INF)
					paths[i] = min(paths[j] + (j - i) * (j - i), paths[i]);
			}
		}
	}
}

int main() {
	int num = 0, cursor = 0;
	string road = "";

	cin >> num >> road;
	
	fill_n_by_m1(num);
	count_path(road, num);

	if (paths[num - 1] == INF)
		cout << -1;
	else
		cout << paths[num - 1];

	return 0;
}
