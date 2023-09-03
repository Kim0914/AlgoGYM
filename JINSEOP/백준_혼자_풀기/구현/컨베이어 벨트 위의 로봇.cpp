#include <iostream>
#include <vector>
using namespace std;

int cell = 0, limit = 0, zero_cnt = 0, answer_cnt = 1, up_ptr = 0, down_ptr = 0, belt[204];
bool robot_pos[204];
void check_durability(int idx) {
	if (belt[idx] == 0)
		zero_cnt++;
}

void put_down_robot() {
	if (robot_pos[down_ptr])
		robot_pos[down_ptr] = false; // 내리는 위치에 로봇이 있다면 내려줌
}

void rotate_belt() {
	// 일일이 돌리면 시간초과 발생
	// 따라서 올리고 내리는 위치만 변경한다.
	if (up_ptr == 0) // 올리는 위치가 0이되면?
		up_ptr = (cell * 2) - 1; // 마지막 칸으로 이동
	else
		up_ptr--; // 아니면 한 칸씩 뒤로 밀면 됨

	if (down_ptr == 0) // 위와 동일
		down_ptr = (cell * 2) - 1;
	else
		down_ptr--;

	put_down_robot(); // 내리는 위치에 로봇이 위치하면 즉시 내림
	// 올리고 내리는 위치만 옮겨도, 로봇은 자동으로 이동하는 효과가 난다.
}

void move_robot() {
	int belt_cnt = 0;
	int idx = down_ptr; // 내리는 위치부터 훑어야 함 (현재 위치)

	while (belt_cnt < cell - 1) { // 벨트 절반 길이만큼 돌림 (올리는 위치 -> 내리는 위치)
		int next_pos = idx; // 로봇이 가야할 다음 칸
		if (idx == 0) // idx는 현재 위치를 계속 갱신한다.
			idx = (cell * 2) - 1; // 줄이다 0이 되었다면, 마지막 칸으로 돌림
		else
			idx--; // 뒤에서부터 훑으므로 한 칸씩 줄임

		if (robot_pos[idx]) { // 현재 위치에 로봇이 있을 때
			if (!robot_pos[next_pos] && belt[next_pos] > 0) { // 앞에 로봇이 없고 내구도가 남았으면?
				belt[next_pos] -= 1; // 이동하는 즉시 내구도를 1 깎는다.
				check_durability(next_pos); // 내구도가 0이 되면 종료 카운트 증가

				robot_pos[next_pos] = true; // 로봇을 다음 칸으로 이동시킨다.
				robot_pos[idx] = false; // 있던 칸은 로봇 제거
			}
		}
		// 로봇이 있거나 내구도가 0이라면 이동하지 않는다.
		// 뒤부터 탐색하는 이유는, 벨트에 먼저 올라간 로봇부터 움직이기 위해서.
		belt_cnt++;
	}

	put_down_robot(); // 내리는 위치에 로봇이 있으면 내림
}

void put_robot() {
	// 올리는 위치에 내구도가 남아있다면
	if (belt[up_ptr] > 0) {
		robot_pos[up_ptr] = true; // 로봇 올림
		belt[up_ptr] -= 1;
		check_durability(up_ptr); // 내구도가 다 닳았으면 종료 카운트 증가
	}
}

int main() {
	cin >> cell >> limit;
	for (int i = 0; i < cell * 2; i++)
		cin >> belt[i];

	// 올리는 위치는 idx = 0
	up_ptr = 0;
	// 내리는 위치는 idx = cell - 1
	down_ptr = cell - 1;
	// 전체 길이는 cell * 2

	while (true) { 
		// 내구도가 0인 칸이 limit 이상이면 종료
		// 1. 벨트를 회전 시킨다.
		rotate_belt();
		// 2. 로봇이 있으면 한 칸 전진시킨다.
		move_robot();
		// 3. 올리는 위치의 내구도가 0이 아니면 로봇을 올린다.
		put_robot();

		if (zero_cnt >= limit)
			break;
		
		answer_cnt++; // 정답 횟수
	}

	cout << answer_cnt;
	return 0;
}
