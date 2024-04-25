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
		for (ll i = 0; i < (1 << num); i++) {
			ll sum = 0;
			ll partial_water = 0;

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
