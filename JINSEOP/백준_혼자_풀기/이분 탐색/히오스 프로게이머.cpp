#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LL_MAX 9999999999999
typedef long long ll;

ll num = 0, limit = 0;
vector<ll> char_vec;
bool validate_level(ll target_level) {
	ll diff = 0;

	for (int i = 0; i < char_vec.size(); i++) {
		if (target_level > char_vec[i])
			diff += (target_level - char_vec[i]);

		if (diff > limit)
			return false;
	}

	return true;
}

int main() {
	cin >> num >> limit;

	ll level = 0;
	for (int i = 0; i < num; i++) {
		cin >> level;
		char_vec.push_back(level);
	}

	ll left_v = 1, right_v = LL_MAX, answer = 0;
	// max_element는 O(N), 최대 값을 우선 오른쪽 값으로 지정
	while (left_v <= right_v) {
		ll mid = (left_v + right_v) / 2;
		
		if (!validate_level(mid))
			right_v = mid - 1;
		else {
			left_v = mid + 1;
			answer = mid;
		}
	}

	cout << answer;
	return 0;
}
