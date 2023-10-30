#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;
string temp = "";
string erase_and_reverse(string source) {
	source.erase(source.begin());
	reverse(source.begin(), source.end());
	return source;
}

string erase_string(string source) {
	source.erase(source.size() - 1);
	return source;
}

void make_word(string src, string target) {
	if (src.size() == target.size()) {
		if (src == target)
			answer = 1;
		return;
	}

	if (target[target.size() - 1] == 'A') {
		// 끝이 A로 끝나면 단순히 A를 붙인 동작이다.
		temp = target;
		temp = erase_string(temp);

		make_word(src, temp);
	}
	if (target[0] == 'B') {
		// B로 시작하면 B를 붙이고 뒤집은 동작이다.
		temp = target;
		temp = erase_and_reverse(temp);

		make_word(src, temp);
	}
}

int main(){
	string src = "", target = "";
	cin >> src >> target;

	make_word(src, target);
	cout << answer;
	return 0;
}
