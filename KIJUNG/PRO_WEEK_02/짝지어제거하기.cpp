#include <string>
#include <stack>
using namespace std;

int solution(string s){
    stack<int> st;

    for(char c: s){
        if(st.empty()) st.push(c);
        else {
            if(st.top() == c) st.pop();
            else st.push(c);
        } 
    }
    
    if(st.empty()) return 1;

    return 0;
}