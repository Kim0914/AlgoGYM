#include <iostream>
#include <algorithm>
using namespace std;

string target = "";
int answer = 0;
string add_and_reverse(string source) {
	source += "B";
	reverse(source.begin(), source.end());
	return source;
}

string add_string(string source) {
	source += "A";
	return source;
}

void make_word(string src) {
	if (src.size() == target.size()) {
		if (src == target)
			answer = 1;
		return;
	}

	make_word(add_and_reverse(src));
	make_word(add_string(src));
}

int main(){
	string src;
	cin >> src >> target;

	make_word(src);
	cout << answer;
	return 0;
}
