#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = false;
    
    if(s.size() == 4 | s.size() == 6){
        for(char c : s){
            if(c < '0' || c > '9'){
                answer = false;
                break;
            }
            answer = true;
        }
    }
    
    return answer;
}
