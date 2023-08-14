#include <iostream>
using namespace std;

int tc = 0, n = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int two_cnt = 0, five_cnt = 0;
		cin >> n;
		
		for (int i = 2; i <= n; i *= 2)
			two_cnt += n / i; // 이러면 2의 수만 세짐
		for (int i = 5; i <= n; i *= 5)
			five_cnt += n / i; // 이러면 5의 수만 세짐

		cout << min(two_cnt, five_cnt) << '\n';
	}
	return 0;
}
