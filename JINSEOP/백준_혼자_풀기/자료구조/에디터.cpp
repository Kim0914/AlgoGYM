#include <iostream>
using namespace std;

int num = 0;
string init_editor = "";
char cmd = 'X', char_to_add = 'X';
struct Node {
    char partial;
    Node* prev;
    Node* next;
    
    Node(char partial, Node* prev, Node* next) {
        this->partial = partial;
        this->prev = prev;
        this->next = next;
    }
};

int main() {
    cin >> init_editor;

    Node* head = new Node('#', NULL, NULL); // 첫 글자 삽입
    Node* cursor = head;
    for (int i = 0; i < init_editor.size(); i++) { // 문자열 전체 삽입
        cursor->next = new Node(init_editor[i], cursor, NULL);
        cursor = cursor->next;
    } // 끝나면 커서는 자동으로 마지막 커서에 위치한다.

    cin >> num;
    for (int i = 0; i < num; i++) {

        cin >> cmd;
        switch (cmd)
        {
        case 'L':
            if (cursor->prev != NULL)
                cursor = cursor->prev;
            // 문장의 맨 앞이 아니면 이전으로
            break;
        case 'D':
            if (cursor->next != NULL)
                cursor = cursor->next;
            // 문장의 맨 끝이 아니면 다음으로
            break;
        case 'B':
            if (cursor->prev == NULL)
                continue;
            // 문장의 제일 처음이면 삭제 안해도 됨
            cursor->prev->next = cursor->next;
            if (cursor->next != NULL)
                cursor->next->prev = cursor->prev;
            else
                cursor->next = NULL;
            // 문장의 제일 마지막이 아니면? NULL로 만듬
            cursor = cursor->prev; // 이전 커서로 이동
            break;
        case 'P':
            cin >> char_to_add;

            Node* inserted_node = new Node(char_to_add, NULL, NULL);
            // 커서 왼쪽에 문자를 추가한다는 것은 해당 문자 뒤에 추가하는 것
            // 새로 생긴 노드의 prev를 현재 커서로.
            if (cursor->next != NULL) {
                cursor->next->prev = inserted_node;
                inserted_node->next = cursor->next;
            }

            cursor->next = inserted_node;
            inserted_node->prev = cursor;
            cursor = cursor->next;
            
            break;
        }
    }
    // 연결 리스트 자료구조는, 삽입과 삭제가 O(1)만에 이루어진다.
    // 따라서 위와 같은 에디터 구조를 짜기 매우 좋은 자료구조!

    cursor = head->next; // 처음의 다음 커서로 이동
    while (cursor->next != NULL) {
        cout << cursor->partial;
        cursor = cursor->next;
    }
    cout << cursor->partial;

    return 0;
}
