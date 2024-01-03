#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int row = 0, col = 0, target_row = 0;
string target_str = "";
int origin[26], target[26];
vector<string> ladders;
void init_participant() {
	for (int i = 0; i < col; i++) {
		origin[i] = i;
		target[i] = target_str[i] - 'A';
	}
}

void send_down_origin() {
	for (int i = 0; i < target_row; i++) {
		for (int j = 0; j < col - 1; j++) {
			if (ladders[i][j] == '-')
				swap(origin[j], origin[j + 1]);
		}
	}
}

void send_up_target() {
	for (int i = row - 1; i > target_row; i--) {
		for (int j = 0; j < col - 1; j++) {
			if (ladders[i][j] == '-')
				swap(target[j], target[j + 1]);
		}
	}
}

string compare_between() {
	string answer = "";

	for (int i = 0; i < col - 1; i++) {
		if (origin[i] == target[i])
			answer += '*';
		// origin과 target이 동일하다면 그냥 내려보내도 됨
		else if (origin[i] == target[i + 1] && origin[i + 1] == target[i]) {
			swap(origin[i], origin[i + 1]);
			answer += '-';
		// origin과 target이 서로 교차된 알파벳이라면
		// 둘의 자리를 바꾸면 만들 수 있는 문자열이다.
		}
		else {
			answer = "";
			for (int j = 0; j < col - 1; j++)
				answer += 'x';
			return answer;
			// 두 경우에 모두 걸리지 않으면 만들 수 없는 문자열.
			// 바로 결과를 반환해도 된다.
		}
	}

	return answer;
}

int main() {
	cin >> col >> row;
	cin >> target_str;
	init_participant();

	for (int i = 0; i < row; i++) {
		string horizontal = "";
		cin >> horizontal;

		if (horizontal[0] == '?')
			target_row = i;
		// ???로 만들어진 행을 저장, ladder[row]로 접근하도록
		ladders.push_back(horizontal);
	}

	send_down_origin();
	send_up_target();
	// 위에서 아래로, 아래에서 위로 사다리 태우기

	cout << compare_between();
	return 0;
}
