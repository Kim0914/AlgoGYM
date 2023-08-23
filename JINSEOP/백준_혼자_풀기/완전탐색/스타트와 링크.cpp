#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, synergies[21][21], answer = 99999999;
bool teammates[21]; // 스타트 팀은 true, 링크 팀은 false 
void backtrack(int depth, int idx) {
	if (depth == num / 2) { // 절반을 팀을 정하면, 나머지는 자동
		int team_s = 0, team_l = 0;

		for (int i = 1; i <= num; i++) { // 시너지 배열을 돌며 팀 실력차를 확인한다.
			for (int j = 1; j <= num; j++) {
				if (teammates[i] == true && teammates[j] == true) // 스타트 팀일 경우
					team_s += synergies[i][j];
				if (teammates[i] == false && teammates[j] == false) // 링크 팀일 경우
					team_l += synergies[i][j];
			}
		}

		answer = min(abs(team_s - team_l), answer); // 두 팀의 실력 차가 최소가 되어야 함
		return;
	}

	for (int i = idx; i < num; i++) {
		teammates[i] = true; // 각각 될 수 있는 팀의 경우의 수를 모두 고른다.
		backtrack(depth + 1, i + 1);
		teammates[i] = false;
	}
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			cin >> synergies[i][j];

	backtrack(0, 1); // 0명부터 1번사원부터 시작
	cout << answer;

	return 0;
}
