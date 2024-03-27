#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

int dx[4] = { 1, 0 , 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
bool finded = false;
string result = "";
string add_road(int dir, string road) {
	if (dir == 0)
		return road + "d";
	if (dir == 1)
		return road + "l";
	if (dir == 2)
		return road + 'r';
	if (dir == 3)
		return road + 'u';
}

void dfs(int n, int m, int curr_x, int curr_y, int r, int c, int k, int depth, string curr_road) {
	if (finded)
		return;

	if (depth == k && curr_x == r && curr_y == c) {
		result = curr_road;
		finded = true;
		return;
	}

	if (abs(curr_x - r) + abs(curr_y - c) > (k - depth))
		return;
	// 현재 위치 -> 목적지 거리가 남은 거리보다 길면 바로 제거
	// impossible이 되는 경우를 제거한다.

	for (int i = 0; i < 4; i++) {
		int nx = curr_x + dx[i];
		int ny = curr_y + dy[i];

		if (nx <= 0 || nx > n || ny <= 0 || ny > m)
			continue;

		dfs(n, m, nx, ny, r, c, k, depth + 1, add_road(i, curr_road));
	}
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
	string answer = "";
	// row, col, 출발 지점, 탈출 지점, 이동거리 제한

	int remain = abs(x - r) + abs(y - c);
	if ((k - remain) % 2 != 0 || remain > k)
		answer = "impossible";
	else {
		dfs(n, m, x, y, r, c, k, 0, "");
		answer = result;
	}

	return answer;
}
