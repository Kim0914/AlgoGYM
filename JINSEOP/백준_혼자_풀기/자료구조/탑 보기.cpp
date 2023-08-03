#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 99999999

int num = 0, tower_list[100001];
vector<pair<int, int>> tower_vec;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> tower_list[i];

	for (int i = 0; i < num; i++) {
		stack<int> high_tower_left;
		stack<int> high_tower_right;
		pair<int, int> tower_unit;

		int first_tower_left = MAX, first_tower_right = MAX;

		for (int j = i - 1; j >= 0; j--) { // 현재 탑 기준 왼쪽
			if (high_tower_left.empty()) {
				if (tower_list[i] < tower_list[j]) {
					high_tower_left.push(tower_list[j]); // 처음 만나는 높은 탑 삽입
					first_tower_left = j + 1;
				}
			}
			if (!high_tower_left.empty() && (tower_list[j] > high_tower_left.top()))
				high_tower_left.push(tower_list[j]); // 이후 만나는 더 높은 탑 삽입
		}
		for (int j = i + 1; j < num; j++) { // 현재 탑 기준 오른쪽
			if (high_tower_right.empty()) {
				if (tower_list[i] < tower_list[j]) {
					high_tower_right.push(tower_list[j]); // 처음 만나는 높은 탑 삽입
					first_tower_right = j + 1;
				}
			}
			if (!high_tower_right.empty() && (tower_list[j] > high_tower_right.top()))
				high_tower_right.push(tower_list[j]); // 이후 만나는 더 높은 탑 삽입
		}

		tower_unit.first = high_tower_left.size() + high_tower_right.size();
		tower_unit.second = min(first_tower_left, first_tower_right);

		tower_vec.push_back(tower_unit);
	}

	for (auto i : tower_vec) {
		cout << i.first << " "; 
		if (i.second != MAX)
			cout << i.second << '\n';
		else
			cout << '\n';
	}

	return 0;
}
