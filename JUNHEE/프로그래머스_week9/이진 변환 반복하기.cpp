#include <string>
#include <vector>
#include <iostream>

using namespace std;

int zero = 0;
string int_to_bin(int num){
    string temp = "";
    while(num != 0){
        if(num % 2 == 0){
            temp += '0';
        }
        else{
            temp += '1';
        }
        num /= 2;
    }
    return temp;
}
int erase_zero(string s){
    int temp = 0;
    for(auto i : s){
        if(i == '0'){
            zero++;
            continue;
        }
        temp++;
    }
    return temp;
}
vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 1;
    int start;
    while(true){
        start = erase_zero(s);
        if(start == 1){
            answer.push_back(cnt);
            answer.push_back(zero);
            break;
        }
        cnt++;
        s = int_to_bin(start);
    }
    return answer;
}
