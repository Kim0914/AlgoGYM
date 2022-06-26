#include <iostream>
using namespace std;

pair<int, int> idxs = {0, 0};

int calc_alpha(string name) {
	int cnt = 0;
	for (int i = 0; i < name.size(); i++)
		if (name[i] != 'A') cnt++;
	return cnt;
}

pair<int, int> search_next(string& name, int idx) {
	for (int i = idx; i < name.size(); i++)
		if (name[i] != 'A')
			return make_pair(idx, i);
}

int calc_distance(string name) {
	int size_v = name.size();
	return min(idxs.second - idxs.first, idxs.first + (size_v - idxs.second));
}

int up_down(char part_name) {
	if (part_name - 'A' < 14)
		return part_name - 'A';
	else return 26 - ((part_name) -'A');
}

int solution(string name) {
	int answer = 0;
	int cnt = calc_alpha(name);

	while (true) {
		if (cnt == 0) break;
		idxs = search_next(name, idxs.second);
		answer += up_down(name[idxs.second]);
		name[idxs.second] = 'A';
		answer += calc_distance(name);
		cnt--;
	}

	return answer;
}

int main() {
	string name;
	cin >> name;

	cout << solution(name);
	return 0;
}
