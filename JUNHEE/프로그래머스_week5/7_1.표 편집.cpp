#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int select(char alpha){
    char list[4] = {'U', 'D', 'C', 'Z'};
    for(int i = 0; i < 4; i++){
        if(alpha == list[i]) return i;
    }
    return -1;
}

struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    
    Node* cur = new Node(0, NULL, NULL);
    for(int i=1;i<n;i++) {
        cur->next = new Node(i, cur, NULL);
        cur = cur->next;
    }
    
    
    for(int i=0;i<n-k-1;i++) 
        cur = cur->prev;
    
    int x;
    stack<Node*> del;
    for(string str : cmd) {
        switch (select(str[0])){
            case 0:
                x = stoi(str.substr(2));
                while(x--) cur = cur->prev;
                break;
            case 1:
                x = stoi(str.substr(2));
                while(x--) cur = cur->next;
                break;
            case 2:
                del.push(cur);
                if(cur->prev != NULL) cur->prev->next = cur->next;
                if(cur->next != NULL) cur->next->prev = cur->prev;
                if(cur->next == NULL) cur = cur->prev;
                else cur = cur->next;
                break;
            case 3:
                Node* r = del.top(); del.pop();
                if(r->prev != NULL) r->prev->next = r;
                if(r->next != NULL) r->next->prev = r;
                break;
        }
    }
    
    answer[cur->n] = 'O';
    while(cur->prev != NULL) {
        answer[cur->prev->n] = 'O';
        cur = cur->prev;
    }
    while(cur->next != NULL) {
        answer[cur->next->n] = 'O';
        cur = cur->next;
    }
    
    return answer;
}
