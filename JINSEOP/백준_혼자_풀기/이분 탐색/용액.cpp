#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int num = 0;
long long min_value = 9999999999, left_liquid = 0, right_liquid = 0, liquid[100001];
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> liquid[i];

	int left = 0, right = num - 1;
	// 정렬된 용액에 대해 왼쪽 끝 오른쪽 끝을 각각 집는다.
	while (left < right) { // 커서가 같아질 때 까지 반복
		long long characteristic_value = liquid[left] + liquid[right];

		if (min_value > abs(characteristic_value)) { // 최소 특성 값을 갱신하며 진행한다.
			min_value = abs(characteristic_value);
			left_liquid = liquid[left];
			right_liquid = liquid[right];
		}

		if (characteristic_value > 0) // 특성 값이 양수이면 양수 용액을 줄임
			right--;
		else if (characteristic_value < 0) // 특성 값이 음수이면 음수 용액을 높임
			left++;
		else if (characteristic_value == 0) // 0이면 종료해도 된다.
			break; // 오름차순으로 주어지기에 가능한 문제
	}

	cout << left_liquid << " " << right_liquid;

	return 0;
}
