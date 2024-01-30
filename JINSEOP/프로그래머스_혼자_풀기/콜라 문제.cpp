#include <string>
#include <vector>
#include <iostream>
using namespace std;

int calculate_coke(int a, int b, int n) {
	int add_coke = 0, rest = 0;

	if (n < a)
		return add_coke;

	while (n != 0) {
		if (n % a == 0)
			add_coke += ((n / a) * b);
		else {
			add_coke += ((n / a) * b);
			rest += (n % a);
		}

		n = (n / a) * b;
	}

	add_coke += calculate_coke(a, b, rest);
	return add_coke;
}

int solution(int a, int b, int n) {
	int answer = 0;

	answer = calculate_coke(a, b, n);
	return answer;
}
