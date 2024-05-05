#include <iostream>
#include <string>
#include <regex>
using namespace std;

string target = "";
int main() {
	cin >> target;

	regex re("((100+1+)|(01))+");
	if (regex_match(target, re))
		cout << "SUBMARINE";
	else
		cout << "NOISE";

	return 0;
}
