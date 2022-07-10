#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size() - k;
    int index = 0;
    for(int i = 0; i < len; i++){
        int start = index;
        char temp = number[index];
        for(int j = start; j < k + 1 + i; j++){
            if(temp < number[j]){
                index = j;
                temp = number[j];
            }
        }
        index += 1;
        answer.push_back(temp);
    }
    return answer;
}
