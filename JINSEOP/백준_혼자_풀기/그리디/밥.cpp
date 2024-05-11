#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> piii;

int num = 0, limit = 0;
vector<piii> food_vec;
bool cmp(piii a, piii b) {
	if (a.second == b.second)
		return a.first.first > b.first.first;
	return a.second > b.second;
}

int main() {
	cin >> num >> limit;

	int ochun = 0, chun = 0, answer = 0;
	for (int i = 0; i < num; i++) {
		cin >> ochun >> chun;
		food_vec.push_back({ { ochun, chun }, ochun - chun});
		answer += chun;
	} 
	sort(food_vec.begin(), food_vec.end(), cmp);
	// 5000원 - 1000원의 차이를 기준으로 내림차순
  // 5000원이 1000원보다 많이 맛있는 경우 뽑을 수 있도록

	limit -= (num * 1000); // 1000원 짜리로 모두 사보자
	for (int i = 0; i < food_vec.size(); i++) {
		if (limit <= 0)
			break; // 예산이 다 떨어지면 중단

		if ((food_vec[i].first.first > food_vec[i].first.second) && limit >= 4000) {
			answer += (food_vec[i].first.first - food_vec[i].first.second);
			limit -= 4000;
		} // 모두 산 1000원짜리 중에서, 5000원짜리가 만약 더 맛있다면?
	} // 5000원 짜리로 메뉴를 바꾸고, 예산에서 깎는다.
  // 차이가 가장 큰 순서로 5000원 짜리를 사기 때문에, 가성비가 좋은 5000원 짜리만 살 수 있음
	
	cout << answer;
	return 0;
}
