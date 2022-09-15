#include <iostream>
#include <string>
#include <vector>
using namespace std;

void to_jaden_case(string& s) {
    bool not_first = true;

    if ('a' <= s[0] <= 'z')
        s[0] = toupper(s[0]);

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ' ') {
            not_first = false;
            continue;
        }

        if (!not_first) {
            not_first = true;
            if ('a' <= s[i] && s[i] <= 'z')
                s[i] = toupper(s[i]);
        }
            
        else if('A' <= s[i] && s[i] <= 'Z')
                s[i] = tolower(s[i]);
    }
}

string solution(string s) {
    string answer = "";
    
    to_jaden_case(s);
    answer = s;

    return answer;
}
