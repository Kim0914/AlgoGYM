#include <iostream>
#include <unordered_map>
using namespace std;

int num = 0, rot_num = 0, rot_count = 0;
char rot_target = 'X';
bool duplicated = false;
string answer = "";
unordered_map<char, int> validator;
struct Node {
    char target;
    Node* prev;
    Node* next;
    
    Node(char target, Node* prev, Node* next) {
        this->target = target;
        this->prev = prev;
        this->next = next;
    }
};

bool check_duplication() {
    for (int i = 0; i < answer.size(); i++) {
        if(answer[i] != '?')
            validator[answer[i]]++;
        
        if (validator[answer[i]] > 1)
            return false;
    }

    return true;
}

int main() {
    cin >> num >> rot_num;

    Node* head = new Node('?', NULL, NULL); // 최초의 헤드 생성
    Node* cursor = head;

    for (int i = 1; i < num; i++) {
        cursor->next = new Node('?', cursor, NULL);
        // 헤드의 다음부터 새로운 노드 삽입
        cursor = cursor->next; // 다음 노드로 이동
    }// 삽입이 끝나면, cursor는 마지막에 위치한다.

    cursor->next = head;
    head->prev = cursor; // 헤드와 꼬리를 연결해주어야 원형 리스트!
    cursor = head; // 로직을 위해 커서를 머리로 옮기자.

    for (int i = 0; i < rot_num; i++) {
        cin >> rot_count >> rot_target;

        while (rot_count--)
            cursor = cursor->next; // 회전 수 만큼 이동

        if (cursor->target != '?' && cursor->target != rot_target) {
            duplicated = true;
            continue;
        }

        cursor->target = rot_target; // 이동 후 어떤 문자인지 밝힘
    }

     while (num--) {
        answer += (cursor->target);
        cursor = cursor->prev; // 따로 삭제할 필요는 없음
     }

     if (!check_duplication() || duplicated)
         cout << "!";
     else
         cout << answer;

    return 0;
}
