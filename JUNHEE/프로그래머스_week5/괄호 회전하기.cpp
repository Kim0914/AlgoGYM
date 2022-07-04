#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;


bool is_right(string s){
    stack<char> str;
    char temp;
    for(int i=0;i<s.size();i++){
        temp = s[i];
        if(temp == ')'){
            if(str.top() == '('){
                str.pop();
            }
            else{
                str.push(temp);
            }
        }
        else if(temp == ']'){
            if(str.top() == '['){
                str.pop();
            }
            else{
                str.push(temp);
            }
        }
        else if(temp == '}'){
            if(str.top() == '{'){
                str.pop();
            }
            else{
                str.push(temp);
            }
        }
        else{
            str.push(temp);
        }
    }
    if(str.empty()) return true;
    else return false;
}
string rotation(string s){
    char start = s[0];
    for(int i=0;i<s.size()-1;i++){
        s[i] = s[i+1];
    }
    s[s.size()-1] = start;
    return s;
}
int solution(string s) {
    int answer = 0;
    is_right(s);
    for(int i = 0; i < s.size();i++){
        s = rotation(s);
        if(is_right(s))
            answer++;
    }
    return answer;
}
