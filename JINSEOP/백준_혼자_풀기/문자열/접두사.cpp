#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int num = 0;
unordered_map<string, int> suffix_map;
vector<string> str_vec;
bool cmp(string a, string b) {
	return a.size() > b.size();
}

int main() {
	cin >> num;

	string input_str;
	for (int i = 0; i < num; i++) {
		cin >> input_str;
		str_vec.push_back(input_str);
	}
	sort(str_vec.begin(), str_vec.end(), cmp);

	int answer = 0; // 비어있는 집합은 반드시 존재
	for (int i = 0; i < str_vec.size(); i++) {
		if (!suffix_map[str_vec[i]])
			answer++;

		string temp = "";
		for (int j = 0; j < str_vec[i].size(); j++) {
			temp += str_vec[i][j];
			suffix_map[temp]++;
		}
	}

	cout << answer;
	return 0;
}
