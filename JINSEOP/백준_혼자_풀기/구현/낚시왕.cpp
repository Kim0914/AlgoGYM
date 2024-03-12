#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MACRO(i) cout << shark_info[i].x << " " << shark_info[i].y << '\n'

struct shark {
	int x;
	int y;
	int velo;
	int dir;
	int size;
};

bool cmp(shark a, shark b) {
	return a.size > b.size;
}

int row = 0, col = 0, shark_num = 0;
int shark_pos[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, 1, -1 };
bool is_catch[10001];
vector<shark> shark_info;
void optimize() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
}

int main() {
	optimize();

	cin >> row >> col >> shark_num;

	int x = 0, y = 0, velo = 0, dir = 0, size = 0;
	for (int i = 0; i < shark_num; i++) {
		cin >> x >> y >> velo >> dir >> size;
		shark_info.push_back({ x, y, velo, dir, size });
		// 구조체 기본 생성자
		shark_pos[x][y] = size; // 상어 위치 표시
		is_catch[size] = false; // 상어 잡아 먹혔는지 표시
	}
	sort(shark_info.begin(), shark_info.end(), cmp);
	// 겹치는 상어를 먹기 위해 크기 순 정렬

	// 낚시꾼은 최대 col 만큼 움직인다.
	int limit = col, answer = 0;
	while (limit--) {
		for (int i = 1; i <= row; i++) {
			if (shark_pos[i][col - limit] != 0) {
				answer += shark_pos[i][col - limit];
				is_catch[shark_pos[i][col - limit]] = true;
				shark_pos[i][col - limit] = 0;
				break;
			}
			// 육지에서 가장 가까운 상어 제거 => 낚시꾼
		}

		for (int i = 0; i < shark_info.size(); i++) {
			if (is_catch[shark_info[i].size])
				continue; // 이미 잡힌 상어는 탐색 X

			int curr_dir = shark_info[i].dir;
			int curr_velo = shark_info[i].velo;
			int curr_size = shark_info[i].size;

			// 상어 원래 위치에서 제거
			if(shark_pos[shark_info[i].x][shark_info[i].y] == curr_size)
				shark_pos[shark_info[i].x][shark_info[i].y] = 0;
			// 먼저 도착한 상어를 지우면 안되기에, 사이즈가 같은 경우 제거 후 출발

			// 상어 옮기기
			for (int j = 0; j < curr_velo; j++) {
				switch (curr_dir)
				{
				case 1: // 상
					shark_info[i].x = shark_info[i].x + dx[curr_dir - 1];
					if (shark_info[i].x < 1) {
						curr_dir = 2;
						shark_info[i].x = 2;
					}
					break;
				case 2: // 하
					shark_info[i].x = shark_info[i].x + dx[curr_dir - 1];
					if (shark_info[i].x > row) {
						curr_dir = 1;
						shark_info[i].x = row - 1;
					}
					break;
				case 3: // 우
					shark_info[i].y = shark_info[i].y + dy[curr_dir - 1];
					if (shark_info[i].y > col) {
						curr_dir = 4;
						shark_info[i].y = col - 1;
					}
					break;
				case 4: // 좌
					shark_info[i].y = shark_info[i].y + dy[curr_dir - 1];
					if (shark_info[i].y < 1) {
						curr_dir = 3;
						shark_info[i].y = 2;
					}
					break;
				}
			}

			if (shark_pos[shark_info[i].x][shark_info[i].y] > curr_size) {
				// 도착 위치에 이미 더 큰 상어가 있다면?
				// 해당 상어는 잡아 먹힌다.
				is_catch[curr_size] = true;
				continue;
			}

			// 최종적으로 바뀐 상어 위치 표시, 방향 저장
			shark_info[i].dir = curr_dir;
			shark_pos[shark_info[i].x][shark_info[i].y] = curr_size;
		}
	}

	cout << answer;
	return 0;
}
