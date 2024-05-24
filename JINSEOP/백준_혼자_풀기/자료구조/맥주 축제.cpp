#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MAX 1000000000

ll day = 0, goal = 0, kinds = 0;
int main()
{
	cin >> day >> goal >> kinds;

	ll pref = 0, alcohol = 0;
	vector<pll> beer_vec;
	for (int i = 0; i < kinds; i++) {
	// 선호도, 도수 레벨
		cin >> pref >> alcohol;
		beer_vec.push_back({ alcohol, pref });
	}
	sort(beer_vec.begin(), beer_vec.end());

	priority_queue<ll, vector<ll>, greater<>> beer_q;
	ll curr_pref = 0;
	for (int i = 0; i < beer_vec.size(); i++) {
		beer_q.push(beer_vec[i].second);
		curr_pref += beer_vec[i].second;

		if (beer_q.size() > day) {
		// 이미 술이 축제 기간만큼 선택되었다면?
			curr_pref -= beer_q.top();
			beer_q.pop();
		} 

		if (beer_q.size() == day && curr_pref >= goal) {
			cout << beer_vec[i].first;
			return 0;
		} // 축제 기간만큼 먹었고, 선호도를 넘었다면?
		// 방금 집어 넣은 맥주의 도수가 정답!
	}

	cout << -1;
	return 0;
}
