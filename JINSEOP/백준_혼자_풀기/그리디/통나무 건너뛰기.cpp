#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int tc = 0;
int main()
{
	cin >> tc;
	while (tc--) {
		int num = 0;
		cin >> num;

		int height = 0;
		vector<int> height_info;
		for (int i = 0; i < num; i++) {
			cin >> height;
			height_info.push_back(height);
		}
		sort(height_info.begin(), height_info.end());

		int answer = height_info[1] - height_info[0];
		for (int i = 2; i < num; i += 2)
			answer = max(answer, height_info[i] - height_info[i - 2]);
		for (int i = 3; i < num; i += 2)
			answer = max(answer, height_info[i] - height_info[i - 2]);

		cout << answer << '\n';
	}

	return 0;
}
