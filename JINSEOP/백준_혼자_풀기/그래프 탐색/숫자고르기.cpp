#include <iostream>
#include <vector>
#include <set>
using namespace std;

int len = 0, num = 0, max_size = 0;
vector<int> bottom_vec;
string top_bit = "0";
string bottom_bit = "0";
string max_bit = "0";
void print_bit() {
	for (int i = 0; i < max_bit.size(); i++)
		if (max_bit[i] == '1')
			cout << i << '\n';
}

void backtrack(int depth, int idx, vector<bool> &visit) {
	if (top_bit == bottom_bit && depth != 0) {
		if (depth > max_size) {
			max_size = depth;
			max_bit = top_bit;
		}
	}

	for (int i = idx; i < len; i++) {
		if (!visit[i]) {
			top_bit[i + 1] = '1'; bottom_bit[bottom_vec[i]] = '1';
			visit[i] = true;
			backtrack(depth + 1, i, visit);
			top_bit[i + 1] = '0'; bottom_bit[bottom_vec[i]] = '0';
			visit[i] = false;
		}
	}
}

int main() {
	cin >> len;
	vector<bool> visit(len, false);

	for (int i = 0; i < len; i++) {
		cin >> num;
		bottom_vec.push_back(num); // 아래 집합 저장
		top_bit += "0"; bottom_bit += "0"; max_bit += "0";
		// 비트마스킹 용 비트 생성
	}

	backtrack(0, 0, visit);
	cout << max_size << '\n';
	print_bit();

	return 0;
}
