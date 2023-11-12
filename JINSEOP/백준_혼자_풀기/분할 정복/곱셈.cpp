#include <iostream>
using namespace std;
#define ll long long 

ll num = 0, mult = 0, divisor = 0, remaind = 0;
ll power(ll mult) {
	// 분할 정복의 기초, 쪼개어 큰 문제를 해결한다.
	// 거듭제곱은? b승이 짝수 -> a^(b/2) * a^(b/2)
	// b승이 홀수 -> a^(b/2) * a^(b/2 + 1)
	if (mult == 0)
		return 1; // 0승은 1이다.
	if (mult == 1)
		return num % divisor; // 1승은 그냥 나머지

	remaind = power(mult / 2) % divisor;
  // 이 부분이 핵심이다.
  // 계산량을 줄이기 위해, remaind 변수에서 나머지를 계속 기억하고 있는다.
  
	if (mult % 2 == 0)
		return (remaind * remaind) % divisor;
  // 기억하고 있던 나머지끼리 곱하고 다시 나누어 결과를 계산한다.
	else
		return (((remaind * remaind) % divisor) * num) % divisor;
  // mult승이 홀수 승인 경우에는, 뒤에 num을 한번 더 곱한 뒤 나누어준다.
  // 이 방식은 O(logN)이 걸리는 분할 정복법을 통한 거듭제곱 방식이다.
}

int main() {
	cin >> num >> mult >> divisor;
	cout << power(mult);

	return 0;
}
