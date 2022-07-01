#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next){
        this->n = n;
        this->prev = prev;
        this->next = next;
    }
};

stack<Node*> ctrlz;
string make_base(int n, string answer) {
    for (int i = 0; i < n; i++)
        answer += 'O';

    return answer;
}

int read_count(string cmd) {
    string temp;
    for (int i = 2; i < cmd.size(); i++) {
        temp += cmd[i];
    }

    return stoi(temp);
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    answer = make_base(n, answer);

    Node* cursor = new Node(0, NULL, NULL);
    for (int i = 1; i < n; i++) {
        cursor->next = new Node(i, cursor, NULL);
        cursor = cursor->next;
    } 

    for (int i = 0; i < n - k - 1; i++) cursor = cursor->prev;

    for (string comm : cmd) {
        int curr = 0;
        switch (comm[0]) {
        case 'U':
            curr = read_count(comm);
            while (curr--)
                cursor = cursor->prev;
            break;
        case 'D':
            curr = read_count(comm);
            while (curr--)
                cursor = cursor->next;
            break;
        case 'C':
            ctrlz.push(cursor);
            answer[cursor->n] = 'X';
            if (cursor->prev != NULL) cursor->prev->next = cursor->next;
            if (cursor->next != NULL) cursor->next->prev = cursor->prev;
            if (cursor->next == NULL) cursor = cursor->prev;
            else cursor = cursor->next;
            break;
        case 'Z':
            Node * undo = ctrlz.top();
            answer[undo->n] = 'O';
            ctrlz.pop();
            if (undo->prev != NULL) undo->prev->next = undo;
            if (undo->next != NULL) undo->next->prev = undo;
            break;
        }
    }

    return answer;
}
