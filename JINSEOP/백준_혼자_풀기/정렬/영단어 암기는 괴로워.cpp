#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, min_len = 0;
string voca = "";
unordered_map<string, int> voca_note;
vector<pair<string, int>> voca_vector;
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size())
			return a.first < b.first;
		
		return a.first.size() > b.first.size();
	}

	return a.second > b.second;
}

int main(){
	optimize();
	cin >> num >> min_len;

	for (int i = 0; i < num; i++) {
		cin >> voca;
		if (voca.size() >= min_len)
			voca_note[voca]++;
	}

	for (auto& m : voca_note) 
		voca_vector.push_back({ m.first, m.second });

	sort(voca_vector.begin(), voca_vector.end(), cmp);
	for (auto& p : voca_vector)
		cout << p.first << '\n';

	return 0;
}
