#include <iostream>
#include <vector>
using namespace std;

int num = 0, student_num = 0, sex = 0, pos = 0;
bool switches[101];
pair<int, int> students[101];
void boy_behave(int target) {
	for (int i = target; i <= num; i += target)
		switches[i] = !switches[i];
	// 배수인 스위치 상태 뒤집기
}

void girl_behave(int target) {
	switches[target] = !switches[target];
	int iter = 1;

	while (true) {
		if ((target + iter) > num || (target - iter) < 1)
			break;
		if (switches[target - iter] != switches[target + iter])
			break;

		switches[target - iter] = !switches[target - iter];
		switches[target + iter] = !switches[target + iter];
		iter++;
	}
	// 대칭인 곳 까지만 상태 뒤집기
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> switches[i];
	cin >> student_num;
	for (int i = 0; i < student_num; i++) {
		cin >> sex >> pos;
		students[i] = { sex, pos };
		// first가 성별, second가 받은 스위치 수
	}

	for (int i = 0; i < student_num; i++) {
		if (students[i].first == 1) // 남자면
			boy_behave(students[i].second);
		else // 여자면
			girl_behave(students[i].second);

	}

	for (int i = 1; i <= num; i++) {
		cout << switches[i] << " ";
		if (i % 20 == 0)
			cout << '\n';
	}

	return 0;
}
