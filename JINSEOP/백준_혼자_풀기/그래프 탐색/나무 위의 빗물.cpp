#include <iostream>
#include <cmath>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int vertices = 0, from = 0, to = 0;
double init_water = 0;
int degree[500001];
int main() {
	OPTIMIZE;

	cin >> vertices >> init_water;
	for (int i = 0; i < vertices - 1; i++) {
		cin >> from >> to;
		degree[from]++;
		degree[to]++;
	}

	double leaf_node_cnt = 0;
	for (int i = 2; i <= vertices; i++)
		if (degree[i] == 1) // 진출차수가 1이면 Leaf node
			leaf_node_cnt++;

	cout.precision(10);
	cout << init_water / leaf_node_cnt;
	// 어차피 Pi > 0인 노드들의 기대값의 합은?
	// 초기 init_water과 동일한 값이다.
	// 따라서 어차피 물은 단말에 고이게 되니, 단말로 나눠주면 된다.
	return 0;
}
