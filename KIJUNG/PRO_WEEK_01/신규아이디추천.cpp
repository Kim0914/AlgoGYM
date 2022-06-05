#include <string>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    for(int i=0;i<answer.size();i++) {
        answer[i] = tolower(answer[i]);
        if(!(answer[i] == '.' || answer[i] == '-' || answer[i] == '_' || (answer[i] >= 'a' && answer[i] <= 'z') || (answer[i] >= '0' && answer[i] <= '9') )) answer.erase(answer.begin()+i--);
        if(i!=0 && answer[i-1] == '.' && answer[i] == '.') answer.erase(answer.begin()+i--);
    }
    
    if(answer.front() == '.') answer.erase(answer.begin());
    if(answer.back() == '.') answer.pop_back();

    if(answer.empty()) answer = "a";

    if(answer.size() >= 16) answer = answer.substr(0,15);

   if(answer.front() == '.') answer.erase(answer.begin());
    if(answer.back() == '.') answer.pop_back();

    if(answer.size() <= 2) {
        while(answer.size()!=3) answer += answer.back();
    }

    return answer;
}