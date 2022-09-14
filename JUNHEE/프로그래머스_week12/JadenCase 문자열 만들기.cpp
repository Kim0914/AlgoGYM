#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    for(int i = 0; i < s.size(); i++){
        char temp = s[i];
        if(s[i] == ' ') flag = true;
        if(flag && (s[i] >= 'a' && s[i] <= 'z')){
            temp -= 32;
            flag = false;
        }
        else if(flag && s[i] != ' '){
            flag = false;   
        }
        else if(!flag && (s[i] >= 'A' && s[i] <= 'Z')){
            temp += 32;
        }
        answer += temp;
        cout << temp;
    }
    return answer;
}
