#include <iostream>
#include <string>
using namespace std;

int main() {
	string expr = "", num = "";
	bool exist_minus = false;
	int sum = 0;
	cin >> expr;

	for (int i = 0; i < expr.size(); i++) {
		if ('0' <= expr[i] && expr[i] <= '9')
			num += expr[i];

		if (expr[i] == '-') {
			if (exist_minus) {
				sum -= stoi(num);
				num = "";
			}
			else {
				exist_minus = true;
				sum += stoi(num);
				num = "";
			}
		}
		else if (expr[i] == '+') {
			if (exist_minus) {
				sum -= stoi(num);
				num = "";
			}
			else {
				sum += stoi(num);
				num = "";
			}
		}
	}

	if (exist_minus)
		sum -= stoi(num);
	else
		sum += stoi(num);

	cout << sum;

	return 0;
}
