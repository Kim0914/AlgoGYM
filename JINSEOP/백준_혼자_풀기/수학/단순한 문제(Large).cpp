#include <iostream>
using namespace std;

int tc = 0;
int main() {
	cin >> tc;
	
	while (tc--) {
		int a = 0, b = 0, c = 0, cnt = 0;
		cin >> a >> b >> c;

		cout << min(min(a, b), c) << '\n';
	}

	return 0;
}

// (x mod y) == (y mod z) == (z mod k) 여야 한다.
// 그럼 x >= y >= z >= x 인 경우에 위의 식의 해가 존재하므로,
// x = y = z 일 수 밖에 없다.
