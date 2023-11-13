#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long

ll num = 0;
void calculate_sequence(int num) {
	string huge_integer = to_string(pow(2, num));
	int point_idx = huge_integer.find('.');
	huge_integer = huge_integer.substr(0, point_idx);
	huge_integer[huge_integer.size() - 1] -= 1;

	cout << huge_integer << '\n';
}

void move_hanoi(ll depth, int source, int auxiliary, int destination) {
	// 하노이의 탑은 분할 정복 알고리즘의 대표적인 문제이다.
	if (depth == 1) {
		cout << source << " " << destination << "\n";
		return;
	}

	// STEP 1. n-1개의 원판을 보조 기둥으로 옮긴다.
	move_hanoi(depth - 1, source, destination, auxiliary);
	// STEP 2. 남은 1개를 목적지 기둥으로 옮긴다.
	cout << source << " " << destination << "\n";
	// STEP 3. 보조 기둥에 옮겼던 n-1개의 원판을 목적지 기둥으로 옮긴다.
	move_hanoi(depth - 1, auxiliary, source, destination);
}

int main() {
	cin >> num;

	// 하노이의 탑은 n개의 원판을 최소 2^n - 1 회만에 옮길 수 있다.
	calculate_sequence(num);
	
	if(num <= 20) // 20개 이상은 출력할 필요 없다.
		move_hanoi(num, 1, 2, 3);

	return 0;
}
