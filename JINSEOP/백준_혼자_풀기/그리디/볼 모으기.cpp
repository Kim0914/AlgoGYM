#include <iostream>
using namespace std;

string balls = "";
int cnt = 0, min_cnt = 99999999;

void move_balls(char target) {
	bool shouldMove = false;

	for (int i = 0; i < balls.size(); i++) { // 왼쪽으로 모으는 경우
		if ((balls[i] != target) && !shouldMove) // 아직 반대 색깔이 안나옴
			shouldMove = true;
		if ((balls[i] == target) && shouldMove) // 반대 색깔이 등장하면 옮겨야 함
			cnt++;
	}

	min_cnt = min(min_cnt, cnt);
	cnt = 0;
	shouldMove = false;
	for (int i = balls.size() - 1; i >= 0; i--) { // 오른쪽으로 모으는 경우
		if ((balls[i] != target) && !shouldMove) // 아직 반대 색깔이 안나옴
			shouldMove = true;
		if ((balls[i] == target) && shouldMove) // 반대 색깔이 등장하면 옮겨야 함
			cnt++;
	}
	min_cnt = min(min_cnt, cnt);

}

int main() {
	int num = 0;
	cin >> num >> balls;

	move_balls('R'); // 빨강을 옮기는 경우
	move_balls('B'); // 파랑을 옮기는 경우

	cout << min_cnt;
	return 0;
}
