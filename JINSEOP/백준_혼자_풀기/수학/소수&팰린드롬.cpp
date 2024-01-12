#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1003002

int target = 0;
bool sieve[MAX_N];
void fill_seive() {
	sieve[1] = true; // 1은 소수가 아님
	for (int i = 2; i * i < MAX_N; i++) {
		for (int j = i * 2; j < MAX_N; j += i)
		// j += i를 통해서 배수만 골라내기
		// 단, i가 아닌 i * 2부터 시작해야 함
			sieve[j] = true;
	}
}

bool check_prime(int target) {
	if (sieve[target])
		return false;
	
	return true;
}

bool check_palindrome(string target_str) {
	int left_ptr = 0, right_ptr = target_str.size() - 1;

	while (left_ptr <= right_ptr) {
		if (target_str[left_ptr] != target_str[right_ptr])
			return false;

		left_ptr++;
		right_ptr--;
	}

	return true;
}

int main() {
	cin >> target;

	fill_seive();
	while (true) {
		bool is_prime = check_prime(target);
		bool is_palindrome = check_palindrome(to_string(target));
		
		if (is_prime && is_palindrome)
			break;

		target++;
	}

	cout << target;
	return 0; 
}
