#include <iostream>
using namespace std;
#define ll long long

int room_num = 0;
ll init_atk = 0, answer = 0;
pair<int, pair<ll, ll>> dungeon[123456];
int main() {
	cin >> room_num >> init_atk;
	for (int i = 0; i < room_num; i++)
		cin >> dungeon[i].first >> dungeon[i].second.first >> dungeon[i].second.second;
		// < 방 정보, < 공격력, 생명력 >>

	ll front = 1, rear = 1e18;
	while (front <= rear) {
		ll mid = (front + rear) / 2;
		ll curr_health = mid;
		ll curr_attack = init_atk;
		bool is_dead = false;

		for (int i = 0; i < room_num; i++) {
			if (dungeon[i].first == 1) { // 괴물 방
				ll hit_count = ((dungeon[i].second.second - 1) / curr_attack);
				// 괴물의 체력을 현재 공격력으로 나누면? 때릴 수 있는 횟수
				curr_health -= (hit_count * dungeon[i].second.first);
				// 나도 때린 만큼 괴물의 공격력 대로 맞는다.

				if (curr_health <= 0) {
					is_dead = true;
					break; // 체력이 0이하로 내려가면 바로 사망
				}
			}
			else { // 포션 방
				curr_health = min(curr_health + dungeon[i].second.second, mid); // 체력 회복
				curr_attack += dungeon[i].second.first; // 공격력 증가
			}
		}

		if (is_dead)
			front = mid + 1;
		else {
			answer = mid;
			rear = mid - 1;
		}
	}

	cout << answer;

	return 0;
}
