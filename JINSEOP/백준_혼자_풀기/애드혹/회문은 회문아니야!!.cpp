#include <iostream>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

string target = "";
int dp[51][51];
bool check_palindrome() {
	int size = target.size();
	for (int i = 0; i < size / 2; i++) {
		if (target[i] != target[size - 1 - i])
			return false;
	}

	return true;
}

bool check_identity() {
	for (int i = 0; i < target.size(); i++) {
		if (target[i] != target[0])
			return false;
	}

	return true;
}

int main() {
	OPTIMIZE;
	
	cin >> target;
	if (check_identity())
		cout << -1;
	else if (check_palindrome())
		cout << target.size() - 1;
	else
		cout << target.size();
	// 1. 모두 같은 문자이면? 반드시 팰린드롬이다.
	// 2. 팰린드롬이라면? 끝의 문자를 하나 제거하면 그게 가장 길다.
	// 3. 팰린드롬이 아니라면? 그냥 답을 출력하면 된다.

	return 0;
}
