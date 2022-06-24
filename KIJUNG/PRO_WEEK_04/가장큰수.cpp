#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
    return stoi(a+b)>stoi(b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNums;
    for(int number: numbers){
        strNums.push_back(to_string(number));
    }
    
    sort(strNums.begin(), strNums.end(),comp);
    
    for(string str: strNums) {
        answer+=str;
    }
    
    return (answer[0]=='0')?"0":answer;
}