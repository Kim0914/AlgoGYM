#include <iostream>
#include <vector>
using namespace std;

int num = 0, answer = 0;
bool egg_state[8];
void backtrack(int curr_egg, vector<pair<int, int>> eggs) {
	if (curr_egg >= eggs.size()) {
		// 깨진 계란 계산
		int break_cnt = 0;

		for (int i = 0; i < eggs.size(); i++)
			if (egg_state[i])
				break_cnt++;

		answer = max(break_cnt, answer); // 최대로 깨지는 경우
		return;
	}

	if (egg_state[curr_egg])
		backtrack(curr_egg + 1, eggs);
	// 이미 깨진 계란의 경우는 바로 스킵

	bool is_hit = false;
	for (int i = 0; i < eggs.size(); i++) {
		if (egg_state[curr_egg])
			break;
		if (i == curr_egg)
			continue;

		if (!egg_state[i]) { // 아직 안깨진 계란이면?
			is_hit = true;

			eggs[i].first -= eggs[curr_egg].second;
			eggs[curr_egg].first -= eggs[i].second; // 서로 내구도 감소

			if (eggs[i].first <= 0)
				egg_state[i] = true; // 깨짐
			if (eggs[curr_egg].first <= 0)
				egg_state[curr_egg] = true; // 깨짐

			backtrack(curr_egg + 1, eggs);

			eggs[i].first += eggs[curr_egg].second;
			eggs[curr_egg].first += eggs[i].second; // 내구도 복구
			if(egg_state[i])
				egg_state[i] = false; // 복구
			if(egg_state[curr_egg])
				egg_state[curr_egg] = false; // 복구
		}
	}

	if(!is_hit)
		backtrack(curr_egg + 1, eggs);
	// 계란 아무것도 안깨고 나온 경우에도 다음으로 이동해야 함
}

int main() {
	cin >> num;

	vector<pair<int, int>> eggs;
	int durability = 0, weight = 0;
	for (int i = 0; i < num; i++) {
		cin >> durability >> weight;
		eggs.push_back({ durability, weight });
	}

	// 어차피 시작은 가장 왼쪽부터 해야함
	backtrack(0, eggs);
	cout << answer;
	return 0;
}
