#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> tower_vec;
stack<pair<int, int>> height_stack;

int main() {
	int num = 0, tower = 0, max_t = 0, max_idx = 0;

	cin >> num;
	vector<int> rx_map(num, 0);

	for (int i = 0; i < num; i++) {
		cin >> tower;
		tower_vec.push_back(tower);
	}

	rx_map[0] = 0;
	height_stack.push({tower_vec[0], 0}); // 초기 작업

	for (int i = 1; i < num; i++) {
		while (!height_stack.empty() && (height_stack.top().first < tower_vec[i]))
			height_stack.pop();
		// 현재 탑보다 큰 높이가 나올 때 까지 pop

		if (height_stack.empty()) // 없으면 0
			rx_map[i] = 0;
		else
			rx_map[i] = height_stack.top().second + 1; // 있으면 해당 위치 저장

		height_stack.push({ tower_vec[i], i }); // 자신의 높이 스택에 저장
	}

	for (int i : rx_map)
		cout << i << " ";
}
