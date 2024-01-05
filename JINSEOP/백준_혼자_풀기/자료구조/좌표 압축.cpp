#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
#define ll long long

ll num = 0, coord = 0, coords[1000000];
set<ll> max_heap;
unordered_map<ll, int> index_map;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> coords[i];
		max_heap.insert(coords[i]);
	}

	// 결국 우리가 찾고 싶은 것은
	// 해당 수보다 작은 게 몇 개 있냐?
	
	int idx = 0;
	for (auto i : max_heap) {
		index_map[i] = idx;
		idx++;
	}

	for (int i = 0; i < num; i++)
		cout << index_map[coords[i]] << " ";
	return 0;
}
