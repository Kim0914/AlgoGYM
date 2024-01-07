#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num = 0;
char parent = 'Z', left_c = 'Z', right_c = 'Z';
pair<char, char> simple_tree[26];
void preorder(char curr_node) {
	if (curr_node == '.')
		return;

	cout << curr_node;
	preorder(simple_tree[curr_node - 'A'].first);
	preorder(simple_tree[curr_node - 'A'].second);
}

void inorder(char curr_node) {
	if (curr_node == '.')
		return;

	inorder(simple_tree[curr_node - 'A'].first);
	cout << curr_node;
	inorder(simple_tree[curr_node - 'A'].second);
}

void postorder(char curr_node) {
	if (curr_node == '.')
		return;

	postorder(simple_tree[curr_node - 'A'].first);
	postorder(simple_tree[curr_node - 'A'].second);
	cout << curr_node;
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> parent >> left_c >> right_c;
		simple_tree[parent - 'A'] = { left_c, right_c};
	}

	preorder('A'); cout << '\n';
	inorder('A'); cout << '\n';
	postorder('A');
	return 0;
}
