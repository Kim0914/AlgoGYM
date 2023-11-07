#include <iostream>
#include <queue>
using namespace std;

int row = 0, apple_num = 0, dir_num = 0, apple_x = 0, apple_y = 0;
int dummy_map[101][101];
bool snake_map[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool check_dummy(int x, int y) {
	if ((x >= row || x < 0) || (y >= row || y < 0))
		return false;
	if (snake_map[x][y])
		return false;

	return true;
}

int main(){
	optimize();
	cin >> row >> apple_num;
	for (int i = 0; i < apple_num; i++) {
		cin >> apple_x >> apple_y;
		dummy_map[apple_x - 1][apple_y - 1] = 9;
		// 사과가 있는 위치를 9로 마킹
	}
	
	cin >> dir_num;
	int timer = 0, turn_time = 0, direction = 1;
	char turn_dir = 'X';
	// direction = 1은 기본적으로 오른쪽으로 보고있다는 의미이다.
	queue<pair<int, int>> snake;
	int curr_x = 0, curr_y = 0; // 시작점
	snake.push({ curr_x, curr_y });

	for (int i = 0; i < dir_num; i++) {
		cin >> turn_time >> turn_dir;

		while (timer < turn_time || i == dir_num - 1) {
			// 이 부분이 핵심이다.
			// 뱀의 방향 전환을 모두 받았어도, 게임은 계속 되어야 한다.
			timer++;
			int nx = curr_x + dx[direction];
			int ny = curr_y + dy[direction];
			// 방향대로 이동

			if (!check_dummy(nx, ny)) {
				cout << timer;
				// 뱀 몸을 만나거나, 벽을 만난 경우 (게임 오버)
				return 0;
			}

			if (dummy_map[nx][ny] == 9) {
				// 사과를 먹었다면?
				dummy_map[nx][ny] = 0; // 사과 일단 먹기
				snake.push({ nx, ny });
				snake_map[nx][ny] = true;
				// 꼬리는 그대로 두고 몸의 길이가 1 늘어남
			}
			else {
				// 사과가 없는 칸이라면?
				snake.push({ nx, ny });
				snake_map[nx][ny] = true;
				// 머리를 옮긴 뒤 꼬리 삭제
				snake_map[snake.front().first][snake.front().second] = false;
				snake.pop();
			}

			curr_x = nx; curr_y = ny; // 현재 위치 바꿔줘야 함

			if (timer == turn_time) {
				// 몸을 돌릴 시간이라면?
				if (turn_dir == 'D')
					direction = (direction + 1) % 4;
				// 오른쪽으로 도는 경우는, 그냥 1을 더해주기만 하면 된다.
				else
					direction = (direction + 3) % 4;
				// 반대로 도는 경우는? 3씩 더해주면 한 칸씩 뒤로 밀린다.
			}
		}
	}
}
