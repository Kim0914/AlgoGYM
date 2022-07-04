#include <string>
#include <vector>
#include <deque>

using namespace std;

bool check(deque<char> &d){
    deque<int> s;
    for(char c: d){
        if(c == '[' || c == '{' || c == '(') s.push_back(c);
        else{
            if(s.empty()) return false;
            if(c == ']' && s.back() == '[') s.pop_back();
            else if(c == '}' && s.back() == '{') s.pop_back();
            else if(c == ')' && s.back() == '(') s.pop_back();  
        }
    }
    if(s.empty()) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    deque<char> d;

    for(char c: s){
        d.push_back(c);
    }
    
    int dSize = d.size();
    while(dSize--){
        if(check(d)) answer++;
        d.push_back(d.front());
        d.pop_front();
    }

    return answer;
}