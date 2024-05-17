#include <iostream>
#include <vector>
#include <set>
using namespace std;

int num = 0;
vector<int> seq;
int visit[26]; // 계수 정렬을 위한 배열
void clear_visit() {
	for (int i = 0; i < 26; i++)
		visit[i] = 0;
}

void backtrack(int depth, string target) {
	if (depth == target.size()) {
		cout << target << '\n';
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (visit[i] > 0) {
			visit[i]--;
			target[depth] = i + 'a';
			backtrack(depth + 1, target);
			visit[i]++;
		} 
		// 앞에서부터 훑으며 사용하지 않은 알파벳으로 바꿈
	}
}

int main() {
	cin >> num;

	string target = "";
	for (int i = 0; i < num; i++) {
		cin >> target;

		for (int j = 0; j < target.size(); j++)
			visit[target[j] - 'a']++;

		backtrack(0, target);
		clear_visit();
	}

	return 0;
}
