#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
	int max_health = health;
	
	int prev_time = 0; // 이전 시간
	for (int i = 0; i < attacks.size(); i++) {
		int curr_time = attacks[i][0]; // 공격 받는 시간
		int diff = curr_time - prev_time - 1;
		// 이전 공격받은 시간 부터 지금까지 회복 가능

		health += ((diff / bandage[0]) * (bandage[2] + bandage[1]));
			// 연속 성공한 만큼 더해준다.
		health += ((diff - (diff / bandage[0])) * bandage[1]);
			// 연속 성공한 횟수만큼 빼고 더해주자.

		if (health >= max_health)
			health = max_health;

		health -= attacks[i][1]; // 데미지만큼 체력 감소
		prev_time = curr_time; // 현재 시간으로 이전 시간 갱신
		if (health <= 0)
			return -1;
	}

	
	return health;
}
