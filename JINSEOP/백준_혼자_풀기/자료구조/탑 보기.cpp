#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int num = 0, tower_list[100001];
pair<int, int> tower_vec[100001];
stack<pair<int, int>> high_tower_left;
stack<pair<int, int>> high_tower_right;

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tower_list[i];
		tower_vec[i] = { 0, 999999999 };
	}

	for (int i = 0; i < num; i++) {
		while (!high_tower_left.empty() && (tower_list[i] >= high_tower_left.top().first))
			high_tower_left.pop();
		tower_vec[i].first += high_tower_left.size(); // 왼쪽에서 볼 수 있는 빌딩
		
		if (tower_vec[i].first > 0) // 내가 볼 수 있는 빌딩이 있으면 기록
			tower_vec[i].second = high_tower_left.top().second;

		high_tower_left.push({ tower_list[i], i});
	}

	for (int i = num - 1; i >= 0; i--) {
		while (!high_tower_right.empty() && (tower_list[i] >= high_tower_right.top().first))
			high_tower_right.pop();
		tower_vec[i].first += high_tower_right.size(); // 오른쪽에서 볼 수 있는 빌딩

		if (!high_tower_right.empty() && (abs(high_tower_right.top().second - i) < abs(i - tower_vec[i].second))) {
			tower_vec[i].second = high_tower_right.top().second;
		}
		// 오른쪽에서 보는 거리가 더 가까우면 교체

		high_tower_right.push({ tower_list[i], i});
	}
		
	for (int i = 0; i < num; i++) {
		cout << tower_vec[i].first << " ";
		if (tower_vec[i].second != 999999999)
			cout << tower_vec[i].second + 1 << '\n';
		else
			cout << '\n';
	}

	return 0;
}
