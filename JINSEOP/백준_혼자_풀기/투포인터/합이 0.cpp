#include <iostream>
#include <algorithm>
using namespace std;

int num = 0;
int teammates[10000];
int main() {
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> teammates[i];

	sort(teammates, teammates + num);
	// 우선 투 포인터를 사용하기 위해 정렬이 필요하다.

	
	return 0;
}
