#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> counter;
int main(){
	string target = "";
	cin >> target;

	for (int i = 0; i < target.size(); i++)
		counter[target[i]]++;

	int init_zero = counter['0'];
	int init_one = counter['1'];

	int iter = target.size();
	while (counter['0'] > (init_zero / 2)) {
		if (iter < 0)
			break;
		if (target[iter] == '0') {
			target[iter] = '#';
			counter['0']--;
		}

		iter--;
	}

	iter = 0;
	while (counter['1'] > (init_one / 2)) {
		if (iter >= target.size())
			break;
		if (target[iter] == '1') {
			target[iter] = '#';
			counter['1']--;
		}

		iter++;
	}

	for (int i = 0; i < target.size(); i++) {
		if (target[i] != '#')
			cout << target[i];
	}

	return 0;
}
