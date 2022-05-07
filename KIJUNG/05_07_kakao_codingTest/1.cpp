#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int kind[8];

int mappingKind(char k){
    if(k == 'R') return 0;
    else if(k == 'T') return 1;
    else if(k == 'C') return 2;
    else if(k == 'F') return 3;
    else if(k == 'J') return 4;
    else if(k == 'M') return 5;
    else if(k == 'A') return 6;
    else if(k == 'N') return 7;
    
}

void judge(string s, int choice){
    if(choice <= 3){
        kind[mappingKind(s[0])] += 4-choice;
    }
    else if(choice > 4){
        kind[mappingKind(s[1])] += choice-4;
    }
}

string solution(vector<string> survey, vector<int> choices) {

    FOR(i,0,survey.size()){
        judge(survey[i], choices[i]);
    }

    // FOR(i,0,8){
    //     cout << kind[i] << " ";
    // }

    string answer = "";

    if(kind[0]>=kind[1]) answer +="R";
    else answer +="T";
    if(kind[2]>=kind[3]) answer +="C";
    else answer +="F";
    if(kind[4]>=kind[5]) answer +="J";
    else answer +="M";
    if(kind[6]>=kind[7]) answer +="A";
    else answer +="N";

    return answer;
}