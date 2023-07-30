#include <iostream>
#include <string>
using namespace std;

long long min_cnt = 99999999;
bool isPossible = false;
long long attach_one(long long curr_num) {
	string stringify_num = to_string(curr_num);
	stringify_num += "1";
	
	return stoll(stringify_num);
}

void dfs(long long curr_num, long long goal, int cnt) {
	if (curr_num > goal)
		return;

	if (curr_num == goal) {
		isPossible = true;
		if (min_cnt > cnt)
			min_cnt = cnt;
	}

	dfs(curr_num * 2, goal, cnt+1);
	dfs(attach_one(curr_num), goal, cnt+1);
}

int main() {
	int start = 0, goal = 0;
	cin >> start >> goal;

	dfs(start, goal, 1);

	if (!isPossible)
		cout << -1;
	else
		cout << min_cnt << endl;

	return 0;
}
