#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

int row = 0, col = 0;
unordered_map<string, bool> str_map;
bool remove_row(int height, vector<string> table_vec) {
	for (int i = 0; i < col; i++) {
		string temp_str = "";

		for (int j = height + 1; j < row; j++)
			temp_str += table_vec[j][i];

		if (str_map[temp_str])
			return true;
		// 중복되는 경우, 자르는 범위를 더 줄여봐야 함
		str_map[temp_str] = true;
	}

	return false;
	// 중복되는 게 없는 경우, 자르는 범위를 늘려야 함
}

int main()
{
	cin >> row >> col;
	
	string content = "";
	vector<string> table_vec;
	for (int i = 0; i < row; i++) {
		cin >> content;
		table_vec.push_back(content);
	}

	int left_cnt = 0, right_cnt = row;
	while (left_cnt <= right_cnt) {
		int mid = (left_cnt + right_cnt) / 2;

		bool is_duplicate = remove_row(mid, table_vec);
		if (is_duplicate) {
			right_cnt = mid - 1;
		} // 중복되는 문자열이 있으면, 자르는 범위가 줄어든다
    // 왜? 더 적게 자르면서 중복되는 경우가 있을 수 있음
		else
			left_cnt = mid + 1;
	} // 없으면 자르는 범위를 늘려서 중복되게 만들어야 한다.

	cout << left_cnt;
	return 0;
}
