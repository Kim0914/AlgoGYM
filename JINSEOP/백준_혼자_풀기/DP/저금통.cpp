#include <iostream>
#include <string>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int num = 0;
int prime_info[1000000], dp[1000][1000];
void init_array() {
	for (int i = 0; i < 1000000; i++)
		prime_info[i] = i;
}

void make_eratostenes() {
	for (int i = 2; i < 1000000; i++) {
		if (prime_info[i] == 0)
			continue;

		for (int j = i + i; j < 1000000; j += i)
			prime_info[j] = 0;
	}
}

string integer_to_string(int x, int y) {
	string result = "";
	string str_x = to_string(x);
	string str_y = to_string(y);

	result = str_x + str_y;
	return result;
}

int main() {
	OPTIMIZE;
	cin >> num;

	init_array();
	make_eratostenes();
	// 소수 목록을 미리 만들어 놓는다.

	dp[1][1] = 0;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (i == 1 && j == 1)
				continue;

			if (prime_info[stoi(integer_to_string(i, j))])
				dp[i][j]++;
			// 현재 읽는 상태가 소수면 값을 1 더해줌
			dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
			// 이전부터 갱신해오는 소수들을 덮어쓰기
		}
	}

	cout << dp[num][num];
	return 0;
}
