#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

string src = "", target = "";
int hash_map[100];
int main() {
	OPTIMIZE;

	cin >> src >> target;
	for (int i = 0; i < src.size(); i++) {
		int idx = src[i] - '!';

		if (!hash_map[idx])
			hash_map[idx] = i + 1;
		// 각 문자를 ascii 코드로 치환했을 때의 위치를 처장한다.
	}

	long long answer = 0;
	for (int i = 0; i < target.size(); i++) {
		int idx = target[i] - '!';

		answer *= src.size();
	// 뒤로 갈수록 원본 문자 목록의 길이만큼 곱해주면 된다.
	// ex) bca에서 cc를 찾는 방법
	// c의 위치가 2니, 2 + (2 * 3)을 하면 된다. 
	// 2 * 3은 1번 위치에 있는 문자열로 만드는 경우를 모두 뛰어넘긴 것!
		answer += hash_map[idx];
	// 내가 찾고자 하는 문자의 위치만큼 더한다.
		answer %= 900528;
	}

	cout << answer;
	return 0;
}
