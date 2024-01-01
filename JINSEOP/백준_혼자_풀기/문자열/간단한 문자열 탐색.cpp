#include <iostream>
#include <string>
using namespace std;

string src = "", target = "";
int answer = 0;
bool check_word(int idx) {
	for (int i = idx; i < idx + target.size(); i++) {
		if (src[i] != target[i - idx])
			return false;
	}

	return true;
}

int main() {
	getline(cin, src);
	getline(cin, target);

	int iter = 0;
	while (true) {
		if (check_word(iter)) {
			answer++;
			iter += target.size();
		}
		else
			iter++;

		if (iter > src.size())
			break;
	}

	cout << answer;
	return 0;
}
