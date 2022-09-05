#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> mbti;
    mbti['R'] = 0; mbti['T'] = 0; 
    mbti['C'] = 0; mbti['F'] = 0; 
    mbti['J'] = 0; mbti['M'] = 0; 
    mbti['A'] = 0; mbti['N'] = 0;
    for(int i = 0; i < survey.size(); i++){
        char first = survey[i][0];
        char second = survey[i][1];
        if(choices[i] == 1) mbti[first] += 3;
        else if(choices[i] == 2) mbti[first] += 2;
        else if(choices[i] == 3) mbti[first] += 1;
        else if(choices[i] == 5) mbti[second] += 1;
        else if(choices[i] == 6) mbti[second] += 2;
        else if(choices[i] == 7) mbti[second] += 3;
        
    }
    if(mbti['R'] < mbti['T']) answer += 'T';
    else answer += 'R';
    if(mbti['C'] < mbti['F']) answer += 'F';
    else answer += 'C';
    if(mbti['J'] < mbti['M']) answer += 'M';
    else answer += 'J';
    if(mbti['A'] < mbti['N']) answer += 'N';
    else answer += 'A';
    return answer;
}
