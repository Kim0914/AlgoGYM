#include <iostream>
#include <unordered_map>
using namespace std;

int num = 0, answer = 0;
unordered_map<char, int> init_checker(string src){
	unordered_map<char, int> checker;

	for (int i = 0; i < src.size(); i++)
		checker[src[i]]++;

	return checker;
}

int main(){
	cin >> num;

	string src = "", target = "";
	cin >> src;

	unordered_map<char, int> src_checker;
	src_checker = init_checker(src);

	for (int i = 0; i < num - 1; i++) {
		cin >> target;
		int diff = src.size() - target.size();

		if (abs(diff) > 1)
			continue; // 둘의 차이가 1보다 크면 어차피 안됨

		unordered_map<char, int> target_checker;
		target_checker = init_checker(src);

		int cnt = 0;
		for (int i = 0; i < target.size(); i++) {
			if (target_checker[target[i]] > 0) {
				target_checker[target[i]]--;
				cnt++;
			}
		}

		if (diff > 0) {
			// 대상의 길이가 1 작은 경우
			if (cnt == src.size() - 1)
				answer++;
			// 기준 문자열의 구조보다 반드시 하나 작아야 한다.
		}

		if (diff == 0) {
			// 대상의 길이가 같은 경우
			if (cnt == src.size() || cnt == (src.size() - 1))
				answer++;
			// 대상과 동일한 구조이거나 한 글자만 다른 경우 비슷한 단어이다.
		}

		if (diff < 0) {
			// 대상의 길이가 1 긴 경우
			if (cnt == src.size())
				answer++;
			// 기본적으로 기준 문자열의 구성과는 동일해야 한다.
		}
	}

	cout << answer;
	return 0;
}
