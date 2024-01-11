#include <iostream>
#include <list>
using namespace std;

int tc;
string target;
struct Node {
	Node* prev;
	Node* next;
	char keylog;

	Node(Node* prev, Node* next, char keylog) {
		this->prev = prev;
		this->next = next;
		this->keylog = keylog;
	}
};
int main() {
	cin >> tc;
	while (tc--) {
		Node* begin_node = new Node(NULL, NULL, 'X');
		// 아무것도 없는 깡통 커서
		Node* cursor = begin_node;

		cin >> target;
		for (char c : target) {
			if (c == '<') {
				if (cursor->prev != NULL)
					cursor = cursor->prev;
			}
			else if (c == '>') {
				if (cursor->next != NULL)
					cursor = cursor->next;
			}
			// < > 이동 시 마다 커서 이동
			else if (c == '-'){
				if (cursor->prev != NULL) {
					cursor->prev->next = cursor->next;
					if(cursor->next != NULL)
						cursor->next->prev = cursor->prev;
					// 연결을 끊어준다.

					cursor = cursor->prev;
					// 연결을 끊은 뒤 커서 이동
				}
			}
			else {
				Node* new_node = new Node(cursor, NULL, c);
				
				if (cursor->next != NULL)
					new_node->next = cursor->next;

				cursor->next = new_node;
				cursor = cursor->next;
			}
		}

		cursor = begin_node;
		while (cursor->next != NULL) {
			cursor = cursor->next;
			cout << cursor->keylog;
		}

		cout << '\n';
	}

	return 0; 
}
