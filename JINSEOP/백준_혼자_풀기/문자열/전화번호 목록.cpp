#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int tc = 0, num = 0;
string input_str = "";
void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	optimize();
	cin >> tc;
	while (tc--) {
		cin >> num;
		vector<string> str_vec;
		unordered_map<string, bool> prefix_validator;

		for (int i = 0; i < num; i++) {
			cin >> input_str;
			str_vec.push_back(input_str);
		}

		sort(str_vec.begin(), str_vec.end());
		// 짧은 문자열부터 훑도록 하자.
		bool cannot = false;
		for (int i = 0; i < str_vec.size(); i++) {
			string temp = "";

			for (int j = 0; j < str_vec[i].size(); j++) {
				temp += str_vec[i][j];

				if (prefix_validator[temp]) {
					cannot = true;
					cout << "NO" << '\n';
					break;
				}
			}

			if (cannot)
				break;
			prefix_validator[str_vec[i]] = true;
		}

		if (!cannot)
			cout << "YES" << '\n';
	}

	return 0;
}
