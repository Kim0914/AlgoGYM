#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> idol_info;
unordered_map<string, string> r_idol_info;
int num = 0, prob_num = 0;
int main() {
	cin >> num >> prob_num;

	int member_num = 0, prob_kind = 0;
	string group_name = "", member_name = "";
	for (int i = 0; i < num; i++) {
		cin >> group_name >> member_num;

		vector<string> temp_vec;
		for (int j = 0; j < member_num; j++) {
			cin >> member_name;
			r_idol_info[member_name] = group_name;
			temp_vec.push_back(member_name);
		}

		sort(temp_vec.begin(), temp_vec.end());
		idol_info[group_name] = temp_vec;
	}

	for (int i = 0; i < prob_num; i++) {
		cin >> member_name >> prob_kind;

		if (prob_kind == 0)
			for (auto mem : idol_info[member_name])
				cout << mem << '\n';
		else
			cout << r_idol_info[member_name] << '\n';
	}

	return 0;
}
