#include <iostream>
using namespace std;

struct Trie {
	bool finish; // 문자열 끝
	Trie* node[26]; // 알파벳 26글자

	Trie() {
		finish = false;
		for (int i = 0; i < 26; i++)
			node[i] = NULL;
		// 26개 노드 초기화
	}

	void insert(char *str) {
		if (*str == NULL) {
			finish = true;
			return;
		// 더 이상 문자가 없으면 탐색 종료
		// 종료시에 해당 노드 finish true로 꼭 변경
		}

		int curr = *str - 'a'; // 현재 문자
		if (node[curr] == NULL)
			node[curr] = new Trie();
		// 현재 문자 자리가 비어있으면, 새 트라이 삽입
		node[curr]->insert(str + 1);
		// 해당 트라이로 재귀적으로 파고든다.
	}

	bool find(char* str) {
		if (*str == NULL)
			return true;
		// 더 이상 찾을 문자가 없으면 접두사가 맞음!
		if (finish == true)
			return false;
		// 이미 등록된 문자열의 끝, 접두사가 아님!

		int curr = *str - 'a';
		if (node[curr] == NULL)
			return false;
		// 현재 문자 자리가 비어있으면, 아예 없는 문자
		return node[curr]->find(str + 1);
		// 재귀적으로 다음 트라이를 탐색
	}
};

void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int num = 0, target_num = 0, answer = 0;
char input_str[10000];
int main() {
	optimize();
	cin >> num >> target_num;

	Trie* root = new Trie(); // 새 트라이 생성
	for (int i = 0; i < num; i++) {
		cin >> input_str;
		root->insert(input_str);
		// 입력받는 문자열 모두 트라이에 삽입
	}

	for (int i = 0; i < target_num; i++) {
		cin >> input_str;
		if (root->find(input_str))
			answer++;
		// 트라이 탐색 후, 접두사면 횟수 증가
	}

	cout << answer;
	return 0;
}
