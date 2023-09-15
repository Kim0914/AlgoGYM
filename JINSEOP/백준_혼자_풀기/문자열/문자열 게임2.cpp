#include <iostream>
#include <unordered_map>
using namespace std;

int tc = 0, limit = 0;
string game_string = "";
int main(){
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> game_string >> limit;
		unordered_map<char, int> char_counter;
		for (int i = 0; i < game_string.size(); i++)
			char_counter[game_string[i]]++; // 모든 알파벳의 빈도 저장
      // 알파벳의 빈도를 조사해 시간을 줄이기 위한 용도

		int min_length = 99999999, max_length = 0;
		for (int i = 0; i < game_string.size(); i++) {
			if (char_counter[game_string[i]] < limit)
				continue; // 해당 알파벳은 탐색할 필요가 없다.

			int alphabet_cnt = 0;
			for (int j = i; j < game_string.size(); j++) {
				if (game_string[i] == game_string[j]) // 부분 문자열의 시작과 끝이 같으면
					alphabet_cnt++; // 카운트를 하나 올린다.

				if (alphabet_cnt == limit) { // 카운트 수가 같다는 것은 limit회 등장했다는 것
					min_length = min(min_length, j - i + 1);
					max_length = max(max_length, j - i + 1);
					break; // 바로 최소 길이와 최대 길이를 갱신한다.
				}
			}
		}

		if (min_length == 99999999 || max_length == 0)
			cout << "-1" << '\n';
		else
			cout << min_length << " " << max_length << '\n';
	}

	return 0;
}
