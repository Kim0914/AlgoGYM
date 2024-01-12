#include <iostream>
using namespace std;

string target = "";
bool check_palindrome(int start_idx) {
	int rear_ptr = target.size() - 1;

	for (int i = start_idx; i < target.size(); i++) {
		if (target[i] != target[rear_ptr])
			return false;
		// start_idx 기준 제일 앞과 제일 뒤부터 팰린드롬 여부 검사

		rear_ptr--;
	}

	// 마지막 한글자만 남는 경우는 어차피 true를 반환하게 됨.
	return true;
}

int main() {
	cin >> target;

	int answer = target.size();
	bool is_palindrome = false;
	for (int i = 0; i < target.size(); i++) {
		if (check_palindrome(i))
			is_palindrome = true;

		if (is_palindrome) {
			cout << target.size() + i;
			break;
		}
	}

	return 0;
}
