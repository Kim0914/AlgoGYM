#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num = 0, par_n = 0, left_n = 0, right_n = 0, left_cnt = -1, right_cnt = -1;
pair<int, int> bi_tree[100001];
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void inorder(int curr_node, bool right_flag) {
	if (curr_node == -1)
		return;

	left_cnt++;
	inorder(bi_tree[curr_node].first, 0);

	if (right_flag) {
	// 여긴 가장 끝 오른쪽 부분만 해당한다.
		right_cnt++;
		inorder(bi_tree[curr_node].second, 1);
	}
	// 나머지 오른쪽 부분은 여기로 들어간다.
	else inorder(bi_tree[curr_node].second, 0);
}

int main() {
	optimize();

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> par_n >> left_n >> right_n;

		bi_tree[par_n].first = left_n;
		bi_tree[par_n].second = right_n;
	}

	inorder(1, 1);
	// 전체 순회 과정에서 가장 오른쪽 부분만 빼면 된다.
	// 중위 순회의 끝은 가장 오른쪽이기 때문에, 다시 올라오지 않음!
	cout << 2 * left_cnt - right_cnt;
	return 0;
}
