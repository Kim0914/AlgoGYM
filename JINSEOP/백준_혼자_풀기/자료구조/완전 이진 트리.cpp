#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int num = 0, node = 0;
vector<int> binary_tree;
vector<int> print_vec[11];
void binary_search(int left, int right, int depth){
	if (depth > num)
		return;

	int mid = (left + right) / 2;
	print_vec[depth].push_back(binary_tree[mid]);
	// 동일한 깊이의 노드를 같은 행에 저장.

	binary_search(left, mid, depth + 1);
	binary_search(mid + 1, right, depth + 1);
}

int main() {
	cin >> num;
	for (int i = 0; i < pow(2, num) - 1; i++) {
		cin >> node;
		binary_tree.push_back(node); 
		// 중위 순회(Inorder)의 순서임을 알 수 있다.
	}

	binary_search(0, (pow(2, num) - 1) - 1, 1);
	// 중위 순회의 트리 구조는 가운데가 루트이다.
	// 따라서 이진 탐색과 같이 가운데를 찾아나간다.

	for (int i = 1; i <= num; i++) { // depth 별로 출력
		for (int j = 0; j < print_vec[i].size(); j++)
			cout << print_vec[i][j] << " ";

		cout << '\n';
	}

	return 0;
}
