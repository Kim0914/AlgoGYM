#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i=0;i<s.size();i++){
        if(s[i] <= '9' && s[i] >=0){
            answer = answer*10+(s[i]-48);
        }
        else{
            for(int j=0;j<10;j++){
                if(i+num[j].size()<=s.size() && num[j] == s.substr(i,num[j].size)) {
                    answer = answer*10+j;
                    i+=num[j].size()-1;
                    break;
                }
            }
        }
    }
    return answer;
}