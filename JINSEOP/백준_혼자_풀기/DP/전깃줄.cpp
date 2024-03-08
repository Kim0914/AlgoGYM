#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pii pair<int, int>

int num = 0, from = 0, to = 0 ;
int dp[101];
vector<pii> wire_vec;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> from >> to;
		wire_vec.push_back({ from, to });
	} 
	sort(wire_vec.begin(), wire_vec.end());
	// 연결되는 앞부분 기준으로 정렬했을 때
	// 전선의 뒷 쪽이 모두 오름차순이면 연결 가능함.

	int answer = 0;
	for (int i = 0; i < num; i++){
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (wire_vec[i].second > wire_vec[j].second)
				dp[i] = max( dp[i], dp[j] + 1 );
		}

		answer = max(answer, dp[i]);
	}

	cout << num - answer;
	return 0;
}
