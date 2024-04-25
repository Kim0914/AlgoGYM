#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 9999999999
typedef long long ll;
typedef pair<long long, long long> pll;

ll num = 0, tc = 0, wph = 0, cost = 0;
vector<pll> water_door;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> wph >> cost;
		water_door.push_back({ cost, wph });
	}
	
	ll whole_water = 0, deadline = 0, cnt_for_print = 0;
	cin >> tc;
	cnt_for_print = tc;
	while (cnt_for_print--) {
		cin >> whole_water >> deadline;

		ll answer = MAX;
		// 바깥 i는 수문을 선택하는 모든 경우의 수를 고르기 위함
		for (ll i = 0; i < (1 << num); i++) {
			ll sum = 0;
			ll partial_water = 0;

		// 안쪽 j는 선택된 수문들에 대한 값을 더해주기 위함
		// 예를 들어 i가 13이라면 1101이므로, 1, 2, 4번째 수문의 값을 계산해줌
		// j를 0001 0010 0100 1000 을 돌게하면서, & 연산의 결과가 1인 경우에만 계산해주면 됨
			for (ll j = 0; j < num; j++) {
				if (i & (1 << j)) {
					sum += water_door[j].second;
					partial_water += water_door[j].first;
				}
			}

			if (sum * deadline >= whole_water && partial_water < answer)
				answer = partial_water;
		}

		if(answer == MAX)
			cout << "Case " << tc - cnt_for_print << ": " << "IMPOSSIBLE" << '\n';
		else
			cout << "Case " << tc - cnt_for_print << ": " << answer << '\n';
	}

	return 0;
}
