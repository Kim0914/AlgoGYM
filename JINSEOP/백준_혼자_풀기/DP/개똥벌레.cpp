#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int cave_length = 0, cave_height = 0;
int stalactite[500001], stalagmite[500001];
int main() {
	cin >> cave_length >> cave_height;

	int height = 0;
	for (int i = 0; i < cave_length; i++) {
		cin >> height;

		if (i % 2 == 0)
			stalagmite[height]++;
		else
			stalactite[cave_height - height + 1]++;
		// 어느 높이에 장애물이 위치하는 지 기록한다.
	}

	for (int i = 1; i <= cave_height; i++) {
		stalactite[i] += stalactite[i - 1];
		stalagmite[cave_height - i] += stalagmite[cave_height - i + 1];
	} // 여기서 각 장애물을 누적합 해준다.
	// 이 때, 종유석은 아래에서 부터 누적합을 해준다.
	// 석순은 위에서 부터 누적합을 해주어야 한다.
	// 왜? 각자 위로 갈수록, 아래로 갈수록 부딪힐 장애물의 수가 많아지기 때문이다.

	ll answer = 999999999;
	int cnt = 0;
	for (int i = 1; i <= cave_height; i++) {
		ll curr_height = stalactite[i] + stalagmite[i];
  // 누적합을 이용할 수 있는 이유는 무엇일까?
  // 현재 높이보다 높은 위치에 있는 장애물은 무조건 모두 부딪히게 된다.
  // 따라서 현재 높이에 대해서 부딪힐 수 있는 모든 장애물의 수를 구한 것이 된다.
    
		if (curr_height < answer) {
			cnt = 1;
			answer = curr_height;
			// 더 작게 부딪힐 수 있으면 갱신
		}
		else if (curr_height == answer)
			cnt++;
	}

	cout << answer << " " << cnt;
	return 0;
}
