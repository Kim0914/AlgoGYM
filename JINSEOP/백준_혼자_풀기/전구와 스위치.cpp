#include <iostream>
using namespace std;

string src = "", dest = "", temp = "";
int cnt = 0, res = 99999999;
void flip_bulb(int idx) { // 각 자리별 뒤집는 함수
	if (idx > 0) // 제일 첫 스위치의 경우
		temp[idx - 1] = (temp[idx - 1] == '0') ? '1' : '0';
	temp[idx] = (temp[idx] == '0') ? '1' : '0';
	if (idx < src.size() - 1)
		temp[idx + 1] = (temp[idx + 1] == '0') ? '1' : '0';
}

void match_bulb(int first_bulb) {
	temp = src; // 뒤집을 전구를 복사한다.
	cnt = 0; // 다음 경우를 위해 초기화

	if (first_bulb == 1) { // 첫 스위치를 누르는 경우
		temp[0] = (temp[0] == '0') ? '1' : '0';
		temp[1] = (temp[1] == '0') ? '1' : '0'; // 뒤집기
		cnt++;
	}

	for (int i = 1; i < dest.size(); i++) {
		if (temp[i - 1] != dest[i - 1]) { // 이전 전구만 확인하면 된다!
			flip_bulb(i); // i-1 번째 전구를 맞게 바꾸려면, i 스위치만 누르면 됨
			cnt++;
		}
	}

	if (temp == dest) // 같게 되는 두 경우 중 적게 누른 방식
		res = min(res, cnt);
}

int main() {
	int num = 0;
	cin >> num >> src >> dest;

	match_bulb(0); // 첫 스위치를 안누르는 경우
	match_bulb(1); // 누르는 경우
	
	if (res != 99999999)
		cout << res;
	else
		cout << -1;
	return 0;
}
