#include <iostream>
#include <cmath>
using namespace std;

int num = 0;
void do_cantore(string target) {
	if (target.size() == 1) {
		cout << target;
		return;
	}

	string temp = "";
	for (int i = 0; i < target.size() / 3; i++)
		temp += target[i];

	do_cantore(temp);
	for (int i = 0; i < target.size() / 3; i++)
		cout << " ";
	do_cantore(temp);
}

int main() {
	while (cin >> num) {
		string target = "";

		for (int i = 0; i < pow(3, num); i++)
			target += '-';

		do_cantore(target);
		cout << '\n';
	}

	return 0;
}
