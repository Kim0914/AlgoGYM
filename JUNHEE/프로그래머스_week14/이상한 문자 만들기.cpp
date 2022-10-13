#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(cnt % 2 == 0){
            answer += toupper(s[i]);
        }
        else answer += tolower(s[i]);
        cnt++;
        if(s[i] == ' '){
            cnt = 0;
        }
    }
    return answer;
}
