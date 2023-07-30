#include <iostream>
#include <vector>
#include <set>
using namespace std;

int len = 0, max_size = 0;
int bottom_arr[101];
bool visit[101];
int result_arr[101];
void clear_visit() {
	for (int i = 0; i <= len; i++)
		visit[i] = false;
}

void dfs(int st, int curr) {
	// 핵심은 같은 집합을 만들 수 있다면, 사이클이 생긴다는 것!
	if (visit[curr]) { // 갔던 곳으로 돌아왔다.
		if (curr == st) { // 근데 시작점이랑 같네? 사이클!
			result_arr[max_size] = st;
			max_size += 1;
		}
	}
	else {// 아니면, 계속 진행
		visit[curr] = true;
		dfs(st, bottom_arr[curr]);
	}
	
}

int main() {
	cin >> len;
	for (int i = 1; i <= len; i++) {
		cin >> bottom_arr[i]; // 아래 집합 저장
	}

	for (int i = 1; i <= len; i++) {
		clear_visit();
		dfs(i, i);
	}

	// 사이클이 돌았다는 것은, 같은 집합이라는 것
	cout << max_size << '\n';
	for (int i = 0; i < max_size; i++)
		cout << result_arr[i] << "\n";

	return 0;
}

// 백트래킹 시도, 실패
