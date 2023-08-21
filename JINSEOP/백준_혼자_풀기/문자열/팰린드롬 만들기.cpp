#include <iostream>
#include <string>
using namespace std;

int alpha_arr[26];
string target = "", answer = "";
int odd_cnt = 0, odd_idx = 0;
bool is_even = false;
int main() {
	cin >> target;

	for (int i = 0; i < target.size(); i++) 
		alpha_arr[target[i] - 'A']++;

	for (int i = 0; i < 26; i++) {
		if (alpha_arr[i] != 0) {
			if (alpha_arr[i] % 2 == 1) {
				is_even = true;
				odd_cnt++;
				odd_idx = i;
			}
			if (alpha_arr[i] > 1) {
				is_even = true;
				for (int j = 0; j < alpha_arr[i] / 2; j++)
					answer += (i + 'A');
			}
		}
	}

	if (!is_even || odd_cnt > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	
	string copied_answer = answer;
	if(odd_cnt != 0)
		answer += (odd_idx + 'A');
	for (int i = copied_answer.size() - 1; i >= 0; i--)
		answer += copied_answer[i];

	cout << answer;

	return 0;
}
