#include <string>

using namespace std;

bool solution(string s)
{
    int cnt = 0;
    for(char c: s){
        if(c == ')'){
            if(cnt <= 0) return false;
            else cnt--;
        }
        else cnt++;
    }

    if(cnt == 0) return true;
    return false;
}