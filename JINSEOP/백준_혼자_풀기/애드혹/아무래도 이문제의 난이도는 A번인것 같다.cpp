#include <iostream>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int tc = 0, a = 0, b = 0;
int main() {
	OPTIMIZE;
	cin >> tc;

	while (tc--) {
		cin >> a >> b;
		cout << "yes" << '\n';
		// *1과 *(-1)이 가능하기 때문에
		// 모든 조합이 가능하다
	}

	return 0;
}
