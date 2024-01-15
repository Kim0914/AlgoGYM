#include <iostream>
using namespace std;

int tc = 0;
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();

	cin >> tc;
	while (tc--) {
		int stick_len = 0, num = 0, pos = 0, min_time = 0, max_time = 0;
		cin >> stick_len >> num;
		
		for (int i = 0; i < num; i++) {
			cin >> pos;

			int temp_min = min(pos, stick_len - pos);
			int temp_max = max(pos, stick_len - pos);
			min_time = max(temp_min, min_time);
			max_time = max(temp_max, max_time);
		}

		cout << min_time << " " << max_time << '\n';
	}

	return 0;
}
