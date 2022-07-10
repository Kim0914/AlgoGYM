#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string remove_min(string number, int k) {
	int cnt = 0, iter = 0;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < number.size(); j++) {
			if (number[j] < number[j + 1]) {
				number.erase(number.begin() + j);
				break;
			}
		}
	}

	return number;
}

string solution(string number, int k) {
	string answer = number;
	int pre_len = number.size(), post_len = 0;

	answer = remove_min(number, k);
	post_len = answer.size();

	if (pre_len == post_len)
		answer.erase(answer.end()-1);

	return answer;
}
