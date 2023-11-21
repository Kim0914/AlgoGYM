#include <iostream>
using namespace std;

int num = 0, balloon = 0;
struct Node {
    int balloon_num;
    int index;
    Node* prev;
    Node* next;

    Node (int balloon_num, int index, Node* prev, Node* next) {
        this->balloon_num = balloon_num;
        this->index = index;
        this->prev = prev;
        this->next = next;
    }
};

int main() {
    cin >> num;
    
    cin >> balloon;
    Node* head = new Node(balloon, 1, NULL, NULL); // 새 노드 생성 (헤드)
    Node* cursor = head;

    for (int i = 1; i < num; i++) {
        cin >> balloon;
        cursor->next = new Node(balloon, i+1, cursor, NULL); // 다음 노드를 연결
        cursor = cursor->next; // 다음 노드로 이동 (추가를 위해)
    }

    cursor->next = head;
    head->prev = cursor;
    // 마지막까지 추가했으면, 연결리스트는 (풍선) <- 현재 -> NULL인 상태이다.
    // 그럼 이제 헤드를 연결해주면 원형 리스트가 완성된다.
    cursor = head; // 진행을 위해 커서를 헤드로 옮기자

    while (cursor->next != cursor && cursor->prev != cursor) {
      // 자기 자신을 가리키는 커서가 등장하게 되면, 더 이상 터뜨릴 풍선이 없는 것!
        cout << cursor->index << " ";
        
        int curr_balloon = cursor->balloon_num;
        if (curr_balloon > 0) {
            // 양수면 삭제하고 오른쪽으로 이동
            cursor->prev->next = cursor->next;
            cursor->next->prev = cursor->prev;
            while (curr_balloon--)
                cursor = cursor->next;
        }
        else {
          // 음수면 삭제하고 왼쪽으로 이동
            cursor->prev->next = cursor->next;
            cursor->next->prev = cursor->prev;
            while (curr_balloon++)
                cursor = cursor->prev;
        }
    }
    cout << cursor->index;

    return 0;
}
