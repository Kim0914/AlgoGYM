#include <iostream>
#include <cmath>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int num = 0, timer = 0;
double balls[12];
int main() {
	OPTIMIZE;

	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> balls[i];
	cin >> timer;

	double expectation_value = 0.0;
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (abs(balls[i] - balls[j]) <= timer * 2)
				expectation_value += 0.25;
		}
	}

	cout << expectation_value;
	return 0;
}
