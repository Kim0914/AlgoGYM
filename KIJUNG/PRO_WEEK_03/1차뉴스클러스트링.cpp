#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool validChar(char c){
    if((c>='A' && c<='Z') || (c>='a' && c<='z')) return true;
    return false;
}

int solution(string str1, string str2) {
    vector<string> v1;
    vector<string> v2;
    
    for(int i=0;i<str1.size()-1;i++){
        if(validChar(str1[i]) && validChar(str1[i+1])){
            string tmpStr = "";
            tmpStr+=tolower(str1[i]);
            tmpStr+=tolower(str1[i+1]);
            v1.push_back(tmpStr);
        }
    }

    for(int i=0;i<str2.size()-1;i++){
        if(validChar(str2[i]) && validChar(str2[i+1])){
            string tmpStr = "";
            tmpStr+=tolower(str2[i]);
            tmpStr+=tolower(str2[i+1]);
            v2.push_back(tmpStr);
        }
    }
    
    if(v1.empty() && v2.empty()) return 65536;

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    double inter = 0;
    double uni = 0;

    while(!(v1.empty() && v2.empty())){
        if(v1.empty()){
            uni+=v2.size();
            break;
        }
        if(v2.empty()){
            uni+=v1.size();
            break;
        }
        if(v1.back() == v2.back()){
            inter++;
            uni++;
            v1.pop_back();
            v2.pop_back();
        }
        else if(v1.back() > v2.back()){
            uni++;
            v1.pop_back();
        }
        else{
            uni++;
            v2.pop_back();
        }     
    }
    int answer = (inter/uni)*65536;

    return answer;
}