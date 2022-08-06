#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    if(s.size() % 2 == 0){
        int idx = s.size() / 2;
        answer += s[idx-1];
        answer += s[idx];
    }
    else{
        int idx = s.size() / 2;
        answer += s[idx];
    }
    return answer;
}
