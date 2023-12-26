#include <iostream>
#include <vector>
using namespace std;

int num = 0, use_num = 0, use_wardrobe = 0, answer = 0;
pair<int, int> opened_wardrobe;
vector<int> to_use;
int main() {
	cin >> num;
	cin >> opened_wardrobe.first >> opened_wardrobe.second;
	cin >> use_num;
	for (int i = 0; i < use_num; i++) {
		cin >> use_wardrobe;
		
		if (abs(opened_wardrobe.first - use_wardrobe) < abs(opened_wardrobe.second - use_wardrobe)) {
			answer += abs(opened_wardrobe.first - use_wardrobe);
			opened_wardrobe.first = use_wardrobe;
		}
		else if (abs(opened_wardrobe.first - use_wardrobe) > abs(opened_wardrobe.second - use_wardrobe)) {
			answer += abs(opened_wardrobe.second - use_wardrobe);
			opened_wardrobe.second = use_wardrobe;
		}
	}

	cout << answer;
	return 0;
}

// 그리디로는 해결할 수 없는 문제다.
// Cache hit / miss를 생각해보면 됨
// 아래는 정석 풀이

#include <iostream>
#include <cstring>
using namespace std;

int num = 0, use_num = 0, use_wardrobe = 0, answer = 0;
pair<int, int> opened_wardrobe;
int wardrobe[21], dp[21][21][21];
int open_wardrobe(int open_1, int open_2, int depth) {
	if (depth == use_num + 1)
		return 0;

	int& ret = dp[open_1][open_2][depth];
	if (ret != -1)
		return ret;

	ret = 0;
	ret = min(abs(wardrobe[depth] - open_1) + open_wardrobe(wardrobe[depth], open_2, depth + 1), abs(wardrobe[depth] - open_2) + open_wardrobe(open_1, wardrobe[depth], depth + 1));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> num;
	cin >> opened_wardrobe.first >> opened_wardrobe.second;
	cin >> use_num;
	for (int i = 1; i <= use_num; i++)
		cin >> wardrobe[i];

	cout << open_wardrobe(opened_wardrobe.first, opened_wardrobe.second, 1);
	return 0;
}
