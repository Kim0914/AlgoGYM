#include <iostream>
#include <string>
using namespace std;

struct Trie {
	Trie *node[10];
	bool finish;

	Trie() {
		finish = false;
		for (int i = 0; i < 10; i++)
			node[i] = NULL;
		// 초기화 
	}

	void insert(char *str) {
		if (*str == NULL) {
			finish = true;
			return;
		}

		int curr = *str - '0';
		if (node[curr] == NULL)
			node[curr] = new Trie();
		node[curr]->insert(str + 1);
	}

	bool find(char *str) {
		if (*str == NULL)
			return false;

		if (finish == true)
			return true;

		int curr = *str - '0';
		if (node[curr] == NULL)
			return false;
		return node[curr]->find(str + 1);
	}
};

void optimize() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int tc = 0, num = 0;
char input_str[10000][11];
int main() {
	optimize();
	cin >> tc;

	while (tc--) {
		cin >> num;
		Trie *root = new Trie();

		for (int i = 0; i < num; i++) {
			cin >> input_str[i];
			root->insert(input_str[i]);
		}

		bool flag = true;
		for (int i = 0; i < num; i++) {
			if (root->find(input_str[i])) {
				flag = false;
				cout << "NO" << '\n';
				break;
			}
		}

		if (flag)
			cout << "YES" << "\n";
	}

	return 0;
}
