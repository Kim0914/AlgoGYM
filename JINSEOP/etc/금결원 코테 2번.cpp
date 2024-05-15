#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int lazy_time = 0;
string target = "";
bool select[15];
set<string> validator;
void select_lazy(int depth, int limit, int idx, int size, string target) {
	if (depth == limit) {
		// 여기서 문자열 만들기
		string result = "";
		queue<int> lazy_q;

		for (int i = 0; i < target.size(); i++)
			if (select[i])
				lazy_q.push(i);
		// 지연이 발생한 위치를 저장한다.

		for (int i = 0; i < target.size(); i++) {
			if (!select[i])
				result += target[i];
			if (!lazy_q.empty() && ((i - lazy_q.front()) >= lazy_time)) {
				result += target[lazy_q.front()];
				lazy_q.pop();
			}
		}

		while (!lazy_q.empty()) {
			result += target[lazy_q.front()];
			lazy_q.pop();
		}

		validator.insert(result);
	}

	for (int i = idx; i < size; i++) {
		select[i] = true;
		select_lazy(depth + 1, limit, i + 1, size, target);
		select[i] = false;
	}
}

int main() {
	cin >> target >> lazy_time;
	
	for (int i = 1; i < target.size(); i++)
		select_lazy(0, i, 0, target.size(), target);

	for (auto i : validator)
		cout << i << " ";

	return 0;
}
