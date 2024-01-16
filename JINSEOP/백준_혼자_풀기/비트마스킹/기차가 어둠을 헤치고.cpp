#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int num = 0, cmd_num = 0;
vector<int> train_station;
void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();

	cin >> num >> cmd_num;
	for (int i = 0; i <= num; i++) {
		train_station.push_back(0);
		// 비트 마스킹 기저 0000 0000 0000..
	}

	int cmd = 0, target = 0, seat = 0;
	for (int i = 0; i < cmd_num; i++) {
		cin >> cmd >> target;
		switch (cmd)
		{
		case 1:
			cin >> seat;
			train_station[target] |= (1 << seat);
			// 승객을 seat번 자리에 탑승 시키는 동작
			break;
		case 2:
			cin >> seat;
			train_station[target] &= ~(1 << seat);
			// 단순히 시프트 동작으로 구현이 가능하다.
			// 하차는 해당 비트에 0을 곱해주면 된다.
			break;
		case 3:
			train_station[target] = train_station[target] << 1;
			train_station[target] &= ((1 << 21) - 1);
			// 이 부분이 문제다.
			// 모든 자리를 시프트 연산을 통해 뒤로 밀 수 있다.
			// 20번 자리를 0으로 만들고, 20을 넘어가는 수도 모두 0으로 초기화
			// (1 << 21) - 1은 1111 1111 1111 1111 1111이다.
			break;
		case 4:
			train_station[target] = train_station[target] >> 1;
			train_station[target] &= ~1;
			// 모든 자리를 시프트 연산을 통해 앞으로 밀 수 있다.
			// ~1은 1의 자리를 제외, 모두 1이 된다.
			// 20을 넘어가는 수가 초기화가 필요 없는 이유는?
			// 오른쪽 시프트는 알아서 밖으로 빠지게 된다.
			break;
		}
	}

	vector<bool> report(1 << 21, false);
	int answer = 0;
	for (int i = 1; i <= num; i++) {
		if (report[train_station[i]] == false)
			answer++;
		report[train_station[i]] = true;
	}
	
	cout << answer;
	return 0;
}
