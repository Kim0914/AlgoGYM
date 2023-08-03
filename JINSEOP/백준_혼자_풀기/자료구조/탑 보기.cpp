#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int num = 0, tower_list[100001];
pair<int, int> tower_vec[100001];
stack<pair<int, int>> high_tower_left;
stack<pair<int, int>> high_tower_right;
void init_vec(){
	for (int i = 0; i < num; i++) {
		tower_vec[i] = { 0, 99999999 };
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> tower_list[i];

	init_vec();

	for (int i = 0; i <= num; i++) {
		while (!high_tower_left.empty() && (tower_list[i] >= high_tower_left.top().first))
			high_tower_left.pop();
		tower_vec[i].first += high_tower_left.size(); // 왼쪽에서 볼 수 있는 빌딩
		
		if (!high_tower_left.empty()) {
			if (abs(i - high_tower_left.top().second) < abs(tower_vec[i].second - i))
				tower_vec[i].second = high_tower_left.top().second;
		}

		high_tower_left.push({ tower_list[i], i + 1});
	}

	for (int i = num - 1; i >= 0; i--) {
		while (!high_tower_right.empty() && (tower_list[i] >= high_tower_right.top().first))
			high_tower_right.pop();
		tower_vec[i].first += high_tower_right.size(); // 오른쪽에서 볼 수 있는 빌딩

		if (!high_tower_right.empty()) {
			if (abs(i - high_tower_right.top().second) < abs(tower_vec[i].second - i))
				tower_vec[i].second = high_tower_right.top().second;
		}

		high_tower_right.push({ tower_list[i], i + 1 });
	}
		
	for (int i = 0; i < num; i++) {
		cout << tower_vec[i].first << " ";
		if (tower_vec[i].second != 99999999)
			cout << tower_vec[i].second << '\n';
		else
			cout << '\n';
	}

	return 0;
}
