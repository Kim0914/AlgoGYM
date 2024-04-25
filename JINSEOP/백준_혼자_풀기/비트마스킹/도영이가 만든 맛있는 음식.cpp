#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 9999999999
typedef pair<long long, long long> pll;
typedef long long ll;

ll num = 0, answer = MAX;
vector<pll> food_vec;
int main() {
	cin >> num;

	ll sour = 0, bitter = 0;
	for (int i = 0; i < num; i++) {
		cin >> sour >> bitter;
		food_vec.push_back({ sour, bitter });
	}

	for (int i = 1; i < (1 << num); i++) {
	// 바깥의 i는 표현할 수 있는 모든 조합을 돈다
	// 단, 아무 음식도 안고르는 경우 제외
		ll sour_product = 1;
		ll bitter_sum = 0;
		
		for (int j = 0; j < num; j++) {
			if (i & (1 << j)) {
		// 음식이 총 num개 있을 때, 선택된 j에 대해 값을 계산한다.
				sour_product *= food_vec[j].first;
				bitter_sum += food_vec[j].second;
			}
		}

		answer = min(answer, abs(sour_product - bitter_sum));
	}

	cout << answer;
	return 0;
}
