#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll num = 0, popul = 0;
vector<ll> immig_vec;
bool calculate_cost(ll cost) {
	ll goal = 0;

	for (int i = 0; i < immig_vec.size(); i++) {
		goal += (cost / immig_vec[i]);
		// 총 시간 동안 해당 검색대에서 몇명을 검사할 수 있는지?
		if (goal >= popul)
			return true; // 모두 검사할 수 있으면 true 반환
	}

	return false; // 안되면 시간을 늘려야 함
}

int main()
{
	cin >> num >> popul;

	ll cost = 0, answer = 0;
	for (int i = 0; i < num; i++) {
		cin >> cost;
		immig_vec.push_back(cost);
	}
	sort(immig_vec.begin(), immig_vec.end());
	// 빠른 검색대부터 차례대로 계산하기 위해

	ll left_v = 1, right_v = immig_vec[immig_vec.size() - 1] * popul;
	while (left_v <= right_v) {
		ll mid = (left_v + right_v) / 2;
		// 걸리는 시간을 계속 줄여나가야 함

		bool can_immig = calculate_cost(mid);
		if (can_immig)
			right_v = mid - 1;
		else
			left_v = mid + 1;
	}
	
	cout << left_v;
	return 0;
}
