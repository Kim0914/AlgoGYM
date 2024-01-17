#include <iostream>
#include <unordered_map>
using namespace std;

int num = 0, target_num = 0;
string input_str = "";
unordered_map<string, bool> validator;
void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();
	cin >> num >> target_num;

	for (int i = 0; i < num; i++) {
		cin >> input_str;
		validator[input_str] = true;
	}

	int answer = 0;
	for (int i = 0; i < target_num; i++) {
		cin >> input_str;
		if (validator[input_str])
			answer++;
	}

	cout << answer;
	return 0;
}
