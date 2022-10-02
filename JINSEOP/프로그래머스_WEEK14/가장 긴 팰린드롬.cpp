#include <iostream>
#include <string>
using namespace std;

int DP[2501][2501] = {0, };
void init_DP(string s){
    for(int i = 0; i < s.size(); i++)
            DP[i][i] = 1;
}

void find_2byte_palindrome(string s){
    for(int i = 0; i < s.size() - 1; i++)
        if(s[i] == s[i+1])
            DP[i][i+1] = 2;
}

void find_palindrome(string s){
    for(int len = 3; len <= s.size(); len++){
        for(int left = 0; left <= (s.size() - len); left++){
            int right = left + len - 1;
            
            if(s[left] == s[right] && DP[left + 1][right - 1] != 0)
                DP[left][right] = len;
        }
    }
}

int solution(string s)
{
    int answer=1;
   
    init_DP(s);
    find_2byte_palindrome(s);
    find_palindrome(s);
    
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(DP[i][j] == 0 || i == j) continue;
            answer = max(DP[i][j], answer);
        }
    }
    
    return answer;
}
