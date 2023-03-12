#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i = 0; i < new_id.size(); i++){
        if(new_id[i] <= 'Z' && 'A' <= new_id[i])
            new_id[i] += 32;
    }
    cout << "1단계" << new_id << endl;
    for(int i = 0; i < new_id.size(); i++){
        if((new_id[i] <= 'z' && 'a' <= new_id[i]) || 
           ('0' <= new_id[i] && new_id[i] <= '9') || 
           new_id[i] == '-' || 
           new_id[i] == '_' || 
           new_id[i] == '.')
            answer += new_id[i];
    }
    cout << "2단계" << answer << endl;
    for(int i = 1; i < answer.size();){
        if(answer[i-1] == '.' && answer[i] == '.'){
            answer.erase(answer.begin() + i);
        }
        else i++;
    }
    cout << "3단계" << answer << endl;
    if(answer[0] == '.') answer.erase(answer.begin());
    if(answer[answer.size() - 1] == '.') answer.erase(answer.begin() + answer.size() - 1);
    cout << "4단계" << answer << endl;
    if(answer.size() == 0) answer += 'a';
    cout << "5단계" << answer << endl;
    if(answer.size() >= 16) answer = answer.substr(0,15);
    if(answer[answer.size() - 1] == '.') answer.erase(answer.begin() + answer.size() - 1);
    cout << "6단계" << answer << endl;
    if(answer.size() <= 2) {
        char last = answer[answer.size() - 1];
        for(int i = 0; i <= 3 - answer.size(); i++)
            answer += last;
    }
    cout << "7단계" << answer << endl;
    return answer;
}
