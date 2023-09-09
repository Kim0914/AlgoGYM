#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, answer = 0, crane = 0, contain = 0;
vector<int> cranes, container;
bool pos[10000];
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> crane;
		cranes.push_back(crane);
	}
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> contain;
		container.push_back(contain);
	}

	sort(cranes.begin(), cranes.end(), greater<>()); // 큰 순 정렬
	sort(container.begin(), container.end(), greater<>());

	if (cranes[0] < container[0])
		answer = -1;
	else {
		while (!container.empty()) {
			answer++;
			for (int i = 0; i < cranes.size(); i++) {
				for (int j = 0; j < container.size(); j++) {
					if (container[j] <= cranes[i]) {
						container.erase(container.begin() + j); // 컨테이너에서 큰 박스부터 순서대로 처리
						break;
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}
