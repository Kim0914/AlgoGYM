#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MAX 1000000000

ll day = 0, goal = 0, kinds = 0;
bool calculate_drink(int liver_level, vector<pll> beer_vec) {
	vector<ll> pref_vec;
	for(int i = 0; i < beer_vec.size(); i++) {
		if (liver_level < beer_vec[i].first)
			break;
		// 마실 수 있는 맥주를 모두 찾아낸다
		pref_vec.push_back(beer_vec[i].second);
	}

	if (pref_vec.size() < day)
		return false;
  // 마실 수 있는 맥주가 축제 기간보다 적으면 안됨
  
	ll curr_pref = 0;
	sort(pref_vec.begin(), pref_vec.end(), greater<>());
	for (int i = 0; i < day; i++)
		curr_pref += pref_vec[i];
  // 마실 수 있는 맥주 중 선호도가 높은 것 부터 마시자
	if (curr_pref >= goal)
		return true;
	else
		return false;
}

int main()
{
	cin >> day >> goal >> kinds;

	ll pref = 0, alcohol = 0, max_liver = 0;
	vector<pll> beer_vec;
	for (int i = 0; i < kinds; i++) {
	// 선호도, 도수 레벨
		cin >> pref >> alcohol;
		beer_vec.push_back({ alcohol, pref });
		max_liver = max(max_liver, alcohol);
  // 처음부터 두 가지 조건으로 정렬을 해버리면 안된다.
  // 그럼 마실 수 있고 선호도가 더 큰 맥주를 못먹어버리게 됨
	}
	sort(beer_vec.begin(), beer_vec.end());
	
	ll left_v = 0, right_v = max_liver, answer = MAX;
	while (left_v <= right_v) {
		ll mid = (left_v + right_v) / 2;

		bool can_drink = calculate_drink(mid, beer_vec);
		if (can_drink) {
		// 마실 수 있는 간 레벨이면?
			right_v = mid - 1;
			answer = mid;
		// 줄여야지
		}
		else {
		// 마실 수 없는 간 레벨이면?
			left_v = mid + 1;
		// 늘려야지
		}
	}

	if (answer == MAX)
		cout << -1;
	else
		cout << answer;
	return 0;
}
