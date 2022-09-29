#include <string>
#include <iostream>
using namespace std;

pair<int, int> comparer;
void compare_p_y(string s){
    int p_cnt = 0, y_cnt = 0;

    for(char c : s){
        if(c == 'p' || c == 'P')
            p_cnt++;
        if(c == 'y' || c == 'Y')
            y_cnt++;
    }
    
    comparer.first = p_cnt;
    comparer.second = y_cnt;
}

bool solution(string s)
{
    bool answer = true;
    
    compare_p_y(s);
    
    if(comparer.first == comparer.second)
        answer = true;
    else answer = false;

    return answer;
}
