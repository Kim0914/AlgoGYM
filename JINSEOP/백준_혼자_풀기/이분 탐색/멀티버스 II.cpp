#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num = 0, planet_num = 0;
int multiverse[100][10000];
void compress_coordinate() {
	for (int i = 0; i < num; i++) {
		vector<int> max_heap;

		for (int j = 0; j < planet_num; j++) {
			cin >> multiverse[i][j];
			max_heap.push_back(multiverse[i][j]);
		}

		sort(max_heap.begin(), max_heap.end());
		max_heap.erase(unique(max_heap.begin(), max_heap.end()), max_heap.end());
		for (int j = 0; j < planet_num; j++) {
			int idx = lower_bound(max_heap.begin(), max_heap.end(), multiverse[i][j]) - max_heap.begin();
			multiverse[i][j] = idx;
		}
	}
}

bool check_compressed_coordinate(int src, int dest) {
	for (int i = 0; i < planet_num; i++) {
		if (multiverse[src][i] != multiverse[dest][i])
			return false;
	}

	return true;
}

int main() {
	cin >> num >> planet_num;
	compress_coordinate();

	int answer = 0;
	for (int i = 0; i < num - 1; i++)
		for (int j = i + 1; j < num; j++)
			if (check_compressed_coordinate(i, j))
				answer++;

	cout << answer;
	return 0;
}
