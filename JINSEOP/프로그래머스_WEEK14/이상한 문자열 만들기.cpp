#include <string>
#include <vector>
using namespace std;

void convert_string(string& s){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            cnt = 0; continue;
        }
        
        if(cnt % 2 == 0){
            s[i] = toupper(s[i]);
            cnt++;
        }
        else{
            s[i] = tolower(s[i]);
            cnt++;
        }
    }
}

string solution(string s) {
    string answer = "";
    
    convert_string(s);
    answer = s;
    return answer;
}
