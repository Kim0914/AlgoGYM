#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 9999999999

int num = 0, answer = MAX;
int synergy_info[20][20];
int calculate_synergy(vector<int> target_team) {
	int synergy = 0;

	for (int i = 0; i < target_team.size(); i++)
		for (int j = 0; j < target_team.size(); j++)
			synergy += synergy_info[target_team[i]][target_team[j]];

	return synergy;
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> synergy_info[i][j];

	for (int i = 1; i < (1 << num) - 1; i++) {
		// 0000과 1111은 들어가면 안됨.
		// 최소한 한 명은 팀에 구성될 것!
		vector<int> link_team;
		vector<int> start_team;

		for (int j = 0; j < num; j++) {
			if (i & (1 << j))
				link_team.push_back(j);
			else
				start_team.push_back(j);
		}

		answer = min(answer, abs(calculate_synergy(link_team) - calculate_synergy(start_team)));
	}

	cout << answer;
	return 0;
}
