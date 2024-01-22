#include <iostream>
#include <queue>
using namespace std;

int num = 0, height = 0;
priority_queue<int> m_men, m_women;
priority_queue<int, vector<int>, greater<>> men, women;
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> height;
		if (height < 0)
			m_men.push(height);
		else
			men.push(height);
	}
	for (int i = 0; i < num; i++) {
		cin >> height;
		if (height < 0)
			m_women.push(height);
		else
			women.push(height);
	}
	// 음수는 키가 작은 사람을 원하는 사람
	// 양수는 키가 큰 사람을 원하는 사람
	
	// 쌍을 이루려면 부호가 다른 사람끼리 이뤄야 한다.
	// 또한, 둘을 계산했을 때 음수가 나와야 쌍을 이룰 수 있다.
	// 그럼 최대 쌍을 만들 수 있는 조건은?

	int answer = 0;
	while (!men.empty() && !m_women.empty()) {
		int curr_man = men.top();
		int curr_woman = m_women.top();
		m_women.pop();
		
		if (curr_man + curr_woman < 0) {
			answer++;
			men.pop();
		}
	}

	while (!m_men.empty() && !women.empty()) {
		int curr_man = m_men.top();
		int curr_woman = women.top();
		m_men.pop();

		if (curr_man + curr_woman < 0) {
			answer++;
			women.pop();
		}
	}

	cout << answer;
	return 0;
}
