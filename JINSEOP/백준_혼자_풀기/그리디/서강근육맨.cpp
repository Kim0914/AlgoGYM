#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll num = 0, loss = 0, min_loss = 0;
vector<ll> work_out;
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> loss;
		work_out.push_back(loss);
	}

	sort(work_out.begin(), work_out.end());

	if (num % 2 != 0) {
		min_loss = work_out[num - 1];
		num -= 1; // 제일 큰 한 놈을 제외하고 운동한다.

		for (int i = 0; i < num / 2; i++)
			min_loss = max(min_loss, (work_out[i] + work_out[(num - 1) - i]));

		min_loss = max(min_loss, work_out[work_out.size() - 1]);
	}
	else {
		for (int i = 0; i < num / 2; i++)
			min_loss = max(min_loss, (work_out[i] + work_out[(num - 1) - i]));
	}

	cout << min_loss;

	return 0;
}
