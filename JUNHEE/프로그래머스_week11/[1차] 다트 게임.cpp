#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score;
    char bonus, option;
    int pre_score = 0;
    for(int i = 0; i < dartResult.size(); i += 2){
        bool flag = false;
        if(dartResult[i+1] == '0'){
            score = 10;
            i++;
        }else{
            score = dartResult[i] - '0';
        }
        bonus = dartResult[i+1];
        if(dartResult[i+2] == '*' || dartResult[i+2] == '#'){
            option = dartResult[i+2];
            i++;
            flag = true;
        }
        switch (bonus){
            case 'D':
                score *= score;
                break;
            case 'T':
                score = score * score * score;
                break;
        }
        if(flag){
            switch (option){
                case '*':
                    pre_score *= 2;
                    score *= 2;
                    break;
                case '#':
                    score *= -1;
                    break;
            }
        }
        answer += pre_score;
        pre_score = score;
    }
    answer += pre_score;
    return answer;
}
