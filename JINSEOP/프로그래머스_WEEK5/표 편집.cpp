#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

struct Node {
    int rownum;
    Node* prev;
    Node* next;

    Node(int rownum, Node* prev, Node* next){
        this->rownum = rownum;
        this->prev = prev;
        this->next = next;
    }
    // 구조체 생성자
};

stack<Node*> ctrlz;
string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O'); // 기본 정답 생성

    Node* cursor = new Node(0, NULL, NULL);
    // 가장 첫 칸, 0번째 칸을 만들어 놓는다.
    for (int i = 1; i < n; i++) {
        cursor->next = new Node(i, cursor, NULL);
        cursor = cursor->next;
    }
    // 최초의 표 생성

    for (int i = 0; i < n - k - 1; i++)
        cursor = cursor->prev;
    // 커서가 마지막 칸의 다음 칸을 가리켰으니
    // 처음 시작 위치인 k로 옮겨야 한다.

    for (string s : cmd) {
        int num_to_move = 0;

        switch (s[0])
        {
        case 'U':
            num_to_move = stoi(s.substr(2));
            while (num_to_move--)
                cursor = cursor->prev;
            // 연결리스트에서 이전 노드로 이동
            break;
        case 'D':
            num_to_move = stoi(s.substr(2));
            while (num_to_move--)
                cursor = cursor->next;
            // 연결리스트에서 다음 노드로 이동
            break;
        case 'C':
            ctrlz.push(cursor);
            // 현재 가리키는 커서가 0번이 아니면?
            if (cursor->prev != NULL)
                // 이전 요소와 다음 요소를 연결
                cursor->prev->next = cursor->next;
            // 현재 가리키는 커서가 마지막 행이 아니면?
            if (cursor->next != NULL)
                // 다음 요소를 이전 요소와 연결
                cursor->next->prev = cursor->prev;
            // 현재 커서가 마지막 행이면?
            if (cursor->next == NULL)
                // 커서를 이전 요소로 옮김(이전 요소를 마지막 행으로)
                cursor = cursor->prev;
            // 현재 커서가 첫 행이면?
            else
                // 커서를 다음 요소로 옮김(다음 요소를 첫 행으로)
                cursor = cursor->next;
            break;
        case 'Z':
            Node* redo = ctrlz.top();
            ctrlz.pop();
            if (redo->prev != NULL)
            // 스택에 쌓아두었던 이전 시점을 꺼내 연결한다.
            // 첫 행이 아니었다면, 이전 요소에 연결한다.
                redo->prev->next = redo;
            if (redo->next != NULL)
            // 마지막 행이 아니었다면, 다음 요소에 연결한다.
                redo->next->prev = redo;
            break;
        }
    }

    while (!ctrlz.empty()) {
        answer[ctrlz.top()->rownum] = 'X';
        ctrlz.pop();
    }

    return answer;
}

int main() {
    solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });
    return 0;
}
